/*循环链表
将单链表中终端结点的指针端由空指针改为指向头结点，就使整个单链表形成一个环
，这种头尾相接的单链表成为单循环链表，简称循环链表

并不是说循环链表一定要有头结点
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
	int item;
	int count=0;
	p_list temp;
	p_list target;
	srand(time(0));

	while(count<=10)
	{
		item=rand()%100+1;
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
void insert(p_list *pNode,int place,int num)//place 位置，num插入的数字
{
	p_list temp,target;
	int i;
	if (place==1)//如果输入的数字是1，表示要插入头节点。应该特殊处理
	{
		temp=(p_list)malloc(sizeof(list));
		if (!temp)exit(0);
		temp->data=num;
		for (target=*pNode;target->next!=*pNode;target=target->next)
		{
			temp->next=*pNode;
			target->next=temp;
			*pNode=temp;
		}
	}
	else//在其他的地方插入节点。  同样先找到要插入的位置，如果位置超出链表的长度，自动插入队尾。						
	{//找到要插入位置的前一个节点target，让target->next=temp，插入节点的前驱指向新节点，新节点指向target->next的地址  
		for(i=1,target=*pNode;target->next!=*pNode&&i!=place-1;target=target->next,i++);
		temp=(p_list)malloc(sizeof(list));
		temp->data=num;
		
		temp->next=target->next;
		target->next=temp;
	}
}
void Delete(list **pNode,int place)  //删除操作
{
	list *temp,*target;
	int i;
	temp=*pNode;
	if(temp==NULL)				//首先判断链表是否为空
	{
		printf("这是一个空指针 无法删除\n");
		return;
	}
	if(place==1)		//如果删除的是头节点	
	{				//应当特殊处理，找到尾节点，使尾节点的next指向头节点的下一个节点
                    // rear->next=(*head)->next;然后让新节点作为头节点，释放原来的头节点
		for(target=*pNode;target->next!=*pNode;target=target->next);
		temp=*pNode;
		
		*pNode=(*pNode)->next;
		target->next=*pNode;
		free(temp);
	}
	else //删除其他节点
	{		//首先找出尾节点
		for(i=1,target=*pNode;target->next!=*pNode&&i!=place-1;target=target->next,i++); 
		if(target->next==*pNode)		//判断要删除的位置是否大于链表长度，若大于链表长度，        
                                        //特殊处理直接删除尾节点
		{
                //找出尾节的前一个节点
			for(target=*pNode;target->next->next!=*pNode;target=target->next);
			temp=target->next;	 //	尾节点的前一个节点直接指向头节点  释放原来的尾节点									
			target->next=*pNode;
			printf("数字太大删除尾巴\n");
			free(temp);
		}
		else
		{
			temp=target->next;//  删除普通节点  找到要删除节点的前一个节点target，
                                //使target指向要删除节点的下一个节点  转存删除节点地址
			target->next=temp->next;	//  然后释放这个节点
			free(temp);
		}
	}
}

int findval(list *pNode ,int val)
{
	int i=1;
	list *node;
	node=pNode;
	while(node->data!=val&&node->next!=pNode)
	{
		i++;
		node=node->next;
	}
	if (node->next==pNode&& node->data!=val)
	{
		return -1;
	}
	return i;
}

int Length(p_list p)
{
	int i=0;
	p_list temp;
	if (p==NULL) return 0;
	if (p->next==p)
	{
		return 1;
	}
	temp=p->next;
	while(temp!=p)
	{
		i++;
		temp=temp->next;
	}
	return i+1;
}




int main()
{
	int len;
	p_list head=NULL;
	p_list val=NULL;
	creat_list(&head);
	printf("原始的链表：");
	show(head);

	int find_item=35;
	int place=findval(head,find_item);
	if(place!=-1)printf("找到的值的位置是place=%d\n",place);
	else printf("没找到%d\n",find_item);

	printf("在第二个位置插入99。。。\n");
	insert(&head,2,99);
	show(head);
	len=Length(head);
	printf("长度为%d\n",len );



	printf("删除第五个位置的元素。。。\n");
	Delete(&head,5);
	show(head);
	len=Length(head);
	printf("长度为%d\n",len );

}
