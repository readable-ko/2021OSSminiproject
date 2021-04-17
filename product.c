//This is product function code
//
#include <stdio.h>
#include <string.h>
#include "manager.h"


int selectMenu() {
	int menu;
	printf("\n쇼핑몰 프로그램입니다.\n");
	printf("1. 판매 상품 추가\n");
	printf("2. 판매 상품 조회\n");
	printf("3. 판매 상품 수정\n");
	printf("4. 판매 상품 삭제\n");
	printf("5. 판매 상품 저장\n");
	printf("6. 상품 검색\n");
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
	while(1) {
		printf("상품의 별점을 입력해주세요(1~5점): ");
		scanf("%f", &p->rate);
		if(p->rate >= 1.0 && p->rate <= 5.0) break;
	}

	printf("상품의 별점 갯수를 입력해주세요: ");
	scanf("%d", &p->countstar);
	
	return 1;
}

void readProduct(Product p) {
	if(p.price == -1)
		printf("현재 입력된 상품이 없습니다.\n");
	else {
		float aver = p.rate;
		printf("  /  %s  /  %.2fkg /  %d원  /  %.2f(%d개)\n",p.name, p.weight, p.price, aver, p.countstar);
	}                                      
}

int updateProduct(Product *p) {	
	printf("상품 이름을 입력해주세요: ");
	scanf("%s", p->name);
	printf("상품의 중량을 입력해주세요: ");
	scanf("%f", &p->weight);
	printf("상품의 판매가격을 입력해주세요: ");
	scanf("%d", &p->price);
	while(1) {
		printf("상품의 별점을 입력해주세요(1~5점): ");
		scanf("%f", &p->rate);
		if(p->rate >= 1 && p->rate <= 5) break;
	}
	printf("상품의 별점 개수를 입력해주세요: ");
	scanf("%d", &p->countstar);
	printf("수정이 완료되었습니다! \n");
	
	return 1;
}

int deleteProduct(Product *p) {
	p->weight = -1;
	p->price = -1;
	p->rate = -1;
	p->countstar = -1;
	printf("데이터가 모두 삭제되었습니다.\n");
	return 1;
}

int loadData(Product *p) {
	int i = 0;
	FILE *fp;
	fp = fopen("product.txt","rt");
	for(; i < 100; i++) {
		fscanf(fp, "%s", p[i].name);
		if(feof(fp)) break;
		fscanf(fp, "%f", &p[i].weight);
		fscanf(fp, "%d", &p[i].price);
		fscanf(fp, "%f", &p[i].rate);
		fscanf(fp, "%d", &p[i].countstar);
	}
	fclose(fp);
	if(i == 0) printf(" => 파일이 없습니다\n");
	else printf(" => 로딩에 성공했습니다.\n");
	return i;
}

void saveData(Product *p, int count) {
	FILE *fp;
	fp = fopen("product.txt","wt");

	for(int i = 0; i < count; i++) {
		if(p[i].price == -1) continue;
		fprintf(fp, "%s %f %d %f %d \n", p[i].name, p[i].weight, p[i].price, p[i].rate, p[i].countstar);
	}
	fclose(fp);
	printf(" => 저장되었습니다.\n");
}

void searchName(Product *p, int count) {
	char search[20];
	int scnt = 0;
	
	printf("\n");
	printf("검색할 상품명을 입력해주세요: ");
	scanf("%s",search);

	printf("  번호  /  상품명  /  중량  /  판매가격  /  별점(갯수)\n");
	printf("===========================================\n");
	for(int i = 0; i < count; i++) {
		if(p[i].price == -1) continue;
		if(strstr(p[i].name, search)) {
			printf("  %2d    %s   %.2f    %d    %.2f(%d)\n",i+1, p[i].name, p[i].weight, p[i].price,
				       	p[i].rate, p[i].countstar);
			scnt++;
		}
	}
	if(scnt == 0) printf("검색된 데이터가 없습니다.\n\n");
}

