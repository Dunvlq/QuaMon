#pragma once
#include "svandangki.h"
#include <iostream>
#include <stdlib.h>
#include <cstring> 
#include <windows.h>
#define MAXLOP 30
#define TRUE 1
#define FALSE 0
#define MAX 100

struct dsloptinchi { // cau truc danh sach lop tin chi
	int MALOPTC; //  random so co 3 chu so
	char MAMH[10]; // ma mon hoc (10 ki tu)
	unsigned int NIENKHOA;
	int HOCKY;
	unsigned int SVMAX;
	dssv *sv = NULL;
};
typedef struct dsloptinchi dsltc;

struct nodett { // danh sach lop tin chi la mang con tro ( node tuyen tinh )
	int n=0; 
	dsltc nodett[MAX];
};
typedef struct nodett *NODETT;	// NODETT p=new nodett[MAX] 

int Emptytt (NODETT &ds) {
	return ds->n == 0;
}

int Fulltt (NODETT ds) {
	return ds->n == MAX;
}

//int Insert_item (NODETT &ds, int i, dsltc *list) {
//	int j;
//	if (i < 0 || i > ds->n || Fulltt(ds)) {
//		return 0;
//	}
//	for (j = ds->n - 1; j >= i; j-- ) {
//		ds->nodett[j+1] = ds->nodett[j];
//	}
//	ds->nodett[i] = list;
//	ds->n++;
//	return 1;
//}

int FindSpace(dsltc &ltc); // ham tim khoang trang
int Search (NODETT &ds, char MALOP[10]); // ham tim Ma lop tin chi da co
int SearchMALOPTC(NODETT &ds, unsigned int temp);
void gotoxy(int x, int y); 
int CreateLopTinChi (NODETT &ds); // ham tao lop tin chi
void ShowData(NODETT &ds); // ham xuat danh sach lop tin chi
void DocFile (NODETT &ds);
void GhiFile (dsltc &ltc);
unsigned int Random();



