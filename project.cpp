#include <iostream>
#include <stdlib.h>
#include <cstring> 
#define MAXLOP 30
#define MAX 100
#define TRUE 1
#define FALSE 0
using namespace std;

struct danhsachsinhvien {
	int MASV;
	char HO[30];
	char TEN[30];
	bool PHAI;
	int SODT;
	char MALOP[15];
	
};
typedef struct danhsachsinhvien dssv;


struct danhsachdangki {
	int MASV;
	float DIEM;
};
typedef struct danhsachdangki dsdk;

struct danhsachloptinchi {
	int MALOPTC;
	int MAMH;
	int nienkhoa;
	int hocky;
	int nhom;
	int sosvmax;
	dssv sv;
};
typedef struct danhsachloptinchi dsltc;

struct nodes {
	dssv sv;
	dsdk dk;
	dsltc tc;
	struct nodes *NEXT;
	
};

struct linkedlist {
	nodes *FIRST;
	nodes *LAST;
};


struct listtc {
	int n=0;
	dsltc *list[MAX];
};


int main() {
	
}
