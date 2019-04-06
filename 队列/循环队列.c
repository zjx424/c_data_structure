#include <stdio.h>


#define MAXSIZE 100
#define OK 1
#define ERROR 0
typedef int ElemType;
typedef int Status;

//循环队列的队列满的条件
//(rear+1)%MAXSIZE==front
//队列长度的计算公式
//(rear-front-MAXSIZE)%MAXSIZE

typedef struct
{
	ElemType data[MAXSIZE];
	int front;
	int rear;
}SqQueue;

//初始化队列
Status InitQueue(SqQueue *Q)
{
	Q->front=0;
	Q->rear=0;
	return OK;
}

//求队列长度
int QueueLength(SqQueue Q)
{
	return (Q.rear-Q.front+MAXSIZE)%MAXSIZE;
}

//入队操作 
Status EnQueue(SqQueue *Q,ElemType e)
{
	if ((Q->rear+1)%MAXSIZE==Q->front)
	{
		return ERROR;
	}
	Q->data[Q->rear]=e;
	Q->rear=(Q->rear+1)%MAXSIZE;
	//rear指针向后移一位置
	//若到最后则回到头;
	return OK;
}

Status DeQueue(SqQueue *Q,ElemType *e)
{
	if (Q->front==Q->rear)
	{
		return ERROR;
	}
	*e=Q->data[Q->front];
	Q->front=(Q->front+1)%MAXSIZE;
	//front指针向后移一位置
	//若到最后则回到头;
	return OK;
}
int main()
{
	return 0;
}


