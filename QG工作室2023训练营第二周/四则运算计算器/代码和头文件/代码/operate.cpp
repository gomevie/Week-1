#define _CRT_SECURE_NO_WARNINGS

#include "..\Head\operate.h"


//初始化栈
int initLStack(LinkStack* s) {
	s->top = NULL;
	s->count = 0;
	return 1;
}

//判断栈是否为空
int isEmptyLStack(LinkStack* s) {
	if (s == NULL)
		return 0;
	StackNode* p = s->top;
	if (p == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//入栈
int pushLStack(LinkStack* s, char data) {
	StackNode* p = (StackNode*)malloc(sizeof(StackNode));
	if (p == NULL)
		return 0;
	p->data = data;//头插法
	p->next = s->top;
	s->top = p;
	s->count++;
	return 1;
}

//出栈
int popLStack(LinkStack* s, char* data) {
	if (s == NULL)
		return 0;
	StackNode* p = s->top;
	if (p == NULL)
	{
		printf("栈内无元素\n");
		return 0;
	}
	else
	{
		s->top = p->next;//往后挪一位
		*data = p->data;
		free(p);
		s->count--;
		return 1;
	}
}

//得到栈顶元素
int getTopLStack(LinkStack* s, char* e) 
{
    if (s == NULL)
        return 0;
    StackNode* p = s->top;
    if (p == NULL)
    {
        printf("栈内无元素\n");
        return 0;
    }
    else
    {
        *e = p->data;
        return 1;
    }
}



//返回该字符的优先级
int priority(char ch)
{
	int ret = 0;
	switch (ch)
	{
	case '+':
	case '-':
		ret = 1;
		break;
	case '*':
	case '/':
		ret = 2;
		break;
	default:
		break;
	}
	return ret;
}

//用来将字符放入结果串
void char_put(char ch, char buffer[])
{
    static int index = 0;
    buffer[index++] = ch;
}

//判断遍历到的字符是不是数字
int is_number(char ch)
{
	return(ch >= '0' && ch <= '9');//数字返回1，否则返回0
}

//判断遍历到的字符是不是运算符
int is_operator(char ch)
{
	return(ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

//判断字符是不是左括号
int is_left(char ch)
{
	return(ch == '(');
}

//判断字符是不是右括号
int is_right(char ch)
{
	return(ch == ')');
}

int transform(char str[], char buffer[])
{
    LinkStack* s = (LinkStack*)malloc(sizeof(LinkStack));
    initLStack(s);//创建一个栈
    int i = 0;
    char data;
    while (str[i] != '\0')
    {
        //判断是不是数字
        if (is_number(str[i]) == 1)
        {
            if (is_number(str[i + 1]) == 1)//若后面也是数字(多位数问题)
            {
                char_put(str[i], buffer);//数字直接放入结果串
            }
            else//后面不是数字
            {
                char_put(str[i], buffer);
                char_put(' ', buffer);
            }
        }
        //判断是不是运算符
        else if (is_operator((str[i])) == 1)
        {
            if (isEmptyLStack(s) == 0)//栈不为空
            {
                getTopLStack(s, &data);//查看栈顶元素
                while ((isEmptyLStack(s) == 0) && (priority(str[i]) <= (priority(data))))//新运算符优先级不高于栈顶
                {
                    char content;
                    popLStack(s, &content);
                    char_put(content, buffer);//满足条件的就出栈
                    char_put(' ', buffer);
                }
            }
            pushLStack(s, str[i]);//再将该运算符入栈
        }
        else if (is_left(str[i]))//左括号则直接入栈
        {
            pushLStack(s, str[i]);
        }
        else if (is_right(str[i]))//判断是不是右括号
        {
            getTopLStack(s, &data);//查看栈顶元素
            while (is_left(data) != 1)//栈顶不是左括号的情况
            {
                char content;
                popLStack(s, &content);
                char_put(content, buffer);
                if (isEmptyLStack(s) == 1)//栈为空仍未找到左括号
                {
                    printf("没有匹配到左括号\n");
                    return -1;
                }
                getTopLStack(s, &data);//查看栈顶元素
            }
            //执行到此时则代表匹配到了左括号
            char content;
            popLStack(s, &content);
        }
        else
        {
            printf("有不能识别的字符\n");
            return -1;
        }
        i++;
    }
    //遍历结束
    if (str[i] == '\0')//成功遍历到字符串末尾
    {
        while (isEmptyLStack(s) == 0)//弹出全部栈中元素
        {
            getTopLStack(s, &data);//查看栈顶元素
            if (is_left(data))//栈顶元素为左括号,即缺少 ')'
            {
                printf("有没有匹配到的'(',缺少')'\n");
                return -1;
            }
            popLStack(s, &data);
            char_put(data, buffer);//将栈中元素放入最终串
        }
    }
    else
    {
        printf("遍历没有完成！\n");
    }
    return 1;
}