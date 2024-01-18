# include <stdio.h>

int main(){
	int numArr[15];
	int* ptr = numArr;
	int revArr[15];
	int n, i, j;

	printf("Input the number of elements to store (max 15): ");
	fflush(stdout); fflush(stdin);
	scanf("%u", &n);

	for (i=0; i<n; i++)
	{
		printf("Enter element #%d: ", i+1);
		fflush(stdout); fflush(stdin);
		scanf("%d", &numArr[i]);
	}

	ptr += n;
	i = n; 	j = 0;

	while (i)
	{
		ptr--;
		revArr[j] = *ptr;
		--i,	j++;
	}

	for(i=0, j=n; i<n; i++, j--)
		printf("\nElement #%d: %d ", j, revArr[i]);

	return 0;
}
