/*
有环的定义：链表的尾结点指向链表中的某个结点

方法1:实用p,q两个指针，p总是向前走，但q每次都从头开始走，
对于每个结点，看p走的步数是否和q一样
一样则无环，不一样则有环


方法二：使用快慢指针，使用p，q两个指针，p每次向前走一步，q每次向前走两步
若在某个时候p==q，则存在环
这个方法better


*/
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
//好多人都不清楚楼主问的重点。首先相遇不是操场跑圈，快的能追上慢的，这还用问吗，肯定能追上。
//而楼主问的是一个人是跳1个格子，另一个跳2个格子，会不会每次要相遇的时候，快的都会跳过慢的那个，从而不会相遇在一个格子。
//（重点是为什么一定会相遇在一个格子）通俗点可以理解为他们的相对速度只差一个格子，快的只能一个一个格子的去追慢的，必然在一个格子相遇！
//如果没看懂，看下面的详细。一次跳2个与一次跳一个格子的追上之后，是一定会在一个格子遇到的。
//因为在即将追上的时候，快的那个落后慢的1个或者2个格子，
//无论哪种，落后1个的话，下一步正好追上，落后2个格子的话，下一步就落后1个格子了，也可以说即将追上的时候一定是相差1个格子，下一步一定在一个格子相遇。


int HasLoop2(LinkList L)
{

	LinkList p=L;//p是一步走
	LinkList q=L;//q是2步走
	while(p!=NULL&&q!=NULL&&q->next!=NULL)
	{
		p=p->next;
		if (q->next!=NULL)
		{
			q=q->next->next;
		}
		printf("p:%d, q:%d\n",p->data,q->data );
		if (p==q)
		{
			printf("存在环\n");
			return 1;
		}
	}
	printf("不存在环\n");
	return 0;
}

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
	last_node->next=(*L)->next->next->next;
}




int main(int argc, char const *argv[])
{
	LinkList l1;
	CreateListTail(&l1,7);
	HasLoop2(l1);
	return 0;
}







