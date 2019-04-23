#include "loptinchi.h"
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
	char MH[10],NK[10],HK[10],SVM[200];
	fflush(stdin);
	do {
		ds.nodett[ds.n] = new dsltc;
		XoaManHinh();
		char buff [33];		
		cout << "\nNhap Ma Mon Hoc (nhap q hoac 0 de thoat): ";
		fflush(stdin);
		gets(MH);
		if (stricmp(MH,"q") == 0) {
			break;
		}
		if (strcmp(MH,itoa(0,buff,10))==0) {
			break;
		}
		if (strlen(MH)==0 || atoi(MH) > 0 || atoi(MH) < 0 || Find_Space(MH) == 0) {
			cout<< "\nKhong hop le, nhap lai";
			delete ds.nodett[ds.n];
			ds.n--;
			getch();
			continue;
		}
		if (Search_MAMONHOC(ds,MH) == 1) {
			cout << "\nMa mon hoc da co, vui long nhap lai: ";
			getch();
			continue;
		}
		strcpy(ds.nodett[ds.n]->MAMH,strupr(MH));
		
		do {
			XoaManHinh();
			cout << "\nNhap Nien Khoa: ";
			fflush(stdin);
			gets(NK);
		} while (strlen(NK)==0 || NumberOnly(NK) == 0);
		ds.nodett[ds.n]->NIENKHOA = atoi(NK);
		do {
			XoaManHinh();
			cout << "\nNhap hoc ki bat dau: ";
			fflush(stdin);
			gets(HK);
		} while (strlen(HK)==0 || NumberOnly(HK) == 0);
		ds.nodett[ds.n]->HOCKY = atoi(HK);
		do {
			XoaManHinh();
			cout << "\nNhap So Sinh Vien Toi Da: ";
			fflush(stdin);
			gets(SVM);
		} while (strlen(SVM)==0 || NumberOnly(SVM) == 0);
		ds.nodett[ds.n]->SVMAX = atoi (SVM);
		do {		
				temp = Random();		
		} while(Search_MALOPTC(ds,temp) == 1);
		ds.nodett[ds.n]->MALOPTC = temp;	
		ds.n++;
	} while (ds.n <= MAX);
}

void Show_Data_LTC(NODETT &ds) { // ham show du lieu
	XoaManHinh();
	gotoxy(45,1);
	cout<<"DANH SACH CAC LOP TIN CHI";
	gotoxy(14,3);
	cout << "STT ";
	gotoxy(26,3);
	cout << "MALOPTC";
	gotoxy(42,3); 
	cout << "MA MH"; 
	gotoxy(56,3);
	cout << "NIEN KHOA"; 
	gotoxy(74,3);
	cout << "HOC KY";
	gotoxy(89,3);  
	cout << "SO SVMAX";
	for (int i=0;i<=88;i++) { // ve line phia tren
		gotoxy(i+11,0);
		cout <<"=";
	}
	for (int i=0;i<=88;i++) { //ve line phia duoi
		gotoxy(i+11,ds.n + 5);
		cout <<"=";
	}
	for (int i=0;i<ds.n + 4;i++) { // ve line ben trai
		gotoxy(11,i+1);
		cout <<"//"<<"\n";
	}
	for (int i=0;i<ds.n + 4;i++) { // ve line ben phai
		gotoxy(98,i+1);
		cout <<"//"<<"\n";
	}
	for (int i=0;i<ds.n;i++) { // in ra data
		gotoxy(15,i+4);
		cout << i+1;
		gotoxy(28,i+4);
		cout << ds.nodett[i]->MALOPTC;
		gotoxy(42,i+4);
		cout << ds.nodett[i]->MAMH;
		gotoxy(58,i+4);
		cout << ds.nodett[i]->NIENKHOA;
		gotoxy(76,i+4);
		cout << ds.nodett[i]->HOCKY;
		gotoxy(91,i+4);
		cout << ds.nodett[i]->SVMAX;
		cout << endl;
	}
	gotoxy(0,ds.n + 6);
	cout << " ";
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
	ofstream fileout("loptinchi.txt",ios_base::out);
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
			return TRUE;
		}
	}
	return FALSE;
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
	} else {
		cout << "\nKhong Tim Thay Ma Lop Tin Chi, nhap lai";
		getch();
	}
	
}

