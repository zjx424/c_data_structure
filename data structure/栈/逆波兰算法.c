#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

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
//遇到数字Push进栈,遇到符号,Pop数字出,Push数字的加减乘除的值进去

int main()
{
	sqStack s;
	int i=0;
	char c;
	double d,e;
	char str[MAXBUFFER];//缓冲区str[10]
	printf("请按逆波兰表达式输入待计算的数据,数据与运算符之间用空格隔开,以#作为结束标志:\n");
	InitStack(&s);
	scanf("%c",&c);
	while (c!='#')
	{
		while (isdigit(c)||c=='.')//用于过滤数字
		//判断它是否是数字assci48-57,判断c是否数字
		{ 
			// str[i++]=c;
			// str[i]='\0';
			// 这两句相当于
			str[i]=c;
			i++;
			str[i]='\0';//字符串的结束符是'\0'
			if (i>=10)
			{
				printf("出错,输入的单个数据过大\n");
				return -1;
			}
			scanf("%c",&c);
			if (c==' ')
			{
				d=atof(str);//字符串转换为double型
				Push(&s,d);
				i=0;
				break;
			}
		}
		switch( c )
		{
			case '+':
				Pop(&s,&e);
				Pop(&s,&d);
				Push(&s,d+e);
				break;
			case '-':
				Pop(&s,&e);
				Pop(&s,&d);
				Push(&s,d-e  );
				break;
			case '*':
				Pop(&s,&e);
				Pop(&s,&d);
				Push(&s,d*e);
				break;
			case '/':
				Pop(&s,&e);
				Pop(&s,&d);
				if (e!=0)
				{	
					Push(&s,d/e);
				}
				else 
				{	
					printf("出错!除数为0\n" ); 
					return -1;
				}
				break;
		}
		scanf("%c",&c);
	}
	Pop(&s,&d);
	printf("结果为%.2f'\n",d);


	return 0;
}

// 5 6 7 + 8 * - 9 4 / + #