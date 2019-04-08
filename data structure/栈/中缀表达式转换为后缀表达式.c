//  1+(2-3)*4+10/5
//  
//  1 2 3 - 4 * + 10 5 / +
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


#define STACK_INIT_SIZE 20 //20位
#define STACKINCREMENT 10  
#define MAXBUFFER 10

typedef double ElemType;
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
		s->top=s->base+s->stackSize;
		s->stackSize=s->stackSize+STACKINCREMENT;
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


int main()
{
	sqStack s;
	char c,e;
	InitStack(&s);
	printf("请输入中缀表达式,以#作为结束标志:");
	scanf("%c",&c);
	while(c!='#')
	{
		if (c>='0'&&c<='9')
		{
			printf("%c\n",c );
		}
		else if (')' == c)
		{
			Pop(&s,&e);
			while('('!=e)
			{
				printf("%c",e );
				Pop(&s,&e);
			}
		}
		else if ('+'==c||'-'==c)
		{
			if (!StackLen(s))
			{
				Push(&s,c);
			}
			else
			{
				do
				{
					Pop(&s,&e);
					if ('('==e)
					{
						Push(&s,e);
					}
					else
					{
						printf("%c",e );
					}
				}while(StackLen(s)&&'('!=e);
				Push(&s,c);
			}
		}
		else if ('*'==c||'/'==c||'('==c)
		{
			Push(&s,c);
		}
		else
		{
			printf("用户输入错误!\n");
			return -1;
		}
		scanf("%c",&c);
	}
}