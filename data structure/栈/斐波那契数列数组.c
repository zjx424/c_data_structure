#include <stdio.h>

int main()
{
	int arr[40]={};
	arr[0]=1;
	arr[1]=1;
	int i;
	for (i = 2; i < 40; ++i)
	{
		arr[i]=arr[i-1]+arr[i-2];1
	}
	for (i = 0; i < 40; ++i)
	{
		printf("%d\n",arr[i] );
	}
	return 0;
}


