//为了表示每个数据元素ai与其直接后继数据元素ai+1之间的逻辑关系，对数据
//元素ai来说，除了存储其本身的信息之外，还需存储一个指示其后继的信息
//（数据域）（指针域）这两部分信息组成数据元素ai的存储映像，成为
//结点
//头节点可以存储任意信息，比如线性表长度等附加信息
//LinkList==Node *
#include  <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef int ElemType;
typedef struct Node
{
	ElemType data;
	struct Node *next;
}Node;
typedef struct Node *LinkList;

typedef int Status;
#define ERROR 0
#define OK 1

Status GetElem(LinkList L,int i,ElemType *e)
{
	int j;
	LinkList p;
	p=L->next;
	j=1;
	while(p&&j<i)
	{
		p=p->next;
		j++;
	}
	if (!p||j>i)
	{
		printf("ERROR!!\n");
		return ERROR;
	}
	*e=p->data;
	printf("第%d个Node的值为%d\n",i,*e );
	return OK;
}



void CreateListHead(LinkList *L,int n)
{
	LinkList p;
	int i;
	srand(time(0));
	*L=(LinkList)malloc(sizeof(Node));
	(*L)->next=NULL;
	for (i = 0; i < n; ++i)
	{
		p=(LinkList)malloc(sizeof(Node));
		p->data=rand()%100+1;
		printf("头插法随机生成的数：%d\n",p->data );
		p->next=(*L)->next;
		(*L)->next=p;
	}
}

void CreateListTail(LinkList *L,int n)
{
	LinkList p,r;
	int i;
	srand(time(0));
	*L=(LinkList)malloc(sizeof(Node));
	r=*L;
	for (i = 0; i < n; ++i)
	{
		p=(LinkList)malloc(sizeof(Node));
		p->data=rand()%100+1;
		printf("尾插法随机生成的数：%d\n",p->data );
		r->next=p;
		r=p;
	}
	r->next=NULL;
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



Status ListInsert(LinkList *L,int i,ElemType e)
{
	int j;
	LinkList p,s;
	p=*L;
	j=1;
	while(p&&j<i)
	{
		p=p->next;
		++j;
	}
	if (!p||j>i)
	{
		return ERROR;
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
	int j;
	LinkList p,q;
	p=*L;
	j=1;
	while(p->next && j<i)
	{
		p=p->next;
		++j;
	}
	if (!(p->next)||j>i)
	{
		return ERROR;
	}
	q=p->next;
	p->next=q->next;
	*e=q->data;
	printf("把第%d的数删除\n",i );
	printf("删除掉的元素是%d\n",*e );
	free(q);
	return OK;
}



int main(int argc, char const *argv[])
{

	LinkList l1;
	CreateListHead(&l1,3);
	ListInsert(&l1,2,520);
	
	
	ElemType num;
	GetElem(l1, 2, &num);
	Print_all_data(l1);

	LinkList l2;
	ElemType item;
	CreateListTail(&l2,4);
	ListInsert(&l2,2,520);
	Print_all_data(l2);
	ListDelect(&l2,2,&item);
	
	Print_all_data(l2);

	return 0 ;



}
	

