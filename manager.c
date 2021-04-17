//THis is the manager fuction file of product
#include <stdio.h>
#include "manager.h"

void listProduct(Product *plist, int count) {
	printf("  번호  /  상품명  /  무게  /  가격  /  별점(별점 개수)\n");
	for(int i = 0; i < count; ++i) {
		if(plist[i].price == -1) continue;
		printf("  %2d",i+1);
		readProduct(plist[i]);
	}
}

int selectDataNo(Product *plist, int count) {
	int num;
	listProduct(plist, count);
	printf("무엇을 선택하시겠습니까?");
	scanf("%d", &num);
	return num;
}
