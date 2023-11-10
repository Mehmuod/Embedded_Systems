#include <stdio.h>

int main() {
	int a[5][5], trans[5] [5], r, c, i, j;
	printf ("Enter rows and column of matrix: ");
	fflush(stdin); fflush(stdout);
	scanf("%d %d", &r, &c);

	printf ("\nEnter elements of matrix:\n");
	for(i=0; i<r; ++i)
	for(j=0; j<c; ++j)
	{
	printf ("Enter element a%d%d : ",i+1,j+1);
	fflush(stdin); fflush(stdout);
	scanf ("%d",&a[i][j]);
	}

	printf ("\nEntered Matrix: \n");
	for(i=0; i<r; ++i)
	for(j=0; j<c; ++j)
	{
	printf("%d ",a[i][j]);
	if(j==c-1)
	printf("\n");
	}

	for(i=0; i<r; ++i)
	for(j=0; j<c; ++j)
	{
	trans[ j] [i]=a[i] [j] ;
	}

	printf ("\nTranspose of Matrix:\n");
	for(i=0; i<c; ++i)
	for(j=0; j<r; ++j)
	{
	printf("%d ", trans[i] [j] );
	if(j==r-1)
	printf("\n");
	}
	return 0;
}