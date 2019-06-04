#include "loptinchi.h"
#include "menu.h"
using namespace std;

int Emptytt (NODETT &ds) {
	if (ds.n == 0) 
		return TRUE;
	else return FALSE;	
}

int Fulltt (NODETT ds) {
	if (ds.n == MAX) 
		return TRUE;
	else return FALSE;
}

void initializeTT(NODETT &ds) {
	ds.n=0;
}

int Search_MAMONHOC (NODETT &ds, char MAMONHOC[10]) { // ham kiem tra ma mon hoc co ton tai hay chua
	for (int i=0;i<ds.n;i++) {
		if (stricmp(ds.nodett[i]->MAMH,MAMONHOC)==0) {
			return TRUE;
		}
	}
	return FALSE;
}

int Search_MALOPTC (NODETT &ds, unsigned int temp) { // ham kiem tra ma lop tin chi co ton tai hay chua
	for (int i=0;i<ds.n;i++) {
		if (ds.nodett[i]->MALOPTC == temp) {
			return TRUE;
		}
	}
	return FALSE;
}

int Search_NIENKHOA(NODETT &ds, unsigned int temp) {
	for (int i=0;i<ds.n;i++) {
		if (ds.nodett[i]->NIENKHOA == temp) {
			return TRUE;
		}
	}
	return FALSE;
}

int Search_HOCKY(NODETT &ds, unsigned int temp) {
	for (int i=0;i<ds.n;i++) {
		if (ds.nodett[i]->HOCKY == temp) {
			return TRUE;
		}
	}
	return FALSE;
}

int Search_SVMAX(NODETT &ds, unsigned int temp) {
	for (int i=0;i<ds.n;i++) {
		if (ds.nodett[i]->SVMAX == temp) {
			return TRUE;
		}
	}
	return FALSE;
}

void InputLTC(NODETT &ds) {
	
}

