#include <stdio.h>
#define MAXSIZE 20
typedef int Elemtype;

typedef struct 
{
	Elemtype data[MAXSIZE];
	int length;
}Sqlist;


#define ERROR 0
#define OK 0
typedef int Status;
Status GetElem(Sqlist L,int i,Elemtype *e)
{
	if (i<1||i>L.length||L.length==0)
	//判断条件1，取的位置小于1
	//判断条件2，取得位置比长度还大
	//判断条件3，空线性表
	{
		printf("ERROR！！！\n");
		return ERROR;
	}
	*e=L.data[i-1];
	return OK;
}

int main(int argc, char const *argv[])
{
	Sqlist l1={{6,8,4,3,1,7,5},7};
	Elemtype e;
	GetElem(l1,5,&e);
	printf("l1 的第五个数赋值给e，e==%d\n",e );
	return 0;
}
