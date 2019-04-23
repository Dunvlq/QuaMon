#include "handling.h"


using namespace std;

struct dssinhvien { // cau truc danh sach sinh vien
	int MASV; // ma sinh vien bat dau bang so 3 (6 ki tu)
	char HO[50];
	char TEN[30];
	bool PHAI; // nam la 1 nu la 0
	int SODT;
	char MALOP[15]; //ma lop cua sinh vien
};
typedef struct dssinhvien dssv;

struct dsdangki { // cau truc danh sach dang ki
	int MASV; // ma sinh vien bat dau bang so 3 (5 ki tu)
	float DIEM;
};
typedef struct dsdangki dsdk;

struct linkedlist { // hai con tro quan li danh sach lien ket don 
	dssv *FIRSTSV; // con tro first cua danh sach sinh vien
	dssv *LASTSV; // con tro last cua danh sach sinh vien
	dsdk *FIRSTDK; // con tro first cua danh sach dang ki
	dsdk *LASTDK; // con tro last cua danh sach dang ki
};
typedef struct linkedlist LLIST;

struct nodelkd { // node cua danh sach lien ket don
	dssv sinhvien;	
	dsdk dangki;
	struct nodelkd *NEXT;
};
typedef struct nodelkd NODELKD;
