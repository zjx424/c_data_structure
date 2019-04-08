#include <stdio.h>

#define MAXSIZE 20
#define ERROR 0
#define OK 1

typedef int Status;
typedef int SElemType;

typedef struct 
{
	SElemType data[MAXSIZE];
	int top;//top变量来指示栈顶元素在数组中的位置
}SqStack;

Status Push(SqStack *S,SElemType e)
{
	if (S->top==MAXSIZE-1)//栈满
	{
		return ERROR;
	}
	S->top++;//栈顶指针加1
	S->data[S->top]=e;//将新插入的元素赋值给栈顶空间
	return OK;
}

Status Pop(SqStack *S,SElemType *e)
{
	if (S->top==-1)//空栈
	{
		return ERROR;
	}
	*e=S->data[S->top];//出栈需要先把元素赋值
	S->top--;//然后再让栈顶指针减1
	return OK;
}


int main()
{
	return 0;
}


