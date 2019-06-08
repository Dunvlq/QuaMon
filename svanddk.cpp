#pragma once
#include "svanddk.h"
using namespace std;

void tao_list(LISTSV &l) //khoi tao dskld
{
	l.FIRSTSV=l.LASTSV=NULL; 
	
}


NODESV* KhoitaoNodeSV(DSSV ds) {
	NODESV *p=new NODESV; // cap phat vung nho cho node p
	if(p==NULL){
		cout<<"\n khong du vung nho de cap phat";
		return NULL;
	} 
	
	p->SINHVIEN=ds;
	p->next=NULL;
	return p; 			//tra ve gia tri p vua khoi tao.
}

void add_last(LISTSV &l, NODESV *p) {
	if(l.FIRSTSV==NULL)
	{
		l.LASTSV=l.FIRSTSV=p;//node dau cung la node cuoi va la p.
	}
	else
	{
		l.LASTSV->next=p;
		l.LASTSV=p;
	}
}

int Empty(LISTSV &l){
	return(l.FIRSTSV==l.LASTSV==NULL ? 1 : 0);
}

int ktmasv(LISTSV l,char s[]){ //kiem tra ma sinh vien da co chua

	for(NODESV *p=l.FIRSTSV; p!=NULL;p=p->next){
		
		if(strcmp(p->SINHVIEN.MASV,s)==0) return 1;
	}
	return 0;
}

char* chuyenstringquachar(string str){
	int lenght=str.length();
	char* temp;
	temp=new char[lenght];
	for(int i=0;i<=lenght;i++){
		temp[i]=str[i];
	}
	temp[lenght]='\0';
	return temp;
}

void Giai_Phong_Vung_Nho(LISTSV &l) //hàm giai phóng vùng nho cho danh sách liên ket don
{
	NODESV *p = NULL;
	while (l.FIRSTSV != NULL)
	{
		p = l.FIRSTSV;
		l.FIRSTSV= l.FIRSTSV->next;
		delete p;
	}
}

void Ghi_File_1SV(DSSV &ds) // hàm ghi thông tin 1 sinh viên vào file
{
	ofstream fileout("DSSV.txt",ios::out | ios::app);
	fileout << ds.MALOP << "\t";
	fileout << ds.MASV << "\t";
	fileout << ds.HO <<"\t";
	fileout<<ds.TEN<<"\t";
	fileout << ds.SEX <<"\t";
	fileout<< ds.SDT <<"\n";
}

void Doc_File(LISTSV &l){ //doc thong tin 1 sv trong file
	ifstream filein("DSSV.txt",ios::in);
	string Ho,Ten,MSV;
	if (filein.fail()){
		cout<<"\nmo file that bai";
		system("pause");
	}
	else
	{
		while(!filein.eof()){
			MSV="";
			NODESV *x;
			x=new nodesinhvien;
			
			filein>>x->SINHVIEN.MALOP;
			filein.ignore(1);
			getline(filein,MSV,'\t');
			getline(filein,Ho,'\t');
			getline(filein,Ten,'\t');
			filein>>x->SINHVIEN.SEX;
			filein>>x->SINHVIEN.SDT;
			if(MSV=="")break;
			
			strcpy(x->SINHVIEN.MASV,chuyenstringquachar(MSV));
			strcpy(x->SINHVIEN.HO,chuyenstringquachar(Ho));
			strcpy(x->SINHVIEN.TEN,chuyenstringquachar(Ten));
			add_last(l,x);
		}
	}
	filein.close();
}

DSSV Nhapsv1lop(LISTSV l,char* ML) //nhap dssv cua 1 lop
{
	DSSV ds;
	char MSV[20], Ho[30], TSV[40], GT[10], PN[20];
	int a=0;
	do{
		a=0;
		cout<<"\n\tnhap ma sinh vien : ";
		fflush(stdin);
		InputString(MSV, 20);
		if(strlen(MSV)==0) {
			strcpy(ds.MASV,MSV);
			cout<<"\t\n Thoat";
			return ds;
		}
		if(Empty(l)==0){
			Doc_File(l);
			if(ktmasv(l, MSV)==1){
			a=1;
			cout<<"\n\tma sinh vien da ton tai, nhap lai: ";
			}	
		}
		
	}
	while(a==1);

	do{
		a=0;
		cout<<"\n\tnhap ho sinh vien: ";
		fflush(stdin);
		InputStringSpace(Ho, 30);
		if(strlen(Ho)==0){
			a=1;
			cout<<"\nkhong duoc de trong, nhap lai: ";
		}
	}
	while(a==1);

	do{
		a=0;
		cout<<"\n\tnhap ten sinh vien: ";
		fflush(stdin);
		InputStringSpace(TSV, 40);
		if(strlen(TSV)==0){
			a=1;
			cout<<"\nkhong duoc de trong, nhap lai: ";
		}
	}
	while(a==1);

	do{
		a=0;
		cout<<"\n\tnhap gioi tinh: ";
		fflush(stdin);
		InputStringSpace(GT,10);
		if(strlen(GT)==0){
			a=1;
			cout<<"\nkhong duoc de trong, nhap lai:";
		}
		if(Find_Space(GT)==FALSE){
			a=1;
			cout<<"\nkhong duoc de dau cach, nhap lai:";
		}
	}
	while(a==1);

	do {	
		a=0;
		cout<<"\n\tnhap so dien thoai: ";
		fflush(stdin);
		InputNumber(PN, 20);
		if(strlen(PN)==0){
			a=1;
			cout<<"\nkhong duoc de trong, nhap lai: ";
		}
	}		
	while(a==1);
	
	cout<<endl;
	
	strcpy(ds.MALOP,ML);
	strcpy(ds.MASV,MSV); 
	strcpy(ds.HO,Ho);
	strcpy(ds.TEN,TSV);
	strcpy(ds.SEX,GT); 
	ds.SDT=atoi(PN);	
	
	Ghi_File_1SV(ds);
	
	return ds;
}

