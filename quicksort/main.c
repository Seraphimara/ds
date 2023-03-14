#include "quicksort.h"
#include <stdio.h>

int main() {
	int a[] = {3 ,6 ,77,1, -2, 0,-66,-6,1,1,999,777};
	for(int i = 0; i < sizeof(a)/sizeof(int); ++i) {
		printf("%d  ",a[i]);
	}
	puts("");
	quick_sort(a,0,sizeof(a)/sizeof(int)-1);
	for(int i = 0; i < sizeof(a)/sizeof(int); ++i) {
		printf("%d  ",a[i]);
	}
	puts("");
}
