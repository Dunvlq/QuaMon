#include "monhoc.h"
#include "menu.h"


void InitializeTree(PTR_NODETREE &root) {
	root = NULL;
}

bool Isempty (PTR_NODETREE ds) {
	return ds = NULL;
}

int Compare(dsmh x,dsmh y) {
	return stricmp(x.MAMH,y.MAMH);
}

void Insert_Node_Tree(PTR_NODETREE &ds, dsmh mh) {
	if (ds==NULL) {
		NODETREE *p = new NODETREE;
		p->monhoc = mh;
		p->LEFT = NULL;
		p->RIGHT = NULL;
		ds = p;
	} else {
		if (stricmp(mh.MAMH,ds->monhoc.MAMH) < 0) {
			Insert_Node_Tree (ds->LEFT,mh);
		}else if (stricmp(mh.MAMH,ds->monhoc.MAMH) > 0) {
			Insert_Node_Tree (ds->RIGHT,mh);
		}
	}
}

bool Check_MaMonHoc(PTR_NODETREE ds, char *mh) {
	if (ds==NULL) {
		return false;
	} 
	else {
		if (stricmp(Trim(mh),ds->monhoc.MAMH) == 0)
		{
			return true;
		}
		else if (stricmp(Trim(mh),ds->monhoc.MAMH) < 0)
		{
			Search_MaMonHoc(ds->LEFT, mh);
		}
		else if (stricmp(Trim(mh),ds->monhoc.MAMH) > 0 ) 
		{
			Search_MaMonHoc(ds->RIGHT, mh);
		}
	}
}

PTR_NODETREE Search_MaMonHoc(PTR_NODETREE ds, char *mh) { // tim kiem theo key
	if (ds==NULL) {
		return NULL;
	} 
	else {
		if (stricmp(Trim(mh),ds->monhoc.MAMH) == 0)
		{
			return ds;
		}
		else if (stricmp(Trim(mh),ds->monhoc.MAMH) < 0)
		{
			Search_MaMonHoc(ds->LEFT, mh);
		}
		else if (stricmp(Trim(mh),ds->monhoc.MAMH) > 0 ) 
		{
			Search_MaMonHoc(ds->RIGHT, mh);
		}
	}
}

dsmh Input_Tree (PTR_NODETREE &ds) {
	dsmh mh;
	int a=0;
	int h=CountNode(ds);
	char buff[33];
	int maxten = 50;
	int maxma = 10;
	char mmh[11], tmh[51], stclt[11], stcth[11];
	do {
		gotoxy(112,6);
		cout<< "                                        ";
		DrawBox(110,5,54,2);
		a=0;
		gotoxy(112,5);
		cout <<"Nhap Ma mon hoc:";
		fflush(stdin);
		gotoxy(112,6);
		InputString(mmh,maxma);
		if (strlen(mmh)==0) {
			gotoxy(112,6);
			cout<< "                                        ";
			gotoxy(112,6);
			cout << "khong duoc de trong!";
			a = 1;
			getch();
		}
		if (Check_MaMonHoc(ds,mmh)) {
			gotoxy(112,6);
			cout<< "                                        ";
			gotoxy(112,6);
			cout << "Ma mon hoc da co, nhap lai!";
			a = 1;
			getch();
		}
	} while (a == 1);
	do {
		gotoxy(112,10);
		cout<< "                                        ";
		DrawBox(110,9,54,2);
		a = 0;
		gotoxy(112,9);
		cout <<"Nhap ten mon hoc: ";
		fflush(stdin);
		gotoxy(112,10);
		InputStringSpace(tmh,maxten);
		if (strlen(tmh)==0) {
			gotoxy(112,10);
			cout<< "                                        ";
			gotoxy(112,10);
			cout << "khong duoc de trong!";
			a = 1;
			getch();
		}
	} while (a == 1 );
	do {
		gotoxy(112,14);
		cout<< "                                        ";
		DrawBox(110,13,54,2);
		a=0;
		gotoxy(112,13);
		cout <<"Nhap so tin chi ly thuyet: ";
		fflush(stdin);
		gotoxy(112,14);
		InputNumber(stclt,maxma);
		if (strlen(stclt)==0) {
			gotoxy(112,14);
			cout<< "                                        ";
			gotoxy(112,14);
			cout << "khong duoc de trong!";
			a = 1;
			getch();
		}
	} while (a==1);
	do {
		gotoxy(112,18);
		cout<< "                                        ";
		DrawBox(110,17,54,2);
		a=0;
		gotoxy(112,17);
		cout <<"Nhap so tin chi thuc hanh: ";
		fflush(stdin);
		gotoxy(112,18);
		InputNumber(stcth,maxma);
		if (strlen(stcth)==0) {
			gotoxy(112,18);
			cout<< "                                        ";
			gotoxy(112,18);
			cout << "khong duoc de trong!";
			a = 1;
			getch();
		}				
	} while (a==1);
	strcpy(mh.MAMH,strupr(mmh));
	strcpy(mh.TENMH,strupr(Trim(tmh)));
	mh.STCLT = atoi(stclt);
	mh.STCTH = atoi(stcth);
	return mh;
}

