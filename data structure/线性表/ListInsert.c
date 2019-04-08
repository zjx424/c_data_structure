#include <stdio.h>
#define MAXSIZE 20
typedef int ElemType;

typedef struct 
{
	ElemType data[MAXSIZE];
	int length;
}SqList;
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;

Status ListInsert(SqList *L,int i,ElemType e)
{
	int k;
	if (L->length==MAXSIZE)
	{
		return ERROR;
	}
	if (i<1||i>L->length+1)
	{
		return ERROR;
	}
	if (i<=L->length)
	{
		for (k=L->length-1;k>=i-1 ;k--)
		{
			L->data[k+1]=L->data[k];
		}
	}
	L->data[i-1]=e;
	L->length++;
	return OK;
}


int main(int argc, char const *argv[])
{
	SqList l1={{8,6,2,3,7},5};
	ListInsert(&l1,3,19);
	for (int i = 0; i < 6; ++i)
	{
		printf("%d\t",l1.data[i]);
	}
	return 0;
}