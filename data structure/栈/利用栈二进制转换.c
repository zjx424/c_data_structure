#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define STACK_INIT_SIZE 20 //20位
#define STACKINCREMENT 10 

typedef char ElemType;
typedef struct 
{
	ElemType *base;
	ElemType *top;
	int stackSize;
}sqStack;

void InitStack(sqStack *s)
{
	s->base=(ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));	
	if (!s->base)
	{
		exit(0);
	}
	s->top=s->base;
	s->stackSize=STACK_INIT_SIZE;//当前最大容量
}

void Push(sqStack *s,ElemType e)
{
	if (s->top - s->base >= s->stackSize)//栈满
	{
		s->base=(ElemType *)realloc(s->base,(s->stackSize+STACKINCREMENT)*sizeof(ElemType));
		//增加容量
		if (!s->base)
		{
			exit(0);
		}
	}
	*(s->top)=e;
	s->top++;
}

void Pop(sqStack *s,ElemType *e)
{
	if (s->top == s->base)//空栈
	{
		return;
	}
	*e=*--(s->top);//相当于先把s->top--,然后再把值赋值给e
	// s->top=(s->top)-1;
	// *e=*s->top;
}

int StackLen(sqStack s)
{
	return(s.top-s.base);
}

int main(int argc, char const *argv[])
{
	ElemType c;
	sqStack s;
	int len,i,sum=0;
	InitStack(&s);
	printf("请输入二进制数,输入#符号表示结束:");
	scanf("%c",&c);
	while(c!='#')
	{
		Push(&s,c);
		scanf("%c",&c);
	}
	getchar();//把'\n'从缓冲区去掉

	len=StackLen(s);

	printf("栈的当前容量是%d\n",len );
	for (i = 0; i < len ; ++i)
	{
		Pop(&s,&c);
		sum=sum+(c-48)*pow(2,i);//转assci码  
	}
	printf("sum  == %d\n",sum );
	return 0;
}
