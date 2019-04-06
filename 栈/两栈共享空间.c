#include <stdio.h>

//他们在数组的两端,向中间靠拢,栈1在左,栈2在右
//栈1的起始位置为0,栈2的起始位置为n-1
//所以栈1为空则top1=-1,栈2为空则top2=n
//栈满情况有3:
//情况1:栈1空,栈2满,全栈满:top1==-1,top2==0;
//情况2:栈1满,栈2空,全栈满:top1==n-1,top2==n;
//情况3:以上两种情况都满足,top1+1==top2,为栈满

#define MAXSIZE 20
#define ERROR 0
#define OK 1

typedef int Status;
typedef int SElemType;


//定义
typedef struct
{
	ElemType data[MAXSIZE];
	int top1;//栈1栈顶指针
	int top2;//栈2栈顶指针
}SqDoubleStack;


//Push
//判断栈1还是栈2的栈号参数stackNumber
Status Push(SqDoubleStack *S,SElemType e, int stackNumber)
{
	if (S->top1+1==S->top2)
	{
		return ERROR;
	}
	if (stackNumber==1)
	{
		S->data[++S->top1]=e;
		//这里相当于
		//S->top1++;
		//S->data[S->top1]=e;
	}
	else if (stackNumber == 2)
	{
		S ->data[--S->top2]=e;
		//这里相当于
		//S->top2++;
		//S->data[S->top2]=e;
	}
	return OK;
}

//Pop
Status Pop(SqDoubleStack *S,SElemType e,int stackNumber)
{
	if (stackNumber==-1)
	{
		if (S->top1==-1)
		{
			return ERROR;
		}
		*e=S->data[--S->top1];
	}
	else if (stackNumber == 2)
	{
		if (S->top2==MAXSIZE)
		{
			return ERROR;
		}
		*e=S->data[--S->top2];
	}
	return OK;
}




