#include <stdio.h>
#include <stdlib.h>
int sorted[1024];
int swap, cmp; //교환, 비교 횟수 

void quick_sort(int *data, int start, int end){
	cmp++;
    if(start >= end){
        // 원소가 1개인 경우
        return; 
    }
    
    swap+=4;
    int pivot = start;
    int i = pivot + 1; // 왼쪽 출발 지점 
    int j = end; // 오른쪽 출발 지점
    int temp;
    
    while(i <= j){
    	cmp++;
        // 포인터가 엇갈릴때까지 반복
        while(i <= end && data[i] <= data[pivot]){
        	cmp++;
            i++;
        }
        while(j > start && data[j] >= data[pivot]){
        	cmp++;
            j--;
        }
        
        cmp++;
        if(i > j){
            // 엇갈림
            swap+=3;
            temp = data[j];
            data[j] = data[pivot];
            data[pivot] = temp;
        }else{
            // i번째와 j번째를 스왑
            swap+=3;
            temp = data[i];
            data[i] = data[j];
            data[j] = temp;
        }
    } 
    
    // 분할 계산
    quick_sort(data, start, j - 1);
    quick_sort(data, j + 1, end);
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
		quick_sort(setarr, 0, m-1);
		printf("Swap : %d / Compare : %d\n", swap, cmp);
	}
	system("PAUSE");
	return 0;
}
