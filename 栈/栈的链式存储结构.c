#include <stdio.h>
#include <stdlib.h>

//通常我们用的都是栈的顺序存储结构存储,链式存储
//我们作为一个知识点
typedef int ElemType;
#define ERROR 0
#define OK 1
typedef int Status;

typedef struct StackNode
{
	ElemType data;
	struct StackNode *next;
}StackNode,*LinkStackPtr;

typedef struct LinkStack
{
	LinkStackPtr top;
	int count;
}LinkStack;
Status Push(LinkStack *s,ElemType e)
{
	LinkStackPtr p=(LinkStackPtr)malloc(sizeof(StackNode));
	p->data=e;
	p->next=s->top;
	s->top=p;
	s->count++;
	return OK; 
}

Status Pop(LinkStack *s,ElemType *e)
{
	LinkStackPtr p;
	*e=s->top->data;
	p=s->top;
	s->top=s->top->next;
	free(p);
	s->count--;
	return OK;
}
