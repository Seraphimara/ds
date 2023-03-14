#include <stdio.h>
int partion(int *data,int low,int high) {
	int temp = data[low];
	while(low < high) {
		while(low < high && data[high] >= temp) 
			high--;
		data[low] = data[high];
		while(low < high && data[low] <= temp)
			low++;
	        data[high] = data[low];	
	}
	data[low] = temp;
	return low;
}
int quick_sort(int *data,int low,int high) {
	int t;
	if(data == NULL) {
		printf("data is NULL\n");
		return -1;
	}
	if(low >= high)
		return 0;
	t = partion(data, low, high);
	quick_sort(data,low,t-1);
	quick_sort(data,t+1,high);
	return 0;
}
