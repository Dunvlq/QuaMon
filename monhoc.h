#pragma once
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <windows.h> 
#define MAXLOP 30
#define TRUE 1
#define FALSE 0
using namespace std;

struct dsmonhoc { // cau truc danh sach mon hoc
	int MAMH; //ma mon hoc bat dau bang so 2 (10 ki tu)
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
