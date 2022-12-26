#include <stdio.h>

int main()
{
	int A,B,C,D;
	scanf("%d %d %d %d " , &A, &B, &C, &D);
	int min,max;
	min=A;
	max=0;
	if(A<=min)
		min=A;
	if(B<=min)
		min=B;
	if(C<=min)
		min=C;
	if(D<=min)
		min=D;
	if(A>=max)
		max=A;
	if(B>=max)
		max=B;
	if(C>=max)
		max=C;
	if(D>=max)
		max=D;
	
	printf("%d %d", min, max);
return 0;
}
