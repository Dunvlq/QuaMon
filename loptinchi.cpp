#pragma once
#include <iostream>
#include <fstream>
#include <string.h>
#include <conio.h>
#include "Graphic.h"
#include <time.h>
#include "loptinchi.h"
#include <windows.h>
#define MAX 100
#include <math.h>
using namespace std;

int FindSpace(dsltc &ltc) { //ham tim khoang trang
	NODETT ds;
	for (int i=0;i<strlen(ltc.MAMH);i++) {
		if (ltc.MAMH[i] == ' ') {
			return FALSE;
		}
	}
	return TRUE;
}

int Search (NODETT &ds, char MALOP[10]) { // ham kiem tra ma mon hoc co ton tai hay chua
	for (int i=0;i<ds->n;i++) {
		if (stricmp(ds->nodett[i].MAMH,MALOP)==0) {
			return FALSE;
		}
	}
	return TRUE;
}

int SearchMALOPTC (NODETT &ds, unsigned int temp) { // ham kiem tra ma lop tin chi co ton tai hay chua
	for (int i=0;i<ds->n;i++) {
		if (ds->nodett[i].MALOPTC == temp) {
			return FALSE;
		}
	}
	return TRUE;
}

int CreateLopTinChi (NODETT &ds) { //ham them nhieu lop tin chi
	ofstream fout;
	unsigned int temp;
	dsltc ltc;
	char MALOP[10],MH[10],NK[10],HK[10],SVM[200];
	fflush(stdin);
	if (Fulltt(ds)) {
		cout << "Danh sach da day khong the them."<<endl;
	}
	do {
		
		ClearScreen();
		char buff [33];		
		cout << "\nNhap Ma Mon Hoc (nhap q hoac 0 de thoat): ";
		fflush(stdin);
		gets(MH);
		if (stricmp(MH,"q") == 0) {
			cout << "\nThoat.";
			break;
		}
		if (strcmp(MH,itoa(0,buff,10))==0) {
				break;
		}
		if (strlen(MH)==0 || atoi(MH) > 0 || atoi(MH) < 0 || FindSpace(ltc) == 0) {
			continue;
		}
		if (Search(ds,MH) == 0) {
			cout << "\nMa mon hoc da co, vui long nhap lai: ";
			system("pause");
			continue;
		}
		strcpy(ltc.MAMH,strupr(MH));
		
		do {
			ClearScreen();
			cout << "\nNhap Nien Khoa: ";
			fflush(stdin);
			gets(NK);
		} while (strlen(NK)==0 || atoi(NK)<=0);
		ltc.NIENKHOA = atoi(NK);
		do {
			ClearScreen();
			cout << "\nNhap hoc ki bat dau: ";
			fflush(stdin);
			gets(HK);
		} while (strlen(HK)==0 || atoi(HK)<=0);
		ltc.HOCKY = atoi(HK);
		do {
			ClearScreen();
			cout << "\nNhap So Sinh Vien Toi Da: ";
			fflush(stdin);
			gets(SVM);
		} while (strlen(SVM)==0 || atoi(SVM)<=0);
		ltc.SVMAX = atoi (SVM);
		do {		
				temp = Random();		
		} while(SearchMALOPTC(ds,temp) == 0);
		ltc.MALOPTC = temp;	
		ds->nodett[ds->n++] = ltc;
		GhiFile(ltc);
	} while (ds->n < MAX);
	return 0;	
}

void ShowData(NODETT &ds) {
	ClearScreen();
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
		gotoxy(i+11,ds->n + 5);
		cout <<"=";
	}
	for (int i=0;i<ds->n + 4;i++) { // ve line ben trai
		gotoxy(11,i+1);
		cout <<"//"<<"\n";
	}
	for (int i=0;i<ds->n + 4;i++) { // ve line ben phai
		gotoxy(98,i+1);
		cout <<"//"<<"\n";
	}
	for (int i=0;i<ds->n;i++) { // in ra data
		gotoxy(15,i+4);
		cout << i+1;
		gotoxy(28,i+4);
		cout << ds->nodett[i].MALOPTC;
		gotoxy(42,i+4);
		cout << ds->nodett[i].MAMH;
		gotoxy(58,i+4);
		cout << ds->nodett[i].NIENKHOA;
		gotoxy(76,i+4);
		cout << ds->nodett[i].HOCKY;
		gotoxy(91,i+4);
		cout << ds->nodett[i].SVMAX;
		cout << endl;
	}
	gotoxy(0,ds->n + 6);
	cout << " ";
}

void DocFile (NODETT &ds) {
	dsltc ltc;
	ifstream fin("loptinchi.txt",ios_base::in);
	if (fin.fail() == TRUE) {
		cout << "\nFile khong ton tai.";
		system("pause");
	}
	do {
		fin>>ltc.MALOPTC;
		fin>>ltc.MAMH;
		fin>>ltc.NIENKHOA;
		fin>>ltc.HOCKY;
		fin>>ltc.SVMAX;
		if(fin==NULL) {
        	break;
    	}
		ds->nodett[ds->n++] = ltc;
	} while (!fin.eof());
	fin.close();
}

void GhiFile (dsltc &ltc) {
	ofstream fout("loptinchi.txt",ios_base::out | ios_base::app);
	fout << "\n" << ltc.MALOPTC << "\n";
	fout << ltc.MAMH << "\n";
	fout << ltc.NIENKHOA << "\n";
	fout << ltc.HOCKY << "\n";
	fout << ltc.SVMAX;
	fout.close();
}

unsigned int Random()
{	
	unsigned int a;
	srand(time(0));
	for( int i = 1; i < 1000; i++)
	{
		a = rand() % 900 + 100;	
	} 	
    return a;
}

int main()
{
	NODETT ds = new nodett[MAX];
	DocFile(ds);
	CreateLopTinChi(ds);
	ShowData(ds);
//	system("pause");
	return 0;
}

