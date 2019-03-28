#include <stdio.h>

typedef int ElemType

typedef struct DualNode
{
	ElemType data;
	struct DualNode *prior;//前驱结点
	struct DualNode *next;//后继结点
}DualNode, *DuLinkList;

void Insert()
{
	s->prior=p;
	s->next=p->next;
	p->next->prior=s;
	p->next=s;
}
//顺序是:
//先搞定

void Delect()
{
	p->prior->next=p->next;
	p->next->prior=p->prior;
}

