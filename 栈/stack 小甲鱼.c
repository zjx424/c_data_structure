#include <stdio.h>
#include <stdlib.h>


#define STACKINCREMENT 10

typedef int ElemType;
typedef struct
{
	ElemType *base;//指向栈底
	ElemType *top;//指向栈顶
	int stackSize;//当前最大容量
}sqStack;

#define STACK_INIT_SIZE 100
initStack(sqStack *s)
{
	s->base=(ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
	if (!s->base)
	{
		exit(0);
		s->top=s->base;
		s->stackSize=STACK_INIT_SIZE;
	}
}
Push (sqStack *s,ElemType e)
{
	if (s->top-s->base>=s->stackSize)
	{
		s->base=(ElemType *)realloc(s->base,(s->stackSize+STACKINCREMENT)*sizeof(ElemType));
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

Pop(sqStack *s,ElemType *e)
{
	if (s->top==s->base)
	{
		return;
	}
	*e=*--(s->top);
}

int main()
{
	return 0;
}