//顺序存储结构封装需要三个属性
//1存储空间的起始位置,数组data,它的存储位置就是线性表存储空间位置
//2线性表的最大存储容量:数组的长度MAXSIZE
//3线性表的当前长度length
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
//这个函数就是
//判断GetElem(l1,2,&e);中2是否在length的范围内,
//然后传入e的指针,返回l1的第二个元素给e
Status GetElem(SqList L,int i,ElemType *e)
{
	if (L.length==0||i<1||i>L.length)//空表，传入位置小于1，传入位置大于长度报错
	{
		return ERROR;
	}
	*e=L.data[i-1];//否则赋值给传入指针的值；
	return OK;
}

int main(int argc, char const *argv[])
{
	printf("\n");
	SqList l1={{8,6,2,3,7},5};
	//利用GetElem实现翻转
	int arr[5]={};
	int k=1;
	for (int i = 4; i >=0 ; i--)
	{
		GetElem(l1,k,&arr[i]); 
		k++;
	}
	printf("翻转前\n");
	for (int i = 0; i < 5; ++i)
	{
		printf("%d \t",l1.data[i] );
	}
	printf("\n");
	printf("翻转后\n");
	for (int i = 0; i < 5; ++i)
	{
		printf("%d \t",arr[i] );
	}
	printf("\n");
	
	return 0;
}









