#include <stdio.h>

typedef int Status;
typedef int Elemtype;
#define ERROR 0
#define OK 0
#define MAXSIZE 20

typedef struct 
{
	Elemtype data[MAXSIZE];
	int length;
}Sqlist;

Status GetElem(Sqlist L,int i,Elemtype *e)
{
	if (i<1||i>L.length||L.length==0)
	{
		return ERROR;
	}
	*e=L.data[i-1];
	return OK;
}


void print_l(Sqlist L)
{
	for (int i = 0; i <L.length ; ++i)
	{
		printf("%d\t",L.data[i] );
	}
	printf("\n");
	printf("length == %d\n",L.length );
	
}
Status ListInsert(Sqlist *L,int i,Elemtype e)
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
		for (k=L->length; k>=i-1 ; k--)//注意这里是i
		{
			L->data[k+1]=L->data[k];
			//赋值应该从后面开始赋值，如果从前面开始赋值，会覆盖后面的值
		}
	}
	L->data[i-1]=e;
	L->length++;
	return OK;
}

Status ListDelect(Sqlist *L,int i,Elemtype *e)
{
	int k;
	if (L->length==0)
	{
		return ERROR;
	}
	if (i<1||i>L->length)
	{
		return ERROR;
	}
	*e=L->data[i-1];
	//和插入的区别是：取出值要在调序前完成
	if (i<L->length)
	{
		for (k=i; k <L->length ; k++)
		{
			L->data[k-1]=L->data[k];
		}
	}
	
	L->length--;
	return OK;
}




int main(int argc, char const *argv[])
{
	Sqlist l1={{5,7,3,4,2,6},6};

	Elemtype e;
	print_l(l1);
	ListInsert(&l1,4,19);
	print_l(l1);
	ListDelect(&l1,4,&e);
	print_l(l1);
	printf("%d\n",e );
	
	

	return 0;
}





