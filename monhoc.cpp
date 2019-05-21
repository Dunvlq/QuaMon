#include "monhoc.h"



void InitializeTree(PTR_NODETREE &root) {
	root = NULL;
}

int EmptyTree (PTR_NODETREE ds) {
	if (ds == NULL) {
		return TRUE;
	} else {
		return FALSE;
	}
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

int Search_MaMonHoc(PTR_NODETREE ds, char *mh) {
	if (ds==NULL) {
		return FALSE;
	} 
	else {
		if (stricmp(mh,ds->monhoc.MAMH) == 0)
		{
			return TRUE;
		}
		else if (stricmp(mh,ds->monhoc.MAMH) < 0)
		{
			Search_MaMonHoc(ds->LEFT, mh);
		}
		else if (stricmp(mh,ds->monhoc.MAMH) > 0 ) 
		{
			Search_MaMonHoc(ds->RIGHT, mh);
		}
	}
}

int Search_TenMonHoc(PTR_NODETREE ds, char *mh) {
	TEN *arr=new TEN;
	int k=0;
	Transfer(ds,arr,k);
	for (int i=0;i<CountNode(ds);i++) {
	
			cout << arr[i].tenmh << "\n";
		
	}
//	cout << "khong co";
	getch();
}

dsmh Input_Tree (PTR_NODETREE &ds) {
	dsmh mh;
	int a=0;
	char mmh[10], tmh[50], stclt[10], stcth[10];
	do {
		XoaManHinh();
		a=0;
		cout <<"\nNhap Ma mon hoc: ";
		fflush(stdin);
		gets(mmh);
		if (Search_MaMonHoc(ds,mmh)) {
			cout << "\nma mon hoc da co, nhap lai!";
			a = 1;
			getch();
		}
		if (atoi(mmh) > 0 || atoi(mmh) < 0) {
			cout << "\nma mon hoc khong duoc nhap so nguyen, nhap lai!";
			a = 1;
			getch();
		}
		if (Find_Space(mmh) == 0) {
			cout << "\nkhong duoc chua khoang trang, nhap lai!";
			a = 1;
			getch();
		}
		if (strlen(mmh)==0) {
			cout << "\nkhong duoc nhap chuoi rong, nhap lai!";
			a = 1;
			getch();
		}
	} while (a == 1);
	strcpy(mh.MAMH,strupr(mmh));
	do {
		XoaManHinh();
		a = 0;
		cout <<"\nNhap ten mon hoc: ";
		fflush(stdin);
		gets(tmh);
//		if (Search_TenMonHoc(ds,tmh)) {
//			cout << "\nten mon hoc da co, nhap lai!";
//			a = 1;
//			getch();
//		}
		if (atoi(tmh) > 0 || atoi(tmh) < 0) {
			cout << "\nten mon hoc khong duoc nhap so nguyen, nhap lai!";
			a = 1;
			getch();
		}
		if (strlen(tmh)==0) {
			cout << "\nkhong duoc nhap chuoi rong, nhap lai!";
			a = 1;
			getch();
		}	
	} while (a == 1 );
	strcpy(mh.TENMH,strupr(Trim(tmh)));
	do {
		XoaManHinh();
		a=0;
		cout <<"\nNhap so tin chi ly thuyet: ";
		fflush(stdin);
		gets(stclt);
		if (strlen(stclt)==0) {
			cout << "\nkhong duoc nhap chuoi rong, nhap lai!";
			a = 1;
			getch();
		}
		if (Find_Space(stclt) == 0) {
			cout << "\nkhong duoc chua khoang trang, nhap lai!";
			a = 1;
			getch();
		}
		if (NumberOnly(stclt)==0) {
			cout << "\nchi duoc phep nhap so nguyen, nhap lai!";
			a = 1;
			getch();
		}
	} while (a==1);
	mh.STCLT = atoi(stclt);
	do {
		XoaManHinh();
		cout <<"\nNhap so tin chi thuc hanh: ";
		fflush(stdin);
		gets(stcth);
		if (strlen(stcth)==0) {
			cout << "\nkhong duoc nhap chuoi rong, nhap lai!";
			a = 1;
			getch();
		}
		if (Find_Space(stcth) == 0) {
			cout << "\nkhong duoc chua khoang trang, nhap lai!";
			a = 1;
			getch();
		}
		if (NumberOnly(stcth)==0) {
			cout << "\nchi duoc phep nhap so nguyen, nhap lai!";
			a = 1;
			getch();
		}
				
	} while (a==1);
	mh.STCTH = atoi(stcth);
	return mh;
}

void Show_Tree (PTR_NODETREE ds) {
	cout << "\nMa mon hoc : "<< ds->monhoc.MAMH;
	cout << "\nTen mon hoc: "<< ds->monhoc.TENMH;
	cout << "\nSo tin chi ly thuyet: "<< ds->monhoc.STCLT;
	cout << "\nSo tin chi thuc hanh: "<< ds->monhoc.STCTH << endl;
}

void CreatTree_Dsmh(PTR_NODETREE &ds, dsmh mh) {
	int c;
	do{
		mh = Input_Tree(ds);
		Insert_Node_Tree(ds,mh);
		cout << "\nNhap tiep tuc ? 1 : CO - 0 : KHONG";
		cin >> c;
	} while (c == 1);
	
}

NODETREE* FindMin(PTR_NODETREE ds)
{
	while (ds->LEFT != NULL) ds = ds->LEFT;
	return (ds);
}


void RemoveTree (PTR_NODETREE &ds, dsmh mh) {
	
	if (ds==NULL) {
		cout << "\nKhong tim thay , press any key to continue!";
		getch();
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

void Inorder(PTR_NODETREE p) { // duyet theo left node right
	if (p!=NULL) {
		Inorder (p->LEFT);
		Show_Tree(p);
		cout << "=========================";
		Inorder (p->RIGHT);
	}
}



int Transfer(PTR_NODETREE p,TEN *arr,int k) {  // ham tao mang chua cac ten mon hoc
	if (p == NULL) {
		return FALSE;
	}
	Transfer (p->LEFT,arr,k);
	strcpy(arr[k++].tenmh,p->monhoc.TENMH);
	Transfer (p->RIGHT,arr,k);
	
}

void Preorder(PTR_NODETREE p) { // duyet theo node left right
	if (p!=NULL) {
		Show_Tree(p);
		Preorder (p->LEFT);
		Preorder (p->RIGHT);
	}
}

void Posorder(PTR_NODETREE p) { // duyet theo left right node
	if (p!=NULL) {
		Posorder (p->LEFT);
		Posorder (p->RIGHT);
		Show_Tree(p);
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
	char a[2];
	fstream filein("monhoc.txt",ios_base::in);
	if (filein.fail() == TRUE) {
		cout << "\nFile khong ton tai.";
		getch();
		return;
	} 
	while (!filein.eof()) {
		filein.getline(a,2);
		filein.getline(mh.MAMH,10);
		filein.getline(mh.TENMH,50);
		filein >> mh.STCLT;
		filein >> mh.STCTH;
		Insert_Node_Tree(ds,mh);
		if(filein == NULL) {
        	break;
    	}
	}
}

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
