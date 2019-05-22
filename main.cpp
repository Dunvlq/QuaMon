#include "menu.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;


int main () {
	TextColor(128);
	resizeConsole(1920,1080); 
	
	PTR_NODETREE ds;
	dsmh *mh=new dsmh;
	InitializeTree(ds);
	DocFile_MH(ds);
//	Menu();
//	Inorder(ds);
//	DrawScreen();
	Draw_MH(ds);
	Show_Tree(ds,mh);
	getch();
	XoaManHinh();
//	CreatTree_Dsmh(ds,mh);
//	int i=0;
//	dsmh mh;
//	InitializeTree(ds);
	
	
//	getch();
//	Inorder(ds);
//	GhiFile_MH(ds);
// ================================
//	NODETT ds;
//	DocFile_LTC(ds);
//	Show_Data_LTC(ds);
//	getch();
//	Create_LopTinChi(ds);
//	Show_Data_LTC(ds);

}
