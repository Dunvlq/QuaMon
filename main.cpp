#include "menu.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;


int main () {
//	TextColor(128);
//	resizeConsole(1920,1080); 
	
	
	PTR_NODETREE ds;
	TEN *arr=new TEN;
	char *t;
	dsmh mh;
	InitializeTree(ds);
	DocFile_MH(ds);
	Inorder(ds);
	while (1) {
		XoaManHinh();
		Inorder(ds);
//		cout << "\nNhap ten:";
//		fflush(stdin);
//		gets(t);
		Search_TenMonHoc(ds,t);
	}
	
//	getch();
//	CreatTree_Dsmh(ds,mh);
//	GhiFile_MH(ds);
// ================================
//	NODETT ds;
//	DocFile_LTC(ds);
//	Show_Data_LTC(ds);
//	getch();
//	Create_LopTinChi(ds);
//	Show_Data_LTC(ds);
	delete arr;
	return 0;
}
