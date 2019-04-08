#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ERROR 0
#define OK 1
typedef int Status;
typedef int ElemType;

struct Node
{
	ElemType data;
	struct Node *next;
}Node;

typedef struct Node *LinkList;


void CreateListTail(LinkList *L,int n)
{
	srand(time(0));
	LinkList new_node,last_node;
	*L=(LinkList)malloc(sizeof(Node));//创建需要
	last_node=*L;
	for (int i = 0; i < n; ++i)
	{
		new_node=(LinkList)malloc(sizeof(Node));
		new_node->data=rand()%100+1;
		printf("随机产生的数依次是：%d\n", new_node->data);
		last_node->next=new_node;
		last_node=new_node;
	}
	last_node->next=NULL;
}
Status ClearList(LinkList *L)
{
	LinkList p,q;
	p=(*L)->next;
	while(p)
	{
		// q=p->next;
		// free(p);
		// p=q;
		free(p);
		p=p->next;
	}
	(*L)->next=NULL;
	printf("清空单链表，释放内存\n");
	return OK;
}


Status ListInsert(LinkList *L,int i,ElemType e)
{
	int j=1;
	LinkList p,s;
	p=*L;
	if (!p || i<j)
	{
		return ERROR;
	}
	while(p&&j<i)
	{
		p=p->next;
		j++;
	}
	s=(LinkList)malloc(sizeof(Node));
	s->data=e;
	s->next=p->next;
	p->next=s;
	printf("在第%d个位置插入%d\n",i,e );
	return OK;
}
Status ListDelect(LinkList *L,int i,ElemType *e)
{
	int j=1;
	LinkList p,q;
	p=*L;
	if ((!p->next||i<j))
	{
		return ERROR;
	}
	while(p->next&&i>j)
	{
		p=p->next;
		j++;
	}
	q=p->next;
	p->next=q->next;
	*e=q->data;
	printf("删除掉第%d个Node，其值为：%d\n",i,q->data );
	free(q);
	return OK;
}


Status GetElem(LinkList L,int i,ElemType *e)
{
	int j=1;
	LinkList p;
	p=L->next;
	if (!p || i<j)
	{
		return ERROR;
	}
	while(p&&j<i)
	{
		p=p->next;
		j++;
	}
	*e=p->data;
	printf("取出第%d个Node，其值为：%d\n",i,*e );
	return OK;
}

void Print_Node_data(LinkList L)
{
	printf("开始打印所有data。。。\n");
	while (L->next!=NULL)
	{
		L=L->next;
		printf("%d\t",L->data );
	}
	printf("\n");
}





int main(int argc, char const *argv[])
{
	LinkList l1;
	CreateListTail(&l1,5);
	Print_Node_data(l1);

	ListInsert(&l1,3,87);
	Print_Node_data(l1);

	ElemType d;
	ListDelect(&l1,4,&d);
	Print_Node_data(l1);

	ElemType e;
	GetElem(l1,4,&e);

	ClearList(&l1);
	Print_Node_data(l1);

	return 0;
}




