#include <stdio.h>

int main()
{
	int X,Y;
	scanf("%d %d" , &X, &Y);
	if(X==0 || Y==0)
	{
		printf("punct de axe\n");
	}
	else if(X > 0 && Y > 0)
	{
		printf("1\n");
	}
	else if(X < 0 && Y > 0)
	{
		printf("2\n");
	}
	else if(X < 0 && Y < 0)
	{
		printf("3\n");
	}
	else if(X > 0 && Y < 0)
	{
		printf("4\n");
	}
return 0;
}

