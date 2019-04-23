#pragma once
#include "svanddk.h"
#define TRUE 1
#define FALSE 0


struct dsmonhoc { // cau truc danh sach mon hoc
	char MAMH[10]; //ma mon hoc bat dau bang so 2 (10 ki tu)
	char TENMH[50]; // ten mon hoc
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
int EmptyTree (PTR_NODETREE ds);
void Insert_Node_Tree(PTR_NODETREE &ds, dsmh mh);
dsmh Input_Tree (PTR_NODETREE &ds);
void Show_Tree (PTR_NODETREE ds);
void CreatTree_Dsmh(PTR_NODETREE &ds, dsmh mh);
NODETREE* FindMin(PTR_NODETREE ds);
void Find_Node_Temp(PTR_NODETREE &x , PTR_NODETREE &y);
void RemoveTree (PTR_NODETREE &ds, dsmh mh);
void Inorder(PTR_NODETREE p);
void Preorder(PTR_NODETREE p);
void Posorder(PTR_NODETREE p);
void DocFile_MH(PTR_NODETREE &ds);
