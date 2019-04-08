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
	LinkList new_node,last_node;
	srand(time(0));
	*L=(LinkList)malloc(sizeof(Node));//头结点
	last_node=*L;
	for (int i = 0; i < n; ++i)
	{
		new_node=(LinkList)malloc(sizeof(Node));
		new_node->data=rand()%100+1;
		printf("尾插法随机生成的数：%d\n",new_node->data );
		last_node->next=new_node;
		last_node=new_node;
	}
	last_node->next=NULL;
}

void CreateListHead(LinkList *L,int n)
{
	srand(time(0));
	LinkList new_node;
	*L=(LinkList)malloc(sizeof(Node));
	(*L)->next=NULL;//需要创建一个空链表
	for (int i = 0; i < n; ++i)
	{
		new_node=(LinkList)malloc(sizeof(Node));
		new_node->data=rand()%100+1;
		printf("头插法随机生成的数：%d\n",new_node->data );
		new_node->next=(*L)->next;
		(*L)->next=new_node;

	}
}


Status GetElem(LinkList L,int i,ElemType *e)
{
	int j=1;
	LinkList p;
	p=L->next;
	while(j<i&&p)
	{
		p=p->next;
		j++;
	}
	if (!p||j>i)
	{
		return ERROR;
	}
	*e=p->data;
	printf("取出的第%d个数是:%d\n",i,*e );
	return OK;
}

void Print_all_data(LinkList L)
{
	printf("打印所有节点的数据域的值：\n");
	while (L->next!=NULL)
	{
		L=L->next;
		printf("%d \t",L->data);
	}
	printf("\n");
}

int main(int argc, char const *argv[])
{
	LinkList l1;
	CreateListHead(&l1,4);
	Print_all_data(l1);
	ElemType e;
	GetElem(l1,3,&e);
	return 0;
}






