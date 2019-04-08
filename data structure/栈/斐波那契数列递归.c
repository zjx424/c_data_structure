#include <stdio.h>

int Fbi(int i)
{
	if (i<2)
	{
		if (i==0)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	return Fbi(i-1)+Fbi(i-2);
}




int main()
{
	int i;
	for (i = 1; i < 40; ++i)
	{
		printf("%d\n",Fbi(i) );
	}
	return 0;
	return 0;
}