void Create_LopTinChi (NODETT &ds) { //ham them nhieu lop tin chi
	unsigned int temp;
	int max = 10;
	ds.nodett[ds.n] = new dsltc;
	char MH[11],NK[11],HK[11],N[11],SVM[11];
	int a=0;
	int exit=0;
	int thaotac=0;
	TextColor(DEN);
	do {
		gotoxy(123,6);
		cout<< "                                 ";
		a=0;
		DrawBox(121,5,43,2);
		gotoxy(123,5);
		cout << "Nhap Ma Mon Hoc:";
		fflush(stdin);
		gotoxy(123,6);
		InputString(MH,max);
		if (strlen(MH) == 0) {
			gotoxy(123,6);
			cout<< "                                 ";
			gotoxy(123,6);
			cout << "khong duoc de trong:";
			a = 1;
			getch();
		}
	} while (a==1);
	
	do {
		gotoxy(123,10);
		cout<< "                                 ";
		DrawBox(121,9,43,2);
		a=0;	
		gotoxy(123,9);
		cout << "Nhap Nien Khoa:";
		fflush(stdin);
		gotoxy(123,10);
		InputNumber(NK,max);
		if (strlen(NK)==0) {
			gotoxy(123,10);
			cout<< "                                 ";
			gotoxy(123,10);
			cout << "khong duoc de trong:";
			a = 1;
			getch();
		}
	} while (a == 1);
	
	do {
		gotoxy(123,14);
		cout<< "                                 ";
		DrawBox(121,13,43,2);
		gotoxy(123,13);
		a=0;
		cout << "Nhap hoc ki bat dau:";
		fflush(stdin);
		gotoxy(123,14);
		InputNumber(HK,max);
		if (strlen(HK)==0) {
			gotoxy(123,14);
			cout<< "                                 ";
			gotoxy(123,14);
			cout << "khong duoc de trong:";
			a = 1;
			getch();
		}
	} while (a==1);
	do {
		gotoxy(123,18);
		cout<< "                                 ";
		DrawBox(121,17,43,2);
		gotoxy(123,17);
		a=0;
		cout << "Nhap nhom:";
		fflush(stdin);
		gotoxy(123,18);
		InputNumber(N,max);
		if (strlen(N)==0) {
			gotoxy(123,18);
			cout<< "                                 ";
			gotoxy(123,18);
			cout << "khong duoc de trong:";
			a = 1;
			getch();
		}
	} while (a==1);
	
	do {
		gotoxy(123,22);
		cout<< "                                 ";
		DrawBox(121,21,43,2);
		a=0;
		gotoxy(123,21);
		cout << "Nhap So Sinh Vien Toi Da:";
		fflush(stdin);
		gotoxy(123,22);
		InputNumber(SVM,max);
		if (strlen(SVM)==0) {
			gotoxy(123,22);
			cout<< "                                 ";
			gotoxy(123,22);
			cout << "khong duoc de trong:";
			a = 1;
			getch();
		}
	} while (a==1);
	
	do {		
			temp = Random();		
	} while(Search_MALOPTC(ds,temp) == 1);
	DrawBox(131,25,23,2);
	gotoxy(139,25);
	cout << "LUU LAI";
	gotoxy(135,26);
	cout << "CO";
	gotoxy(147,26);
	cout << "KHONG";
	gotoxy(135,26);
	//hight light co
	TextColor(140);
	cout << "CO";
	TextColor(DEN);
	while (exit == 0) {
		char key;
		key = getch();
		if (key == Left) {
			gotoxy(135,26);
			TextColor(140);
			cout << "CO";
			if (thaotac == 0)
				thaotac = 2 - 1;
			else thaotac--;	
			gotoxy(147,26);
			TextColor(DEN);
			cout << "KHONG";
		}
		else if (key == Right) {
			gotoxy(147,26);
			TextColor(140);
			cout << "KHONG";
			if (thaotac == 2 - 1)
				thaotac = 0;
			else thaotac++;
			gotoxy(135,26);
			TextColor(DEN);
			cout << "CO";
		}
		else if (key == ESC) {
			exit = 1;
		}
		else if (key == ENTER) {
			if (thaotac == 0) {
				strcpy(ds.nodett[ds.n]->MAMH,strupr(MH));
				ds.nodett[ds.n]->NIENKHOA = atoi(NK);
				ds.nodett[ds.n]->HOCKY = atoi(HK);
				ds.nodett[ds.n]->NHOM = atoi(N);
				ds.nodett[ds.n]->SVMAX = atoi (SVM);
				ds.nodett[ds.n]->MALOPTC = temp;	
				ds.n++;
				return;
			}
			else if (thaotac == 1 ) {
				return;
			}
		}	
	}	
}

