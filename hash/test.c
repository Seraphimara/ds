#include "hash.h"
#include <stdio.h>

int main() {
	hash *h = hash_create();
	if (h == NULL) {
		printf("malloc failde\n");
		return -1;
	}
	hash_insert(h,655);
	hash_insert(h,230);
	hash_insert(h,36);
	hash_insert(h,687);
	hash_insert(h,103);
	hash_insert(h,405);
	hash_insert(h,693);
	hash_insert(h,104);
	hash_insert(h,999);
	hash_insert(h,1l);
	hash_insert(h,12);
	hash_insert(h,23);
	hash_insert(h,77);
	
	hash_search(h, 12);
	hash_search(h, 230);
	hash_search(h, 1000);
	return 0;
}
