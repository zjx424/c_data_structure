#include <stdio.h>
#include <stdlib.h>

#define CardNumber 13

typedef struct node
{
	int data;
	struct node *next;
}sqlist,*linklist;

linklist CreateLinkList()//创建了一个data全为0的循环链表
{
	linklist head=NULL;
	linklist s,r;
	int i;
	r=head;//r为头结点
	for (i = 0; i < CardNumber; ++i)
	{
		s=(linklist)malloc(sizeof(sqlist));//s为新节点
		s->data=0;
		if (head==NULL)
		{
			head=s;
		}
		else
		{
			r->next=s;
		}
		r=s;
	}
	r->next=head;//单循环链表
	return head;
}
//算法大概:首先创建一个data全部为0的循环链表
//初始化:把第一个赋值给1,然后规定2为初始步长


void Magician(linklist head)
{
	linklist p;
	int j;
	head=p;
	p->data=1;
	int CountNumber=2;
	while(1)
	{
		for (j = 0; j < CountNumber ; ++j)
		{
			p=p->next;
			if (p->data!=0)
			{
				p->next;//跳过有值的位置?存疑
				j--;//j需要返回原来的值
			}
		}
		if (p->data==0)
		{
			p->data=CountNumber;
			CountNumber++;
			if (CountNumber==14)
			{
				break;
			}
		}
	}
}




void DestroyStack(linklist *list)
{
	linklist ptr = *list;
	linklist buff[CardNumber];
	int i=0;
	while(i<CardNumber)
	{
		buff[i++]=ptr;
		ptr=ptr->next;
	}
	for (; i < CardNumber; ++i)
	{
		free(buff[i]);
	}
	*list=0;
}

int main()

{
	linklist head = CreateLinkList();
	Magician(head);
	int i=0;
	for (; i < CardNumber ; ++i)
	{
		printf("黑桃%d\t",head->data );
		head=head->next;
	}
	// DestroyStack(&head);	
}