void Fix_Data_LTC(NODETT &ds,int j, int k) {
	int max = 10,max1 = 4;
	int exit=0;
	int thaotac=0;
	int soitem = 5;
	char mh[11],nk[11],hk[11],n[11],svm[11];
	ClearSignalLTC(j + 7);
	ChoiceDataLTC(thaotac,j+7);
	while (1) {
		char key1;
		key1 = getch();
		if (key1 == Left)
		{
			thaotac--;
			if (thaotac<=0) {
				thaotac=0;
			} 
			ClearSignalLTC(j+7);
			ChoiceDataLTC(thaotac,j+7);
		}
		else if (key1 == Right)
		{
			thaotac++;
			if (thaotac > 4) {
				thaotac = 4;
			}
			ClearSignalLTC(j+7);
			ChoiceDataLTC(thaotac,j+7);
		}
		else if (key1 == ESC)
		{
			break;
		}
		else if (key1 == ENTER) {
			if (thaotac==0) {
				int o=0;
				do {
					o=0;
					ClearSignalLTC(j + 7);
					gotoxy(34,j+7);
					cout << "            ";
					gotoxy(34,j+7);
					InputString(mh,max);
					if (strlen(mh)==0) {
						o=1;
					}
					ChoiceDataLTC(thaotac,j+7);
				} while (o==1);
				strcpy(ds.nodett[k+j]->MAMH,mh);
			}
			if (thaotac==1) {
				int o=0;
				do {
					o=0;
					ClearSignalLTC(j + 7);
					gotoxy(55,j+7);
					cout << "           ";
					gotoxy(55,j+7);
					InputNumber(nk,max);
					if (strlen(nk)==0) {
						o=1;
					}
					ChoiceDataLTC(thaotac,j+7);
				} while (o==1);
				ds.nodett[k+j]->NIENKHOA = atoi(nk);
			}
			if (thaotac==2) {
				int o=0;
				do {
					o=0;
					ClearSignalLTC(j + 7);
					gotoxy(70,j+7);
					cout << "      ";
					gotoxy(70,j+7);
					InputNumber(hk,max1);
					if (strlen(nk)==0) {
						o=1;
					}
					ChoiceDataLTC(thaotac,j+7);
				} while (o==1);
				ds.nodett[k+j]->HOCKY = atoi(hk);
			}
			if (thaotac==3) {
				int o=0;
				do {
					o=0;
					ClearSignalLTC(j + 7);
					gotoxy(80,j+7);
					cout << "      ";
					gotoxy(80,j+7);
					InputNumber(n,max1);
					if (strlen(n)==0) {
						o=1;
					}
					ChoiceDataLTC(thaotac,j+7);
				} while (o==1);
				ds.nodett[k+j]->NHOM = atoi(n);
			}
			if (thaotac==4) {
				int o=0;
				do {
					o=0;
					ClearSignalLTC(j + 7);
					gotoxy(92,j+7);
					cout << "    ";
					gotoxy(92,j+7);
					InputNumber(svm,max1);
					if (strlen(nk)==0) {
						o=1;
					}
					ChoiceDataLTC(thaotac,j+7);
				} while (o==1);
				ds.nodett[k+j]->SVMAX = atoi (svm);	
			}
		}
	}
	ClearChoice();
	// ve khung yes no
//	DrawBox(131,21,23,2);
//	gotoxy(139,21);
//	cout << "LUU LAI";
//	gotoxy(135,22);
//	cout << "CO";
//	gotoxy(147,22);
//	cout << "KHONG";
//	gotoxy(135,22);
//	//hight light co
//	TextColor(140);
//	cout << "CO";
//	TextColor(DEN);
//	while (exit == 0) {
//		char key;
//		key = getch();
//		if (key == Left) {
//			gotoxy(135,22);
//			TextColor(140);
//			cout << "CO";
//			if (thaotac == 0)
//				thaotac = 2 - 1;
//			else thaotac--;	
//			gotoxy(147,22);
//			TextColor(DEN);
//			cout << "KHONG";
//		}
//		else if (key == Right) {
//			gotoxy(147,22);
//			TextColor(140);
//			cout << "KHONG";
//			if (thaotac == 2 - 1)
//				thaotac = 0;
//			else thaotac++;
//			gotoxy(135,22);
//			TextColor(DEN);
//			cout << "CO";
//		}
//		else if (key == ESC) {
//			exit = 1;
//		}
//		else if (key == ENTER) {
//			if (thaotac == 0) {
//				strcpy(ds.nodett[k+j]->MAMH,mh);
//				ds.nodett[k+j]->NIENKHOA = atoi(nk);
//				ds.nodett[k+j]->HOCKY = atoi(hk);
//				ds.nodett[k+j]->SVMAX = atoi (svm);	
//				ClearChoice();
//				exit = 1;
//			}
//			else if (thaotac == 1 ) {
//				ClearChoice();
//				exit = 1;
//			}
//		}	
//	}
//	ClearChoice();
}

void Show_Data_LTC(NODETT &ds,int i) { // ham show du lieu
	int j=0;
	for (i;i<ds.n;i++) { // in ra data
		gotoxy(7,j+7);
		cout << i+1;
		gotoxy(18,j+7);
		cout << ds.nodett[i]->MALOPTC;
		gotoxy(34,j+7);
		cout << ds.nodett[i]->MAMH;
		gotoxy(55,j+7);
		cout << ds.nodett[i]->NIENKHOA;
		gotoxy(70,j+7);
		cout << ds.nodett[i]->HOCKY;
		gotoxy(80,j+7);
		cout << ds.nodett[i]->NHOM;
		gotoxy(92,j+7);
		cout << ds.nodett[i]->SVMAX;
		j++;
		if (j==30) {
			break; 
		}
	}
}

