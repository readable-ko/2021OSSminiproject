//This code is productmain.c
//
#include <stdio.h>
#include "product.h"
#include "manager.h"

int main() {
	Product plist[100];
	plist[0].price = -1;
	int count = 0,index =0, menu;
	int delok;
	while(1) {
		menu = selectMenu();
		if(menu == 0) break;
		if(menu == 2 || menu == 3 || menu == 4)
			if(count == 0) continue;

		if(menu == 1) count += createProduct(&plist[index++]);
		else if(menu == 2) listProduct(plist, index);
		else if(menu == 3) {
			int num = selectDataNo(plist, index);
			if(num > 0)
				updateProduct(&plist[num-1]);
		}
		else if(menu == 4) {
			int num = selectDataNo(plist, index);
			if(num > 0) {
				printf("정말로 삭제하시겠습니까?(삭제 1번) :");
				scanf("%d",&delok);
				if(delok == 1) {
					deleteProduct(&plist[num-1]);
					count--;
				}
			}
		}
	}
	printf("프로그램이 종료되었습니다.\n");
	return 0;
}
