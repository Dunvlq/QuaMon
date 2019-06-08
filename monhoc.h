#pragma once
#include "svanddk.h"
#define TRUE 1
#define FALSE 0


struct dsmonhoc { // cau truc danh sach mon hoc
	char MAMH[12]; //ma mon hoc bat dau bang so 2 (10 ki tu)
	char TENMH[52]; // ten mon hoc
	int STCLT; // so tin chi ly thuyet
	int STCTH; // so tin chi thuc hanh
};
typedef struct dsmonhoc dsmh; 

struct nodetree { // cay nhi phan tim kiem
	dsmh monhoc; // du lieu la cau truc danh sach mon hoc
	struct nodetree *LEFT; // cay con ben trai
	struct nodetree *RIGHT; // cay con ben phai
	
};
typedef struct nodetree NODETREE;
typedef NODETREE* PTR_NODETREE;

void InitializeTree(PTR_NODETREE &root);
bool Isempty (PTR_NODETREE ds);
int Compare(dsmh x,dsmh y);
void Insert_Node_Tree(PTR_NODETREE &ds,dsmh mh);
dsmh Input_Tree (PTR_NODETREE &ds);
void Show_Tree (PTR_NODETREE ds,int k);
void Fix_Data_MH(PTR_NODETREE &ds,int j, int k);
void Inorder(PTR_NODETREE p);
NODETREE* FindMin(PTR_NODETREE ds);
void RemoveTree (PTR_NODETREE &ds, dsmh mh);
void DeleteNode(PTR_NODETREE &ds, dsmh mh);
void DocFile_MH(PTR_NODETREE &ds);
void GhiFile_MH(PTR_NODETREE &ds);
int CountNode(PTR_NODETREE &t);
PTR_NODETREE Search_MaMonHoc(PTR_NODETREE ds, char *mh);
bool Check_MaMonHoc(PTR_NODETREE ds, char *mh);
bool Check_TenMonHoc(PTR_NODETREE ds, char *mh);
void Sort(dsmh *a[500],int q, int r);