void DocFile_LTC (NODETT &ds) { // load du lieu tu file vao bo nho
	dsltc ltc;
	fstream filein("loptinchi.txt",ios_base::in);
	if (filein.fail() == TRUE) {
		cout << "\nFile khong ton tai.";
		getch();
		return;
	}
	do {
		ds.nodett[ds.n] = new dsltc;
		filein>>ds.nodett[ds.n]->MALOPTC;
		filein>>ds.nodett[ds.n]->MAMH;
		filein>>ds.nodett[ds.n]->NIENKHOA;
		filein>>ds.nodett[ds.n]->HOCKY;
		filein>>ds.nodett[ds.n]->NHOM;
		filein>>ds.nodett[ds.n]->SVMAX;
		ds.n++;
		if(filein == NULL) {
        	break;
    	}
		
	} while (!filein.eof());
	filein.close();
}

void GhiFile_LTC(NODETT &ds) { // ghi du lieu tu bo nho vao file 
	ofstream fileout("loptinchi.txt",ios::out);
	for (int i=0;i<ds.n;i++) {
		fileout << "\n";
		fileout << ds.nodett[i]->MALOPTC << "\n";
		fileout << ds.nodett[i]->MAMH << "\n";
		fileout << ds.nodett[i]->NIENKHOA << "\n";
		fileout << ds.nodett[i]->HOCKY << "\n";
		fileout << ds.nodett[i]->NHOM << "\n";
		fileout << ds.nodett[i]->SVMAX;
	}
	fileout.close();
}

unsigned int Random() {	// ham tao ngau nhien so tu 100 -> 999
	unsigned int a;
	srand(time(0));
	for( int i = 1; i < 1000; i++)
	{
		a = rand() % 900 + 100;	
	} 	
    return a;
}

int TraverseINT (NODETT &ds,unsigned int temp) { // tra ve vi tri temp trong danh sach
	for (int i=0;i<ds.n;i++) {
		if (ds.nodett[i]->MALOPTC == temp) {
			return i+1;
		}
	}
	return 0;
}

int TraverseCHAR (NODETT &ds,char MAMONHOC[10]) { // tra ve vi tri temp trong danh sach
	for (int i=0;i<ds.n;i++) {
		if (stricmp(ds.nodett[i]->MAMH,MAMONHOC)==0) {
			return i+1;
		}
	}
	return 0;
}

void Delete_LTC_MALOPTC(NODETT &ds, unsigned int temp) { //xoa nodes theo ma lop tin chi trong bo nho
	int a;
	
	if (Emptytt(ds)) {
		cout << "\nChua co lop tin chi";
		getch();
	} else {
		a = TraverseINT(ds,temp); 
		if (Search_MALOPTC(ds,temp) == 1) {
			for (a;a<ds.n;a++) {
				ds.nodett[a-1] = ds.nodett[a];
			}
			ds.n--;
		} else {
			cout << "\nKhong Tim Thay Ma Lop Tin Chi!";
			getch();
		}
	}
}

void Delete_LTC_MAMONHOC(NODETT &ds, char MAMONHOC[10]) { //xoa nodes theo ma lop tin chi trong bo nho
	int a;
	if (Emptytt(ds)) {
		gotoxy(116,21);
		cout << "Chua co lop tin chi";
		getch();
	}
	a = TraverseCHAR(ds,MAMONHOC); 
	if (Search_MAMONHOC(ds,MAMONHOC) == 1) {
		for (a;a<ds.n;a++) {
			ds.nodett[a-1] = ds.nodett[a];
		}
		ds.n--;
		gotoxy(116,21);
		cout << "Thanh cong!";
		getch();
	} else {

		gotoxy(116,21);
		cout << "Khong Tim Thay Ma Lop Tin Chi";
		getch();
	}
}

void DeleteALL(NODETT &ds) {
	for (int i=ds.n;i>=1;i--) {
		ds.n--;
		ds.nodett[i-1] = ds.nodett[i];
		
	}
}