void input(LISTSV &l){
	int n=0;
	char ML[15];
	cout<<"nhap ma lop: ";
	InputString(ML, 15);
	do {
		DSSV ds;
		ds=Nhapsv1lop(l,ML);
		if(strlen(ds.MASV)==0) break;
		nodesinhvien* x=KhoitaoNodeSV(ds);
		add_last(l,x);
		n++;
	}
	while(n<=MAXSV);
}

void xuat(DSSV *arrtemp[],int i,int k){ //ham xuat 1 sinh vien
	int j=0;
	for (k;k<i;k++) { // in ra data
		gotoxy(6,j+7);
		cout << k+1;
		gotoxy(13,j+7);
		cout << arrtemp[k]->MALOP;
		gotoxy(27,j+7);
		cout << arrtemp[k]->MASV;
		gotoxy(42,j+7);
		cout << arrtemp[k]->HO;
		gotoxy(65,j+7);
		cout << arrtemp[k]->TEN;
		gotoxy(75,j+7);
		cout << arrtemp[k]->SEX;
		gotoxy(85,j+7);
		cout << arrtemp[k]->SDT;
		j++;
		if (j==30) {
			break; 
		}
	}
	
}
void output(LISTSV l,int k) // hàm xuat danh sách sinh viên vua nhap
{	
	DSSV *arrtemp[500];
	int j = 0;
	for (NODESV *p = l.FIRSTSV; p != NULL; p = p->next)
	{	
		arrtemp[j] = new DSSV;
		strcpy(arrtemp[j]->MALOP,p->SINHVIEN.MALOP);
		strcpy(arrtemp[j]->MASV,p->SINHVIEN.MASV);
		strcpy(arrtemp[j]->HO,p->SINHVIEN.HO);
		strcpy(arrtemp[j]->TEN,p->SINHVIEN.TEN);
		strcpy(arrtemp[j]->SEX,p->SINHVIEN.SEX);
		arrtemp[j]->SDT = p->SINHVIEN.SDT;
		j++;
	}
	
	xuat(arrtemp,j-1,k);
	
}

void Del_First(LISTSV &l)// hàm xóa dau danh sach
{
	if (l.FIRSTSV == NULL)
	{
		return;
	}
	NODESV *p = l.FIRSTSV; 
	l.FIRSTSV = l.FIRSTSV->next;
	delete p;
}

void Del_Last(LISTSV &l) //ham xoa cuoi danh sach
{
	if (l.FIRSTSV == NULL)
	{
		return;
	}
	
	if (l.FIRSTSV->next == NULL) //truong hop danh sach chi co 1 phan tu
	{
		Del_First(l);
		return;
	}
	
	for (NODESV *k = l.FIRSTSV; k != NULL; k = k->next)
	{
		if (k->next == l.FIRSTSV)
		{
			delete l.LASTSV; 
			k->next = NULL; 
			l.LASTSV = k; 
			return;
		}
	}
}

DSSV Traverse2(DSSV ds, LISTSV l){
	NODESV *p;
	char MSV[20];
	int dem=0;
	cout<<"nhap ma sinh vien can tim: ";
	fflush(stdin);
	gets(MSV);
	Doc_File(l);
	for(NODESV *p=l.FIRSTSV;p!=NULL;p=p->next){
		dem++;
		if(ktmasv(l,MSV)==1){
		//	xuat(p->SV);
			return ds;
		}
	}
}

void clearlist(LISTSV &l) //ham xoa toan bo danh sach
{
	NODESV *p;
	p=l.FIRSTSV;
	while(Empty(l)){
		p=l.FIRSTSV;
		l.FIRSTSV=l.FIRSTSV->next;
		free(p);
	}
}









































































