#include <stdio.h>
#include <stdlib.h>

//拉丁方阵类似与数独,但是并没有数独复杂,只是每行每列的数字是唯一即可
#define LatinNumber 9
typedef struct node
{
	int data;
	struct node *next;
}sqlist,*linklist;


linklist CreateLinkList()
{
	linklist head=NULL;
	linklist s,r;
	int i;
	int item=1;
	r=head;//r为头结点
	for (i = 0; i < LatinNumber; ++i)
	{
		s=(linklist)malloc(sizeof(sqlist));//s为新节点
		s->data=item;
		if (head==NULL)
		{
			head=s;
		}
		else
		{
			r->next=s;
		}
		r=s;
		item++;
	}
	r->next=head;//单循环链表
	return head;
}

int main()
{
	linklist head = CreateLinkList();
	int i=0;
	int count=9;
	while(count!=0)
	{
		for (; i < LatinNumber ; ++i)
		{
			printf("%d\t",head->data);
			head=head->next;
		}
		printf("\n");
		i=0;
		head=head->next;
		count--;
	}
	return 0;
}