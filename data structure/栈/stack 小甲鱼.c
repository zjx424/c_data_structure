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
		//增加容量
		
		if (!s->base)
		{
			exit(0);
		}
		s->top=s->base+s->stackSize;//设置栈顶
		s->stackSize=s->stackSize+STACKINCREMENT;//设置栈的最大容量    
	}
	*(s->top)=e;
	s->top++;
}

Pop(sqStack *s,ElemType *e)
{
	if (s->top==s->base)//空栈
	{
		return;
	}
	*e=*--(s->top);
}

//清空一个栈
//只需要将s->top赋值给s->base即可,这个原理跟高级格式化只是单纯地清空文件
//列表而没有覆盖硬盘的原理是一样的
ClearStack(sqStack *s)
{
	s->top=s->base;
}
//销毁一个栈
//销毁一个栈与清空一个栈不同,销毁一个栈是要释放掉该栈的物理内存空间
//不要和清空混淆

DestroyStack(sqStack *s)
{
	int i,len;
	len=s->stackSize;
	for (i = 0; i < len; ++i)
	{
		free(s->base);
		s->base++;
	}
	s->base=s->top=NULL;
	s->stackSize=0;
}

//计算栈当前容量就是计算栈中元素的个数
//返回s.top-s.base
//当前容量和最大容量不是一个概念
int StackLen(sqStack s)//这里的int有蹊跷
{
	return(s.top-s.base);
}


int main()
{
	return 0;
}