NODETREE* FindMin(PTR_NODETREE ds)
{
	while (ds->LEFT != NULL) ds = ds->LEFT;
	return (ds);
}


void RemoveTree (PTR_NODETREE &ds, dsmh mh) {
	
	if (ds==NULL) {
		return;
	} 
	else {
		if (stricmp(mh.MAMH,ds->monhoc.MAMH) < 0)
		{
			RemoveTree(ds->LEFT, mh); // duyet sang nhanh trai cua cay
		}
		else if (stricmp(mh.MAMH,ds->monhoc.MAMH) >  0 )
		{
			RemoveTree(ds->RIGHT, mh); // duyet sang nhanh phai cua cây 
		}
		else  // thay node can xoa
		{
			NODETREE *x = ds;  
			if (ds->RIGHT == NULL && ds->LEFT == NULL) {
				delete ds;
				ds = NULL;
			}
			else if (ds->LEFT == NULL)
			{
				// duyet sang phai 
				ds = ds->RIGHT; 
				delete x; 
			}
			else if (ds->RIGHT == NULL)
			{
				// duyet sang trai
				ds = ds->LEFT;
				delete x; 
			}
			else // node co hai cay con
			{
				x = FindMin(ds->RIGHT);
				ds->monhoc = x->monhoc;
				ds = x;
				delete x;
			}
		}
	}
}

void DeleteNode (PTR_NODETREE &ds, dsmh mh) {
	char m[50];
	DrawBox(114,19,50,2);
	gotoxy(116,19);
	cout << "Nhap ma mon hoc can xoa!";
	gotoxy(116,20);
	InputString(m,50);
	if (Search_MaMonHoc(ds,m) != NULL) {
		mh = Search_MaMonHoc(ds,m)->monhoc;
		RemoveTree(ds,mh);
		gotoxy(116,20);
		cout << "DONE";	
		getch();
	} else {
		gotoxy(116,20);
		cout << "Khong tim thay!";	
		getch();
	}
	
}

void Inorder(PTR_NODETREE p) { // duyet theo left node right
	if (p!=NULL) {
		Inorder (p->LEFT);
		cout << p->monhoc.MAMH << endl;
		cout << p->monhoc.TENMH << endl;
		cout << p->monhoc.STCLT << endl;
		cout << p->monhoc.STCTH << endl;
		Inorder (p->RIGHT);
	}
}

void Show_Tree (PTR_NODETREE ds,int k) {
	PTR_NODETREE p = ds;
	dsmh *arrtemp[500];
	PTR_NODETREE Stack[500];
	int sp = -1;
	int i = 0;
	while(p != NULL)
	{
		arrtemp[i] = new dsmh;
		strcpy(arrtemp[i]->MAMH,p->monhoc.MAMH);
		strcpy(arrtemp[i]->TENMH,p->monhoc.TENMH);
		arrtemp[i]->STCLT = p->monhoc.STCLT;
		arrtemp[i]->STCTH = p->monhoc.STCTH;
		if(p->RIGHT != NULL)
		{
			Stack[++sp] = p->RIGHT;
		}
		if(p->LEFT != NULL)
		{
			p = p->LEFT;
		}
		else if(sp == -1)
				break;
		else p = Stack[sp--];
		i++;
	}
//	Sort(*arrtemp,1,i+1);
	int j=0;
	TextColor(DEN);
	for (k;k<=i;k++) {	
		gotoxy(6,j+7);
		cout << k+1;
		gotoxy(14,j+7);
		cout << arrtemp[k]->MAMH;
		gotoxy(27,j+7);
		cout << arrtemp[k]->TENMH;
		gotoxy(87,j+7);
		cout << arrtemp[k]->STCLT;
		gotoxy(95,j+7);
		cout << arrtemp[k]->STCTH;
		j++;
		if (j==30) {
			break; 
		}
	}
}
void Sort(dsmh *arr,int q, int r) {
	dsmh tam;
	int i=q;
	int j=r;
	dsmh x;
	strcpy(x.TENMH,arr[(q+r)/2].TENMH);
	do {
		while (stricmp(arr[i].TENMH,x.TENMH) < 0) i++;
		while (stricmp(arr[j].TENMH,x.TENMH) > 0) j--;
		if (i<=j) {
			strcpy(tam.MAMH,arr[i].MAMH);
			strcpy(tam.TENMH,arr[i].TENMH);
			tam.STCLT = arr[i].STCLT;
			tam.STCTH = arr[i].STCTH;
			
			strcpy(arr[i].MAMH,arr[j].MAMH);
			strcpy(arr[i].TENMH,arr[j].TENMH);
			arr[i].STCLT = arr[j].STCLT;
			arr[i].STCTH = arr[j].STCTH;
			
			strcpy(arr[j].MAMH,tam.MAMH);
			strcpy(arr[j].TENMH,tam.TENMH);
			arr[j].STCLT = tam.STCLT;
			arr[j].STCTH = tam.STCTH;
			i++;
			j--;
		}
	} while (i<=j);
	if (q<j) {
		Sort(arr,q,j);
	}
	if (i<r) {
		Sort(arr,i,r);
	}
}