void searchPrice(Product *p, int count) {
	int lower_bound;
	int upper_bound;
	int scnt = 0, key;

	while(1) {
		printf("\n");
		printf("검색할 최소 금액을 입력해주세요 : ");
		scanf("%d", &lower_bound);
	
		printf("검색할 최대 금액을 입력해주세요 : ");
		scanf("%d", &upper_bound);

		printf("%d ~ %d 사이 금액 대 물건을 검색하겠습니까?(맞다면 1번 틀리다면 0번) : ", lower_bound, upper_bound);
		scanf("%d", &key);
		if(key == 1) break;
	}
	
	printf("  번호  /  상품명  /  중량  /  판매가격  /  별점(갯수)\n");
	printf("===========================================\n");
	for(int i = 0; i < count; i++) {
		if(p[i].price == -1) continue;
		if(p[i].price >= lower_bound && p[i].price <= upper_bound) {
			printf("  %2d    %s    %.2f   %d    %.2f(%d)\n",i+1, p[i].name, p[i].weight, p[i].price,
				       	p[i].rate, p[i].countstar);
			scnt++;
		}
	}
	if(scnt == 0) printf("검색된 데이터가 없습니다.\n\n");
}

void searchRate(Product *p, int count) {
	int lower_bound;
	int upper_bound;
	int scnt = 0, key;

	while(1) {
                while(1) {
			printf("\n");
			printf("검색할 최저 별점을 입력해주세요(1~5점) : ");
			scanf("%d", &lower_bound);
                	if(lower_bound >= 1 && lower_bound <= 5) break;
                }

                while(1) {
			printf("검색할 최대 별점을 입력해주세요(1~5점) : ");
			scanf("%d", &upper_bound);
                	if(upper_bound >= 1 && upper_bound <= 5) break;
                }

		printf("별점 %d ~ %d 사이  상품을 검색하겠습니까?(맞다면 1번 틀리다면 0번) : ", lower_bound, upper_bound);
		scanf("%d", &key);
		if(key == 1) break;
	}
	
	printf("  번호  /  상품명  /  중량  /  판매가격  /  별점(갯수)\n");
	printf("===========================================\n");
	for(int i = 0; i < count; i++) {
		if(p[i].price == -1) continue;
		if(p[i].rate >= lower_bound && p[i].rate <= upper_bound) {
			printf("  %2d    %s    %.2f    %d    %.2f(%d)\n",i+1, p[i].name, p[i].weight, p[i].price,
				       	p[i].rate, p[i].countstar);
			scnt++;
		}
	}
	if(scnt == 0) printf("검색된 데이터가 없습니다.\n\n");
}
void searchStar(Product *p, int count) {
	int lower_bound;
	int upper_bound;
	int scnt = 0, key;

	while(1) {
	        printf("\n검색할 최소 리뷰 갯수를 입력해주세요 : ");
	        scanf("%d", &lower_bound);

        
	        printf("검색할 최대 리뷰 갯수를 입력해주세요 : ");
        	scanf("%d", &upper_bound);

		printf("%d ~ %d 사이 리뷰 갯수를 가진 상품을 검색하겠습니까?(맞다면 1번 틀리다면 0번) : ",
			       	lower_bound, upper_bound);
		scanf("%d", &key);
		if(key == 1) break;
	}
	
	printf("  번호  /  상품명  /  중량  /  판매가격  /  별점(갯수)\n");
	printf("===========================================\n");
	for(int i = 0; i < count; i++) {
		if(p[i].price == -1) continue;
		if(p[i].countstar >= lower_bound && p[i].countstar <= upper_bound) {
			printf("  %2d    %s    %.2f    %d    %.2f(%d)\n",i+1, p[i].name, p[i].weight, p[i].price,
				       	p[i].rate, p[i].countstar);
			scnt++;
		}
	}
	if(scnt == 0) printf("검색된 데이터가 없습니다.\n\n");
}
