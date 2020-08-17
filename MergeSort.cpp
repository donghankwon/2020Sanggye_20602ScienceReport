#include <stdio.h>
#include <stdlib.h>
int sorted[1024];
int swap, cmp; //교환, 비교 횟수 

void merge(int a[], int m, int middle, int n)
{
	swap+=3;
	int i=m;
	int j=middle+1;
	int k=m;
	
	
	while(i<=middle&&j<=n)
	{
		cmp+=3;
		if(a[i]<=a[j])
		{
			swap++;
			sorted[k]=a[i];
			i++;
		}
		else
		{
			swap++;
			sorted[k]=a[j];
			j++;
		}
		k++;
	}
	cmp++;
	if(i>middle)
	{
		for(int t=j; t<=n; t++)
		{
			swap++;
			sorted[k]=a[t];
			k++;
		}
	}
	else
	{
		for(int t=i; t<=middle; t++)
		{
			swap++;
			sorted[k]=a[t];
			k++;
		}
	}
	for(int t=m; t<=n; t++)
	{
		swap++;
		a[t]=sorted[t];
	}
}

void mergeSort(int a[], int m, int n)
{
	if(m<n)
	{
		int middle=(m+n)/2;
		mergeSort(a, m, middle);
		mergeSort(a, middle+1, n);
		merge(a, m, middle, n);
	}
}

int main()
{
	int arr[1024][128]; //정리할 배열 
	int setarr[1024];
	int n, m; //표본수, 항목수 
	int temp; //교환인수  
	
	printf("Input Sample/Item Quantity (Max 128/1024) : ");
	scanf("%d %d", &n, &m);
	
	for(int k=0; k<n; k++)
		for(int i=0; i<m; i++)
			scanf("%d", &arr[i][k]);
			
	for(int k=0; k<n; k++)
	{
		for(int i=0; i<m; i++)
			setarr[i]=arr[i][k];
		swap=0; cmp=0;
		mergeSort(setarr, 0, m-1);
		printf("Swap : %d / Compare : %d\n", swap, cmp);
	}
	system("PAUSE");
	return 0;
}