void ConvertArray(PTR_NODETREE t)
{
	PTR_NODETREE p = t;
	dsmh *arrtemp[500];
	PTR_NODETREE Stack[500];
	int sp = -1;
	int i = 0;
	while(p != NULL)
	{
		arrtemp[i] = new dsmh;
		strcpy(arrtemp[i]->MAMH,p->monhoc.MAMH);
		strcpy(arrtemp[i]->TENMH,p->monhoc.TENMH);
		arrtemp[i]->STCLT = p->monhoc.STCLT;
		arrtemp[i]->STCTH = p->monhoc.STCTH;
		if(p->RIGHT != NULL)
		{
			Stack[++sp] = p->RIGHT;
		}
		if(p->LEFT != NULL)
		{
			p = p->LEFT;
		}
		else if(sp == -1)
				break;
			 else p = Stack[sp--];
		i++;
	}
}

int CountNode(PTR_NODETREE &t)
{
	int c = 1;             // ban than node duoc dem la 1;
	if (t == NULL)
		return 0;
	else
	{
		c += CountNode(t->LEFT);
		c += CountNode(t->RIGHT);
		return c;
	}
}

void DocFile_MH(PTR_NODETREE &ds) {
	dsmh mh;
	int so;
	string temp;
	fstream filein;
	filein.open("monhoc.txt",ios::in);
	if (filein.is_open()) {
		while (!filein.eof()) {
			getline(filein,temp);
			filein.getline(mh.MAMH,10);
			filein.getline(mh.TENMH,50);
			filein >> mh.STCLT;
			filein >> mh.STCTH;
			Insert_Node_Tree(ds,mh);
			if(filein == NULL) {
	        	break;
	    	}
		}
	} else {
		
	}
	
	filein.close();
}

//void GhiFile_MH(PTR_NODETREE &ds) {
//	fstream fileout("monhoc.txt",ios_base::out);
//	const int STACKSIZE = 100;
//	PTR_NODETREE Stack[STACKSIZE];
//	int sp = -1;
//	do 
//	{
//		
//		while(ds != NULL)
//		{
//			Stack[++sp] = ds;
//			ds = ds -> LEFT;
//		}
//		if(sp != -1)
//		{
//			ds = Stack[sp--];
//			fileout << "\n";
//			fileout << ds->monhoc.MAMH << "\n";
//			fileout << ds->monhoc.TENMH << "\n";
//			fileout << ds->monhoc.STCLT << "\n";
//			fileout << ds->monhoc.STCTH;
//			ds = ds -> RIGHT;
//		} else break;
//	} while (1);	
//
//}

void GhiFile_MH(PTR_NODETREE &ds) {
	fstream fileout("monhoc.txt",ios_base::out);
	const int STACKSIZE = 100;
	PTR_NODETREE Stack[STACKSIZE];
	int sp = -1;
	do 
	{
		
		while(ds != NULL)
		{
			Stack[++sp] = ds;
			ds = ds -> LEFT;
		}
		if(sp != -1)
		{
			ds = Stack[sp--];
			fileout << "\n";
			fileout << ds->monhoc.MAMH << "\n";
			fileout << ds->monhoc.TENMH << "\n";
			fileout << ds->monhoc.STCLT << "\n";
			fileout << ds->monhoc.STCTH;
			ds = ds -> RIGHT;
		} else break;
	} while (1);	

}
