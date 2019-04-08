#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//子串的定位操作通常称为串的模式匹配
//KMP算法可以大大避免重复遍历的情况

//问题是由模式串决定,不是由目标串决定  即是pattern决定,而不是text决定


void prefix_table(char pattern[],int prefix[],int n)

//prefix是数组但是前面还没有经过-1处理的
{
	prefix[0]=0;//初始第一位为0
	int len = 0;//len是prefix的位值
	int i =1;//从i=1开始,也就是第二位开始,i是pattern的下标,从0开始
	while(i<n)
	{
		if (pattern[i]==pattern[len])
		//如果pattern的下一位等于pattern[len]
		{
			len++;
			prefix[i]=len;
			i++;
		}
		//遇到不相同的并不是直接写0
		//例外条件是:当到最后一位时,是特殊情况,需要 斜对指向
		else{
			if (len>0)
			{
				len=prefix[len-1];
			}
			//else是len==0情况 
			else{
				prefix[i]=len;
				i++;
			}
		}
	}
}

//向后移位,最后一位不需要,第一位赋值给-1,当遇到-1时直接往后移

void move_prefix_table(int prefix[],int n)//n代表pattern的字符个数
{
	int i;
	for (i = n-1; i >0; i--)
	{
		prefix[i]=prefix[i-1];
	}
	prefix[0]=-1;
}

void KMP_search(char text[],char pattern[])
//text[i]       text原字符串              len(text)=m
//pattern[j]    pattern匹配字符串 	    len(pattern)=n
{
	int n=strlen(pattern);
	int m=strlen(text);
	int *prefix = malloc(sizeof(int)*n);
	prefix_table(pattern,prefix,n);
	move_prefix_table(prefix,n);
	int i=0,j=0;

	while (i<m)
	{
		if (j==n-1&&text[i]==pattern[j])
		//匹配到pattern的最后一位
		//且   
		{
			printf("Found pattern at location %d\n",i-j+1 );
			j=prefix[j];
		}
		//匹配成功往右移
		if (text[i]==pattern[j])
		{
			i++;j++;
		}
		//匹配失败
		else{
			j=prefix[j];
			if (j==-1)
			{
				i++;j++;
			}
		}

	}
}



int main(int argc, char const *argv[])
{
	char pattern[]="as";
	char text[]="casjkldwbndawjrioajdkasndasmdiowq";
	KMP_search(text,pattern); 
	/*
	int prefix[9];
	int n=9;
	prefix_table(pattern,prefix,n);
	move_prefix_table(prefix,n);
	int i;
	for (i = 0; i < n; ++i)
	{
		printf("%d\n",prefix[i] );
	}
	*/

	return 0;
}



