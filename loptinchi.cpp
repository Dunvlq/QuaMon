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

int Create_LopTinChi (NODETT &ds) { //ham them nhieu lop tin chi
	unsigned int temp;
	int max = 10;
	ds.nodett[ds.n] = new dsltc;
	char MH[10],NK[10],HK[10],SVM[200];
	int a=0;
	for (int i=3;i<=165;i++) {
		gotoxy(i,2);
		cout << " ";
	}
	for (int i=3;i<=165;i++) {
		gotoxy(i,39);
		cout << " ";
	}
	TextColor(138);
	gotoxy(76,2);
	cout << "THEM LOP TIN CHI";
	TextColor(DEN);
	do {
		Clearmen();
		a=0;
		DrawBox(63,19,43,2);
		gotoxy(65,19);
		cout << "Nhap Ma Mon Hoc:";
		fflush(stdin);
		gotoxy(65,20);
		InputString(MH,max);
		if (strlen(MH) == 0) {
			gotoxy(65,20);
			cout<< "                                 ";
			gotoxy(65,20);
			cout << "khong duoc de trong:";
			a = 1;
			getch();
		}
		if (Search_MAMONHOC(ds,MH) == 1) {
			gotoxy(65,20);
			cout<< "                                 ";
			gotoxy(65,20);
			cout << "ma mon hoc da co, nhap lai!";
			a = 1;
			getch();
		}
	} while (a==1);
	strcpy(ds.nodett[ds.n]->MAMH,strupr(MH));
	do {
		Clearmen();
		DrawBox(63,19,43,2);
		a=0;	
		gotoxy(65,19);
		cout << "Nhap Nien Khoa: ";
		fflush(stdin);
		gotoxy(65,20);
		InputNumber(NK,max);
		if (strlen(NK)==0) {
			gotoxy(65,20);
			cout<< "                                 ";
			gotoxy(65,20);
			cout << "khong duoc de trong:";
			a = 1;
			getch();
		}
	} while (a == 1);
	ds.nodett[ds.n]->NIENKHOA = atoi(NK);
	do {
		Clearmen();
		DrawBox(63,19,43,2);
		gotoxy(65,19);
		a=0;
		cout << "Nhap hoc ki bat dau: ";
		fflush(stdin);
		gotoxy(65,20);
		InputNumber(HK,max);
		if (strlen(HK)==0) {
			gotoxy(65,20);
			cout<< "                                 ";
			gotoxy(65,20);
			cout << "khong duoc de trong:";
			a = 1;
			getch();
		}
	} while (a==1);
	ds.nodett[ds.n]->HOCKY = atoi(HK);
	do {
		Clearmen();
		DrawBox(63,19,43,2);
		a=0;
		gotoxy(65,19);
		cout << "Nhap So Sinh Vien Toi Da:";
		fflush(stdin);
		gotoxy(65,20);
		InputNumber(SVM,max);
		if (strlen(SVM)==0) {
			gotoxy(65,20);
			cout<< "                                 ";
			gotoxy(65,20);
			cout << "khong duoc de trong:";
			a = 1;
			getch();
		}
	} while (a==1);
	ds.nodett[ds.n]->SVMAX = atoi (SVM);
	do {		
			temp = Random();		
	} while(Search_MALOPTC(ds,temp) == 1);
	ds.nodett[ds.n]->MALOPTC = temp;	
	ds.n++;
}

void Show_Data_LTC(NODETT &ds,int i) { // ham show du lieu
	int j=0;
	for (i;i<ds.n;i++) { // in ra data
		gotoxy(14,j+5);
		cout << i+1;
		gotoxy(41,j+5);
		cout << ds.nodett[i]->MALOPTC;
		gotoxy(67,j+5);
		cout << ds.nodett[i]->MAMH;
		gotoxy(96,j+5);
		cout << ds.nodett[i]->NIENKHOA;
		gotoxy(125,j+5);
		cout << ds.nodett[i]->HOCKY;
		gotoxy(152,j+5);
		cout << ds.nodett[i]->SVMAX;
		j++;
		if (j==33) {
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
		cout << "\nChua co lop tin chi";
		getch();
	}
	a = TraverseCHAR(ds,MAMONHOC); 
	if (Search_MAMONHOC(ds,MAMONHOC) == 1) {
		for (a;a<ds.n;a++) {
			ds.nodett[a-1] = ds.nodett[a];
		}
		ds.n--;

		gotoxy(66,20);
		cout << "Thanh cong!";
		getch();
	} else {

		gotoxy(66,20);
		cout << "Khong Tim Thay Ma Lop Tin Chi";
		getch();
	}
	
}

