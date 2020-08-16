#include <stdio.h>

int main()
{
	int arr[1024][128]; //정리할 배열 
	int swap, cmp; //바꿈, 비교 횟수 
	int n, m; //표본수, 항목수 
	
	printf("Input Sample/Item Quantity (Max 128/1024) : ");
	scanf("%d %d", &n, &m);
	
	for(int k=0; k<n; k++)
		for(int i=0; i<m; i++)
			scanf("%d", &arr[i][k]);
			
	for(int k=0; k<n; k++)
	{
		
	}
}
