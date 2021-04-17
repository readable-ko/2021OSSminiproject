//This is product function code
//
#include <stdio.h>
#include "manager.h"


int selectMenu() {
	int menu;
	printf("\n쇼핑몰 프로그램입니다.\n");
	printf("1. 판매 상품 추가\n");
	printf("2. 판매 상품 조회\n");
	printf("3. 판매 상품 수정\n");
	printf("4. 판매 상품 삭제\n");
	printf("0. 종료\n");
	printf("원하는 메뉴를 선택해 주세요: ");
	scanf("%d",&menu);
	return menu;
}

int createProduct(Product *p) {
	printf("상품 이름을 입력해주세요: ");
	scanf("%s", p->name);
	printf("상품의 중량을 입력해주세요: ");
	scanf("%f", &p->weight);
	printf("상품의 판매가격을 입력해주세요: ");
	scanf("%d", &p->price);
	printf("상품의 별점을 입력해주세요: ");
	scanf("%d", &p->rate[0]);
	p->countstar = 1;
	
	return 1;
}

void readProduct(Product p) {
	if(p.price == -1)
		printf("현재 입력된 상품이 없습니다.\n");
	else {
		float aver = p.rate[0];
		printf("  /%s  / %.2fkg / %d원  / %.2f(%d개)\n",p.name, p.weight, p.price, aver, p.countstar);
	}
}

int updateProduct(Product *p) {	
	printf("상품 이름을 입력해주세요: ");
	scanf("%s", p->name);
	printf("상품의 중량을 입력해주세요: ");
	scanf("%f", &p->weight);
	printf("상품의 판매가격을 입력해주세요: ");
	scanf("%d", &p->price);
	printf("상품의 별점을 입력해주세요: ");
	scanf("%d", &p->rate[0]);
	printf("상품의 별점 개수를 입력해주세요: ");
	scanf("%d", &p->countstar);
	printf("수정이 완료되었습니다! \n");
	
	return 1;
}

int deleteProduct(Product *p) {
	p->weight = -1;
	p->price = -1;
	p->rate[0] = -1;
	p->countstar = -1;
	printf("데이터가 모두 삭제되었습니다.\n");
	return 1;
}


