#pragma once
#include "monhoc.h"
#define TRUE 1
#define FALSE 0
#define MAX 500

using namespace std;

struct dsloptinchi { // cau truc danh sach lop tin chi
	int MALOPTC; //  random so co 3 chu so
	char MAMH[12]; // ma mon hoc (10 ki tu)
	unsigned int NIENKHOA;
	unsigned int HOCKY;
	unsigned int NHOM;
	unsigned int SVMAX;
	DSSV *sv = NULL;
};
typedef struct dsloptinchi dsltc;

struct nodett { // danh sach lop tin chi la mang con tro ( node tuyen tinh )
	int n; 
	dsltc *nodett[MAX];
};
typedef struct nodett NODETT;	

int Emptytt (NODETT &ds);
int Fulltt (NODETT ds);
void InitializeTT(NODETT &ds);
int Search_MAMONHOC (NODETT &ds, char MAMONHOC[10]); // ham tin ma mon hoc da co
int Search_MALOPTC(NODETT &ds, unsigned int temp); // ham tim Ma lop tin chi da co
int Search_NIENKHOA(NODETT &ds, unsigned int temp);
int Search_HOCKY(NODETT &ds, unsigned int temp);
int Search_SVMAX(NODETT &ds, unsigned int temp);
int TraverseINT (NODETT &ds,unsigned int temp);
int TraverseCHAR (NODETT &ds,char temp[10]);
int CheckMaMH(NODETT ds, char *mh);
void Create_LopTinChi (NODETT &ds); // ham tao lop tin chi
void Fix_Data_LTC(NODETT &ds,int j, int k);
void Show_Data_LTC(NODETT &ds,int i); // ham xuat danh sach lop tin chi
void DocFile_LTC(NODETT &ds);
void GhiFile_LTC(NODETT &ds);
void Delete_LTC_MALOPTC(NODETT &ds, unsigned int temp);
void Delete_LTC_MAMONHOC(NODETT &ds, char MAMONHOC[10]);
void DeleteALL(NODETT &ds);
unsigned int Random();

