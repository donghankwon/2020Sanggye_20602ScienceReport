#include <stdio.h>
#include <stdlib.h>

int main()
{
	int arr[1024][128]; //정리할 배열 
	int swap, cmp; //교환, 비교 횟수 
	int n, m; //표본수, 항목수 
	int temp; //교환인수  
	
	printf("Input Sample/Item Quantity (Max 128/1024) : ");
	scanf("%d %d", &n, &m);
	
	for(int k=0; k<n; k++)
		for(int i=0; i<m; i++)
			scanf("%d", &arr[i][k]);
			
	for(int k=0; k<n; k++)
	{
		swap=0; cmp=0;
		int j, remember;
 		for (int i=1; i<m; i++)
		{
    		temp=arr[(j=i)][k];
    		while(--j>=0&&temp<arr[j][k])
			{
				cmp++;
				swap+=2;
        		arr[j+1][k]=arr[j][k];
        		arr[j][k]=temp;
    		}
  		}
		printf("Swap : %d / Compare : %d\n", swap, cmp);
	}
	system("PAUSE");
	return 0;
}
