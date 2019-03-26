/*
据说著名犹太历史学家 Josephus有过以下的故事：
在罗马人占领乔塔帕特后，39 个犹太人与Josephus及他的朋友躲到一个洞中，39个犹太人决定宁愿死也不要被敌人抓到，
于是决定了一个自杀方式，41个人排成一个圆圈，
由第1个人开始报数，每报数到第3人该人就必须自杀，然后再由下一个重新报数，直到所有人都自杀身亡为止。
然而Josephus 和他的朋友并不想遵从。
首先从一个人开始，越过k-2个人（因为第一个人已经被越过），并杀掉第k个人。接着，再越过k-1个人，并杀掉第k个人。
这个过程沿着圆圈一直进行，直到最终只剩下一个人留下，这个人就可以继续活着。
问题是，给定了和，一开始要站在什么地方才能避免被处决？
Josephus要他的朋友先假装遵从，他将朋友与自己安排在第16个与第31个位置，于是逃过了这场死亡游戏
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct List
{
	int  data;
	struct List *next;
} list;
typedef struct List *p_list;


void creat_list(p_list *p)//如果链表为空，则创建一个链表，指针域指向自己，否则寻找尾节点，将
{						 //将尾节点的指针域指向这个新节点，新节点的指针域指向头结点
	int item=1;
	int count=0;
	p_list temp;
	p_list target;


	while(count<=40)
	{
		
		if(item==0)return;//输入0则结束
 
		if(*p==NULL)   //如果输入的链表是空。则创建一个新的节点，使其next指针指向自己  (*head)->next=*head;
		{
			*p=(p_list)malloc(sizeof(list));
			if(!*p)exit(0);
			(*p)->data=item;
			(*p)->next=*p;
		}
		else		//输入的链表不是空的，寻找链表的尾节点，使尾节点的next=新节点。新节点的next指向头节点
		{
			for(target=*p;target->next!=*p;target=target->next);
			//寻找尾节点。循环判断条件
			//当尾结点不等于头结点
 
			temp=(p_list)malloc(sizeof(list));
			if(!temp)exit(0);
			temp->data=item;
			temp->next=*p;  //新节点指向头节点
			target->next=temp;//尾节点指向新节点
		}
	item++;
	count++;
	}
}
void show(p_list p)//遍历，循环链表的遍历最好用do while语句 ，因为头节点就有值
{
	p_list temp;//头结点
	temp=p;
	do
	{
		printf("%5d",temp->data);
		temp=temp->next;	
	}
	while(temp!=p);//循环结点的判断条件
 
	printf("\n");
}



int main(int argc, char const *argv[])
{
	p_list jsf=NULL;
	creat_list(&jsf);
	printf("约瑟夫初循环链表\n");
	show(jsf);
	printf("\n");
	
	int n=41;
	int m=3;
	int i;
	p_list temp;
	m %= n;//m==2
	while(jsf!=jsf->next)//只剩下一个元素时结束
	{
		for (int i = 1; i <m-1 ; ++i)//循环执行一次
		{
			jsf=jsf->next;//1这里指向第二个结点 2 这里指向第五个结点
		}
		printf("%d ->",jsf->next->data );//1死的就是第三个2死的就是第六个

		//单链表删除操作
		temp=jsf->next;//释放第三个结点
		jsf->next=temp->next;
		free(temp);

		jsf=jsf->next;//1指向第四个2指向第七个

	}
	printf("%d\n",jsf->data );//把最后那个元素打印出来




	return 0;
}