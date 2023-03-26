#define _CRT_SECURE_NO_WARNINGS

#include "..\Head\operate.h"


//��ʼ��ջ
int initLStack(LinkStack* s) {
	s->top = NULL;
	s->count = 0;
	return 1;
}

//�ж�ջ�Ƿ�Ϊ��
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

//��ջ
int pushLStack(LinkStack* s, char data) {
	StackNode* p = (StackNode*)malloc(sizeof(StackNode));
	if (p == NULL)
		return 0;
	p->data = data;//ͷ�巨
	p->next = s->top;
	s->top = p;
	s->count++;
	return 1;
}

//��ջ
int popLStack(LinkStack* s, char* data) {
	if (s == NULL)
		return 0;
	StackNode* p = s->top;
	if (p == NULL)
	{
		printf("ջ����Ԫ��\n");
		return 0;
	}
	else
	{
		s->top = p->next;//����Ųһλ
		*data = p->data;
		free(p);
		s->count--;
		return 1;
	}
}

//�õ�ջ��Ԫ��
int getTopLStack(LinkStack* s, char* e) 
{
    if (s == NULL)
        return 0;
    StackNode* p = s->top;
    if (p == NULL)
    {
        printf("ջ����Ԫ��\n");
        return 0;
    }
    else
    {
        *e = p->data;
        return 1;
    }
}



//���ظ��ַ������ȼ�
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

//�������ַ���������
void char_put(char ch, char buffer[])
{
    static int index = 0;
    buffer[index++] = ch;
}

//�жϱ��������ַ��ǲ�������
int is_number(char ch)
{
	return(ch >= '0' && ch <= '9');//���ַ���1�����򷵻�0
}

//�жϱ��������ַ��ǲ��������
int is_operator(char ch)
{
	return(ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

//�ж��ַ��ǲ���������
int is_left(char ch)
{
	return(ch == '(');
}

//�ж��ַ��ǲ���������
int is_right(char ch)
{
	return(ch == ')');
}

int transform(char str[], char buffer[])
{
    LinkStack* s = (LinkStack*)malloc(sizeof(LinkStack));
    initLStack(s);//����һ��ջ
    int i = 0;
    char data;
    while (str[i] != '\0')
    {
        //�ж��ǲ�������
        if (is_number(str[i]) == 1)
        {
            if (is_number(str[i + 1]) == 1)//������Ҳ������(��λ������)
            {
                char_put(str[i], buffer);//����ֱ�ӷ�������
            }
            else//���治������
            {
                char_put(str[i], buffer);
                char_put(' ', buffer);
            }
        }
        //�ж��ǲ��������
        else if (is_operator((str[i])) == 1)
        {
            if (isEmptyLStack(s) == 0)//ջ��Ϊ��
            {
                getTopLStack(s, &data);//�鿴ջ��Ԫ��
                while ((isEmptyLStack(s) == 0) && (priority(str[i]) <= (priority(data))))//����������ȼ�������ջ��
                {
                    char content;
                    popLStack(s, &content);
                    char_put(content, buffer);//���������ľͳ�ջ
                    char_put(' ', buffer);
                }
            }
            pushLStack(s, str[i]);//�ٽ����������ջ
        }
        else if (is_left(str[i]))//��������ֱ����ջ
        {
            pushLStack(s, str[i]);
        }
        else if (is_right(str[i]))//�ж��ǲ���������
        {
            getTopLStack(s, &data);//�鿴ջ��Ԫ��
            while (is_left(data) != 1)//ջ�����������ŵ����
            {
                char content;
                popLStack(s, &content);
                char_put(content, buffer);
                if (isEmptyLStack(s) == 1)//ջΪ����δ�ҵ�������
                {
                    printf("û��ƥ�䵽������\n");
                    return -1;
                }
                getTopLStack(s, &data);//�鿴ջ��Ԫ��
            }
            //ִ�е���ʱ�����ƥ�䵽��������
            char content;
            popLStack(s, &content);
        }
        else
        {
            printf("�в���ʶ����ַ�\n");
            return -1;
        }
        i++;
    }
    //��������
    if (str[i] == '\0')//�ɹ��������ַ���ĩβ
    {
        while (isEmptyLStack(s) == 0)//����ȫ��ջ��Ԫ��
        {
            getTopLStack(s, &data);//�鿴ջ��Ԫ��
            if (is_left(data))//ջ��Ԫ��Ϊ������,��ȱ�� ')'
            {
                printf("��û��ƥ�䵽��'(',ȱ��')'\n");
                return -1;
            }
            popLStack(s, &data);
            char_put(data, buffer);//��ջ��Ԫ�ط������մ�
        }
    }
    else
    {
        printf("����û����ɣ�\n");
    }
    return 1;
}