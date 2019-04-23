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
		if (stricmp(ds->monhoc.MAMH,mh.MAMH) < 0) {
			Insert_Node_Tree (ds->LEFT,mh);
		} else if (stricmp(ds->monhoc.MAMH,mh.MAMH) > 0) {
			Insert_Node_Tree (ds->RIGHT,mh);
		} else {
			cout << "\nDu lieu bi trung !";
		}
	}
} 


dsmh Input_Tree (PTR_NODETREE &ds) {
	dsmh mh;
	char mmh[10], tmh[50], stclt[10], stcth[10];
	do {
		XoaManHinh();
		cout <<"\nNhap Ma mon hoc: ";
		fflush(stdin);
		gets(mmh);
	} while (strlen(mmh)==0 || atoi(mmh) > 0 || atoi(mmh) < 0 || Find_Space(mmh) == 0);
	strcpy(mh.MAMH,strupr(mmh));
	do {
		XoaManHinh();
		cout <<"\nNhap ten mon hoc: ";
		fflush(stdin);
		gets(tmh);	
	} while (strlen(tmh)==0 || atoi(tmh) > 0 || atoi(tmh) < 0 );
	strcpy(mh.TENMH,strupr(Trim(tmh)));
	do {
		XoaManHinh();
		cout <<"\nNhap so tin chi ly thuyet: ";
		fflush(stdin);
		gets(stclt);	
	} while (strlen(stclt)==0 || NumberOnly(stclt)==0 );
	mh.STCLT = atoi(stclt);
	do {
		XoaManHinh();
		cout <<"\nNhap so tin chi thuc hanh: ";
		fflush(stdin);
		gets(stcth);	
	} while (strlen(stcth)==0 || NumberOnly(stcth)==0 );
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
		cout << "\nNhap tiep tuc ?";
		cin >> c;
	} while (c == 1);
	
}

NODETREE* FindMin(PTR_NODETREE ds)
{
	while (ds->LEFT != NULL) ds = ds->LEFT;
	return (ds);
}

void Find_Node_Temp(PTR_NODETREE &x , PTR_NODETREE &y) {
	// tim node trai nhat cua cay ben phai
	if (y->LEFT != NULL) {
		Find_Node_Temp(x,y->LEFT);
	} else {
		x->monhoc = y->monhoc;
		x = y;
		y = y->RIGHT;
	}
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
		else if (stricmp(mh.MAMH,ds->monhoc.MAMH) > 0 )
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
//				Find_Node_Temp(x,ds->RIGHT);
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
		Inorder (p->RIGHT);
	}
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

void DocFile_MH(PTR_NODETREE &ds) {
	dsmh mh;
	char n[2];
	fstream filein("monhoc.txt",ios_base::in);
	if (filein.fail() == TRUE) {
		cout << "\nFile khong ton tai.";
		getch();
		return;
	} 
	while (!filein.eof()) {
		filein.getline(n,2);
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
