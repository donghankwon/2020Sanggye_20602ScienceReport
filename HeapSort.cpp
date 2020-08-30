#include <stdio.h>
#include <stdlib.h>
int sorted[1024];
int swap, cmp; //교환, 비교 횟수 

void _swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int here, int size)
{
    int left = here * 2 + 1;
    int right = here * 2 + 2;
    int max=here;
    cmp++;
    if (left<size&&arr[left]>arr[max])
    {
    	swap++;
    	max = left;
	}
    cmp++;
    if (right < size&&arr[right]>arr[max])
    {
    	swap++;
    	max = right;
	}
 	cmp++;
    if (max != here)
	{
    	swap+=3;
        _swap(&arr[here], &arr[max]);
        heapify(arr, max, size);
    }
}

void buildHeap(int arr[], int size)
{
    int i,j;
    for (i = size / 2 - 1; i >= 0; i--)
        heapify(arr, i, size);
}

void heapSort(int arr[],int size)
{
    int treeSize;
    buildHeap(arr, size);
    for (treeSize = size - 1; treeSize >= 0; treeSize--)
	{
		swap+=3;
        _swap(&arr[0], &arr[treeSize]);
        heapify(arr, 0,treeSize);
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
		swap=0; cmp=0;
		for(int i=0; i<m; i++)
			setarr[i]=arr[i][k];
		heapSort(setarr, m);
		printf("Swap : %d / Compare : %d\n", swap, cmp);
	}
	system("PAUSE");
	return 0;
}
