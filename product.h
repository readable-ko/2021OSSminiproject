#ifndef __PRODUCT_H__
#define __PRODUCT_H__

typedef struct {
	char name[20];
	float weight;
	int price;
	float rate[20];
	int countstar;
} Product;

int selectMenu();
int createProduct(Product *p);
void readProduct(Product p);
int updateProduct(Product *p);
int deleteProduct(Product *p);

int loadData(Product *p);
void saveData(Product *p, int count);

//void listProduct(Product *plist, int count);
//void selectDataNo(Product *plist, int count);
void searchName(Product *p, int count);
void searchPrice(Product *p, int count);
void searchRate(Product *p, int count);
void searchStar(Product *p, int count);

#endif
