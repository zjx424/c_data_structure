//队列(queue)是只允许在一端进行插入操作,而在另一端进行删除操作的线性表
//与栈相反:栈是后进先出,队列是先进先出,First In First Out
//对头出,队尾进,对头删除,队尾增加
//栈一般用顺序表来实现,而队列我们常用列表,简称链队列 



#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;


typedef struct QNode
{
	ElemType data;
	struct QNode *next;
}QNode,*QueuePrt;

typedef struct{
	QueuePrt front,rear;
}LinkQueue;


//创建一个队列
initQueue(LinkQueue *q)
{
	q->front=q->rear=(QueuePrt)malloc(sizeof(QNode));
	if (!q->front)
	{
		exit(0);
	}
	q->front->next=NULL;
}

//入队列操作
InsertQueue(LinkQueue *q,ElemType e)
{
	QueuePrt p;
	p=(QueuePrt)malloc(sizeof(QNode));
	if (p==NULL)
	{
		exit(0);
	}
	p->data=e;
	p->next=NULL;
	q->rear->next=p;//在rear尾部进行插入
	q->rear=p; 
}
//出队列操作
//出队列只是从front->next开始删除
DeleteQueue(LinkQueue *q,ElemType *e)
{
	QueuePrt p;
	if (q->front==q->rear)
	{
		return;
	}
	p=q->front->next;//p是要删除的元素
	*e=p->data;
	q->front->next=p->next;
	if (q->rear==p)//只有一个元素
	{
		q->rear=q->front;
	}
	free(p);
}

//销毁一个队列
DestoryQueue(LinkQueue *q)
{
	while(q->front)
	{
		q->rear=q->front->next;
		free(q->front);
		q->front=q->rear; 
	}
}

int main()
{
	return 0; 
}