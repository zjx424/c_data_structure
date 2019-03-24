#include <stdio.h>
#define MAXSIZE 1000
#define ERROR 0
#define OK 1
typedef int ElemType;
typedef int Status;
typedef struct 
{
	ElemType data;
	int cur;
}Component,staticLinkList[MAXSIZE];

/*
最后一个有值元素游标cur存放0
第一个游标cur存放第一个空闲的下标
最后一个(999)存放第一个有值的下标
*/

Status InitList(staticLinkList space)
{
	int i;
	for (i = 0; i < MAXSIZE-1; ++i)
	{
		space[i].cur=i+1;
	}
	space[MAXSIZE-1].cur=0;
	return OK;
}
int Malloc_SLL(staticLinkList space)
{
	int i=space[0].cur;
	if (space[0].cur)
	{
		space[0].cur=space[i].cur;
	}
	return i;
}
int ListLength(staticLinkList L)
{
	int j=0;
	int i=L[MAXSIZE-1].cur;
	while(i)
	{
		i=L[i].cur;
		j++;
	}
	return j;
}
Status ListInsert(staticLinkList L,int i,ElemType e)
{
	int j,k,l;
	k=MAXSIZE-1;
	if (i<1||i>ListLength(L)+1)
	{
		return ERROR;
	}
	j=Malloc_SLL(L);
	if (j)
	{
		L[j].data=e;
		for(l=1;l<=i-1;l++)
		{
			k=L[k].cur;
		}
		L[j].cur=L[k].cur;
		L[k].cur=j;
		return OK;
	}
	return ERROR;
}





int main(int argc, char const *argv[])
{
	staticLinkList l1;

	InitList(l1);
	ElemType e0=100;
	ListInsert(l1,1,e0);
	

	printf("%d\n", l1[1].data);
	return 0;
}

