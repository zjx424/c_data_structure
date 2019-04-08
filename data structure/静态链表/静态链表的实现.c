#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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
void Free_SSL(staticLinkList space, int j) 
{  
    space[j].cur = space[0].cur;    
    space[0].cur = j;               
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

Status ListDelete(staticLinkList L, int i)   
{ 
    int j, k;   
    if (i < 1 || i > ListLength(L))   
        return ERROR;   
    k = MAXSIZE - 1;   
    for (j = 1; j <= i - 1; j++)   
        k = L[k].cur;  

    j = L[k].cur;   
    L[k].cur = L[j].cur;   
    Free_SSL(L, j);   
    return OK;   
} 


void Print_data(staticLinkList L)
{
	printf("开始打印。。。\n");
	for (int i = 1; i <=ListLength(L); ++i)
	{
		printf("L[%d].data == %d\n",i,L[i].data);
		printf("L[%d].cur == %d\n",i,L[i].cur);
		printf("\n");

	}
}



void Print_Sorted_data(staticLinkList L)
{
	printf("开始打印data。。。\n");
	int first_cur=L[MAXSIZE-1].cur;
	for (int i = 1; i < ListLength(L); ++i)
	{
		int data=L[first_cur].data;
		first_cur=L[first_cur].cur;
		printf("%d\t",data );
	}

}


int main(int argc, char const *argv[])
{
	staticLinkList l1;

	srand(time(0));

	InitList(l1);

	ElemType e0;
	for (int i = 1; i <=13; ++i)
	{
		e0=rand()%100+1;
		printf("随机生成的数是：%d\n",e0 );
		ListInsert(l1,i,e0);
	}
	printf("长度为%d\n",ListLength(l1) );
	Print_Sorted_data(l1);


	ListDelete(l1,1);
	ListDelete(l1,5);
	
	Print_Sorted_data(l1);
	return 0;
}

