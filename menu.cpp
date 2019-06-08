#include "menu.h"

using namespace std;

string tieude = "CHUONG TRINH QUAN LY SINH VIEN";

void DrawBox(int x, int y, int width, int height)
{
	char a = 218, b = 196, c = 191, d = 179, e = 192, f = 217;
	gotoxy(x, y);
	cout << a;                // goc tren trai
	for (int i = 1; i < width; i++){
		gotoxy(x + i, y);
		cout << b;
	}
	gotoxy(x + width, y);     // goc tren phai
	cout << c;
	for (int i = 1; i < height; i++){
		gotoxy(x, y + i);
		cout << d;
	}
	gotoxy(x, y + height);    // goc duoi trai
	cout << e;
	for (int i = 1; i < width; i++){
		gotoxy(x + i, y + height);
		cout << b;
	}
	gotoxy(x + width, y + height);   // goc duoi phai
	cout << f;
	for (int i = 1; i < height; i++){
		gotoxy(x + width, y + i);
		cout << d;
	}
}

void DrawScreen()
{
	// ve duong ben trai
	TextColor(LAM);
	for (int i = 1; i < HEIGHT; i++)
	{
		gotoxy(1, i);
		cout << "//"; //char(221);
	}
	// ve duong ben phai
	for (int i = 0; i < HEIGHT-1; i++)
	{
		gotoxy(WIDTH-2, i+1);
		cout << "//";//char(221);
	}
	// ve duong tren
	for (int i = 1; i < WIDTH; i++)
	{
		gotoxy(i, 0);
		cout << char(219);
	}
	// ve duong tren phu 1
	for (int i = 1; i < WIDTH ; i++)
	{
		gotoxy(i , 1);
		cout << char(205);
	}
	// ve duong tren phu 2
	for (int i = 1; i < WIDTH ; i++)
	{
		gotoxy(i , 3);
		cout << char(205);
	}
	
	// ve duong duoi phu 1
	for (int i = 1; i < WIDTH; i++)
	{
		gotoxy(i , HEIGHT - 2);
		cout << char(205);
	}
	// ve duong duoi phu 2
	for (int i = 1; i < WIDTH; i++)
	{
		gotoxy(i, HEIGHT);
		cout << char(205);
	}	
	// ve duong duoi chinh
	for (int i = 1; i < WIDTH; i++)
	{
		gotoxy(i, HEIGHT+1);
		cout << char(219);
	}	
	TextColor(DEN);

}

void Print_Item()
{
	int So_item = 4;
	string *item = new string[So_item];
	item[0] = "LOP TIN CHI";
	item[1] = "SINH VIEN";
	item[2] = "MON HOC ";
	item[3] = "BANG DIEM";
	gotoxy(71, HEIGHT - 1);
	TextColor(132);
	cout << "ESC: THOAT --- ENTER: CHON";
	TextColor(138);
	//in menu ra man hinh
	for (int i = 0; i < So_item; i++)
	{
		gotoxy((WIDTH / 2 - 6), i + 20);
		cout << item[i] << endl;
	}
}

void DrawBoxItemLTC() {
	for (int i = 0;i < 4; i++) {
		TextColor(137);
		DrawBox(114,8+i*7,50,2);
		gotoxy(131,9);
		cout << "THEM LOP TIN CHI";
		gotoxy(132,9+7);
		cout << "XOA LOP TIN CHI";
		gotoxy(129,9+14);
		cout << "CHINH SUA LOP TIN CHI";
		gotoxy(126,9+21);
		cout << "DANH SACH SINH VIEN CUA LOP";
	}
}

void ChoiceLTC(int i,int j) {
	TextColor(j);
	if (i == 0) {
		gotoxy(131,9);
		cout << "THEM LOP TIN CHI";
	}
	if (i == 1) {
		gotoxy(132,9+7);
		cout << "XOA LOP TIN CHI";
	}
	if (i == 2) {
		gotoxy(129,9+14);
		cout << "CHINH SUA LOP TIN CHI";
	}
	if (i  == 3) {
		gotoxy(126,9+21);
		cout << "DANH SACH SINH VIEN CUA LOP";
	}
}

void ChoiceDataLTC(int i,int j) {
	if (i == 0 ) {
		gotoxy(27,j);
		cout << ">";
	}
	if (i == 1 ) {
		gotoxy(49,j);
		cout << ">";
	}
	if (i == 2 ) {
		gotoxy(66,j);
		cout << ">";
	}
	if (i == 3 ) {
		gotoxy(76,j);
		cout << ">";
	}
	if (i == 4 ) {
		gotoxy(87,j);
		cout << ">";
	}
}

void Print_Item_LTC()
{
	NODETT ds;
	InitializeTT(ds);
	DocFile_LTC(ds);
	int max = 10;
	int k=0;
	int thaoTac = 0;	
	bool exit = false;
	int So_item = 4;
	TextColor(DEN);
	//	in tieu de chuong trinh
	for (int i=3;i<=165;i++) {
		gotoxy(i,2);
		cout << " ";
	}
	gotoxy(79,2);
	TextColor(138);
	cout << "LOP TIN CHI";
	gotoxy(5, HEIGHT - 1);
	for (int i=3;i<=165;i++) {
		gotoxy(i,HEIGHT - 1);
		cout << " ";
	}
	gotoxy(5, HEIGHT - 1);
	TextColor(132);
	cout << "ESC : THOAT | ENTER : CHON | PAGE UP - PAGE DOWN : CHUYEN TRANG ";
	//TextColor(138);
	// in menu ra man hinh
	DrawBoxItemLTC();
	//	highlight thao tac dau tien khi mo chuong trinh
	TextColor(140);
	gotoxy(131,9);
	cout << "THEM LOP TIN CHI";
	TextColor(DEN);
	Draw_LTC(ds,k);
	while (!exit)
	{	
		
		char key;
		key = getch();
		if (key == UP)
		{
			ChoiceLTC(thaoTac,137);
			if (thaoTac == 0)
				thaoTac = So_item - 1;
			else thaoTac--;	
		}
		else if (key == DOWN)
		{
			ChoiceLTC(thaoTac,137);
			if (thaoTac == So_item - 1)
				thaoTac = 0;
			else thaoTac++;	
		}
		else if (key == ESC)
		{
			exit = true;
		}
		else if (key == PGUP) {
			k=k-30;
			if (k<0) {
				k=0;
			}
			ClearTable();
			Draw_LTC(ds,k);
		}
		else if (key == PGDN) {
			k=k+30;
			if (k>=ds.n) {
				k=k-30;
			}
			ClearTable();
			Draw_LTC(ds,k);
		}
		else if (key == ENTER)
		{
			if (thaoTac == 0) {
				ClearChoice();
				Create_LopTinChi(ds);
				GhiFile_LTC(ds);
				ClearTable();
				Draw_LTC(ds,k);
				ClearChoice();
				DrawBoxItemLTC();
			}
			else if (thaoTac == 1) {
				ClearChoice();
				DrawBox(114,20,50,2);
				gotoxy(116,20);
				cout << "Nhap ma lop tin chi can xoa!";
				char a[10];
				fflush(stdin);
				gotoxy(116,21);
				InputNumber(a,max);
				Delete_LTC_MALOPTC(ds,atoi(a));
				GhiFile_LTC(ds);
				ClearTable();
				Draw_LTC(ds,k);
				ClearChoice();
				DrawBoxItemLTC();
			}
			else if (thaoTac == 2) {
				exit = false;
				ClearTable();
				ClearChoice();
				Draw_LTC(ds,k);
				int thaotac=0;
				gotoxy(5,7);
				cout << ">";
				gotoxy(11,7);
				cout << "<";
				while (!exit) {
					char c;
					c = getch();
					if (c == DOWN)
					{
						thaotac++;
						if (thaotac >=(ds.n-k-1)) {
							thaotac=(ds.n-k-1);
						}
						if (thaotac >= 30) {
							thaotac=29;
						}
						gotoxy(5,thaotac+7);
						cout << ">";
						gotoxy(11,thaotac+7);
						cout << "<";
						//
						gotoxy(5,thaotac+6);
						cout << " ";
						gotoxy(11,thaotac+6);
						cout << " ";				
					}
					else if (c == UP)
					{
						thaotac--;
						if (thaotac <= 0) {
							thaotac = 0;
						}
						gotoxy(5,thaotac+7);
						cout << ">";
						gotoxy(11,thaotac+7);
						cout << "<";
						//
						gotoxy(5,thaotac+8);
						cout << " ";
						gotoxy(11,thaotac+8);
						cout << " ";	
					}
					else if (c == ESC)
					{
						exit = true;
					}
					else if (c == ENTER) {
						Fix_Data_LTC(ds,thaotac,k);
						GhiFile_LTC(ds);
						ClearTable();
						Draw_LTC(ds,k);
						gotoxy(5,thaotac+7);
						cout << ">";
						gotoxy(11,thaotac+7);
						cout << "<";
					}
				}
				exit = false;
				ClearTable();
				Draw_LTC(ds,k);
				ClearChoice();
				DrawBoxItemLTC();
			}
			else if (thaoTac == 3) {
				exit = false;
				ClearTable();
				ClearChoice();
				Draw_LTC(ds,k);
				int thaotac=0;
				gotoxy(5,7);
				cout << ">";
				gotoxy(11,7);
				cout << "<";
				while (!exit) {
					char c;
					c = getch();
					if (c == DOWN)
					{
						thaotac++;
						if (thaotac >=(ds.n-k-1)) {
							thaotac=(ds.n-k-1);
						}
						if (thaotac >= 30) {
							thaotac=29;
						}
						gotoxy(5,thaotac+7);
						cout << ">";
						gotoxy(11,thaotac+7);
						cout << "<";
						//
						gotoxy(5,thaotac+6);
						cout << " ";
						gotoxy(11,thaotac+6);
						cout << " ";				
					}
					else if (c == UP)
					{
						thaotac--;
						if (thaotac <= 0) {
							thaotac = 0;
						}
						gotoxy(5,thaotac+7);
						cout << ">";
						gotoxy(11,thaotac+7);
						cout << "<";
						//
						gotoxy(5,thaotac+8);
						cout << " ";
						gotoxy(11,thaotac+8);
						cout << " ";	
					}
					else if (c == ESC)
					{
						exit = true;
					}
					else if (c == ENTER) {
					
					}
				}
				exit = false;
				ClearTable();
				Draw_LTC(ds,k);
				ClearChoice();
				DrawBoxItemLTC();
			}
			
		}
		//	highlight thao tac duoc chon
			ChoiceLTC(thaoTac,140);
			// dua cac thao tac khac ve mau mac dinh
			TextColor(DEN);
	}
}

void DrawBoxItemSV() {
	for (int i = 0;i <= 1; i++) {
		TextColor(137);
		DrawBox(59,11+i*11,50,2);
		gotoxy(77,12);
		cout << "NHAP SINH VIEN";
		gotoxy(73,23);
		cout << "IN DANH SACH SINH VIEN";
	}
}

void ChoiceSV(int i,int j) {
	TextColor(j);
	if (i == 0) {
		gotoxy(77,12);
		cout << "NHAP SINH VIEN";
	}
	if (i == 1) {
		gotoxy(73,23);
		cout << "IN DANH SACH SINH VIEN";
	}
}

void DrawTableSV() {
	TextColor(DEN);
	DrawBox(4,4,95,33);
	for (int i=5;i<=98;i++) { // line ngang 
		gotoxy(i,6);
		cout << char(196);
		gotoxy(4,6);
		cout << char(195);
		gotoxy(99,6);
		cout << char(180);
	}
	for (int i=5;i<=36;i++) {
		gotoxy(10,i);
		cout << char(179);
		gotoxy(10,4);
		cout << char(194);
		gotoxy(10,6);
		cout << char(197);
		gotoxy(10,37);
		cout << char(193);
		//
		gotoxy(24,i);
		cout << char(179);
		gotoxy(24,4);
		cout << char(194);
		gotoxy(24,6);
		cout << char(197);
		gotoxy(24,37);
		cout << char(193);
		//
		gotoxy(39,i);
		cout << char(179);
		gotoxy(39,4);
		cout << char(194);
		gotoxy(39,6);
		cout << char(197);
		gotoxy(39,37);
		cout << char(193);
		//
		gotoxy(62,i);
		cout << char(179);
		gotoxy(62,4);
		cout << char(194);
		gotoxy(62,6);
		cout << char(197);
		gotoxy(62,37);
		cout << char(193);
		//
		gotoxy(72,i);
		cout << char(179);
		gotoxy(72,4);
		cout << char(194);
		gotoxy(72,6);
		cout << char(197);
		gotoxy(72,37);
		cout << char(193);
		//
		gotoxy(81,i);
		cout << char(179);
		gotoxy(81,4);
		cout << char(194);
		gotoxy(81,6);
		cout << char(197);
		gotoxy(81,37);
		cout << char(193);
	}
	gotoxy(6,5);
	cout << "STT";
	gotoxy(14,5);
	cout << "MA LOP";
	gotoxy(29,5);
	cout << "MA SV";
	gotoxy(50,5);
	cout << "HO";
	gotoxy(66,5);
	cout << "TEN";
	gotoxy(75,5);
	cout << "PHAI";
	gotoxy(84,5);
	cout << "SO DIEN THOAI";
//	//
//	gotoxy(13,7);
//	cout << "D17CQCN01";
//	gotoxy(27,7);
//	cout << "N17DCCN024";
//	gotoxy(42,7);
//	cout << "Dinh Nguyen Thien";
//	gotoxy(65,7);
//	cout << "DUNG";
//	gotoxy(75,7);
//	cout << "NAM";
//	gotoxy(85,7);
//	cout << "0379623598";
}

void Print_Item_SV()
{
	int thaoTac = 0;	
	bool exit = false;
	int So_item = 2;
	TextColor(DEN);
	DrawScreen();
	//	in tieu de chuong trinh
	for (int i=3;i<=165;i++) {
		gotoxy(i,2);
		cout << " ";
	}
	gotoxy(80,2);
	TextColor(138);
	cout << "SINH VIEN";
	gotoxy(71, HEIGHT - 1);
	TextColor(132);
	cout << "ESC: THOAT --- ENTER: CHON";
	TextColor(138);
	//in menu ra man hinh
	DrawBoxItemSV();
	//	highlight thao tac dau tien khi mo chuong trinh
	ChoiceSV(thaoTac,140);
	TextColor(DEN);
	while (!exit)
	{	
		char key;
		key = getch();
		if (key == UP)
		{
			ChoiceSV(thaoTac,137);
			if (thaoTac == 0)
				thaoTac = So_item - 1;
			else thaoTac--;			
		}
		else if (key == DOWN)
		{
			ChoiceSV(thaoTac,137);
			if (thaoTac == So_item - 1)
				thaoTac = 0;
			else thaoTac++;			
		}
		else if (key == ESC)
		{
			exit = true;
		}
		else if (key == ENTER)
		{
			if (thaoTac == 0) {
				
			}
			
		}
		//	highlight thao tac duoc chon
		ChoiceSV(thaoTac,140);
		// dua cac thao tac khac ve mau mac dinh
		TextColor(DEN);
	}
}

void DrawBoxItemMH() {
	for (int i = 0;i <= 2; i++) {
		TextColor(137);
		DrawBox(114,12+i*7,50,2);
		gotoxy(133,13);
		cout << "THEM MON HOC";
		gotoxy(134,13+7);
		cout << "XOA MON HOC";
		gotoxy(131,13+14);
		cout << "CHINH SUA MON HOC";
	}
}

void ChoiceMH(int i,int j) {
	TextColor(j);
	if (i == 0) {
		gotoxy(133,13);
		cout << "THEM MON HOC";
	}
	if (i == 1) {
		gotoxy(134,13+7);
		cout << "XOA MON HOC";
	}
	if (i == 2) {
		gotoxy(131,13+14);
		cout << "CHINH SUA MON HOC";
	}
}

void ChoiceDataMH(int i,int j) {
	if (i == 0 ) {
		gotoxy(11,j);
		cout << ">";
	}
	if (i == 1 ) {
		gotoxy(26,j);
		cout << ">";
	}
	if (i == 2 ) {
		gotoxy(84,j);
		cout << ">";
	}
	if (i == 3 ) {
		gotoxy(92,j);
		cout << ">";
	}
}

void ClearSignalMH(int i) {
	gotoxy(11,i);
	cout << " ";
	gotoxy(26,i);
	cout << " ";
	gotoxy(84,i);
	cout << " ";
	gotoxy(92,i);
	cout << " ";
}

void Print_Item_MH()
{
	PTR_NODETREE kd;
	dsmh mh;
	InitializeTree(kd);
	DocFile_MH(kd);
	int k=0;
	int thaoTac = 0;	
	bool exit = false;
	char CTRL;
	int So_item = 3;
	TextColor(DEN);
	DrawScreen();
	//	in tieu de chuong trinh
	for (int i=3;i<=165;i++) {
		gotoxy(i,2);
		cout << " ";
	}
	gotoxy(81,2);
	TextColor(138);
	cout << "MON HOC";
	for (int i=3;i<=165;i++) {
		gotoxy(i,39);
		cout << " ";
	}
	gotoxy(5, HEIGHT - 1);
	TextColor(132);
	cout << "ESC : THOAT | ENTER : CHON | PAGE UP - PAGE DOWN : CHUYEN TRANG";
	TextColor(138);
	//in menu ra man hinh
	DrawBoxItemMH();
	//	highlight thao tac dau tien khi mo chuong trinh
	ChoiceMH(thaoTac,140);
	TextColor(DEN);
	DrawTableMH();
	Show_Tree(kd,k);
	while (!exit)
	{	
		
		char key;
		key = getch();
		if (key == UP)
		{
			ChoiceMH(thaoTac,137);
			if (thaoTac == 0)
				thaoTac = So_item - 1;
			else thaoTac--;			
		}
		else if (key == DOWN)
		{
			ChoiceMH(thaoTac,137);
			if (thaoTac == So_item - 1)
				thaoTac = 0;
			else thaoTac++;			
		}
		else if (key == ESC)
		{
			exit = true;
		}
		else if (key == PGUP) {
			k=k-30;
			if (k<0) {
				k=0;
			}
			ClearTable();
			DrawTableMH();
			Show_Tree(kd,k);
		}
		else if (key == PGDN) {
			k=k+30;
			if (k>=CountNode(kd)) {
				k=k-30;
			}
			ClearTable();
			DrawTableMH();
			Show_Tree(kd,k);
		}
		else if (key == ENTER)
		{
			if (thaoTac == 0) {
				ClearChoice();
				mh = Input_Tree(kd);
				Insert_Node_Tree(kd,mh);
				if (strcmp(mh.MAMH,"null")==0) {
					RemoveTree(kd,mh);
				}
				GhiFile_MH(kd);
				DocFile_MH(kd);
				ClearChoice();
				DrawBoxItemMH();
				ClearTable();
				DrawTableMH();
				Show_Tree(kd,k);
				
			}
			else if (thaoTac == 1) {
				ClearChoice();
				DeleteNode(kd,mh);
				GhiFile_MH(kd);
				DocFile_MH(kd);
				ClearChoice();
				DrawBoxItemMH();
				ClearTable();
				DrawTableMH();
				Show_Tree(kd,k);
			}
			else if (thaoTac == 2) {
				exit = false;
				ClearTable();
				ClearChoice();
				DrawTableMH();
				Show_Tree(kd,k);
				int thaotac=0;
				gotoxy(5,7);
				cout << ">";
				gotoxy(9,7);
				cout << "<";
				while (!exit) {
					char c;
					c = getch();
					if (c == DOWN)
					{
						thaotac++;
						if (thaotac >= CountNode(kd)-k-1) {
							thaotac = CountNode(kd)-k-1;
						}
						if (thaotac >= 30) {
							thaotac=29;
						}
						gotoxy(5,thaotac+7);
						cout << ">";
						gotoxy(9,thaotac+7);
						cout << "<";
						//
						gotoxy(5,thaotac+6);
						cout << " ";
						gotoxy(9,thaotac+6);
						cout << " ";
					}
					else if (c == UP)
					{
						thaotac--;
						if (thaotac <= 0) {
							thaotac = 0;
						}
						gotoxy(5,thaotac+7);
						cout << ">";
						gotoxy(9,thaotac+7);
						cout << "<";
						//
						gotoxy(5,thaotac+8);
						cout << " ";
						gotoxy(9,thaotac+8);
						cout << " ";
					}
					else if (c == ESC)
					{
						exit = true;
					}
					else if (c == ENTER) {
						Fix_Data_MH(kd,thaotac,k);
						GhiFile_MH(kd);
						DocFile_MH(kd);
						ClearTable();
						ClearChoice();
						DrawTableMH();
						Show_Tree(kd,k);
						gotoxy(5,thaotac+7);
						cout << ">";
						gotoxy(9,thaotac+7);
						cout << "<";
					}
				}
				DrawBoxItemMH();
				exit = false;
			}
		}
		//	highlight thao tac duoc chon
		ChoiceMH(thaoTac,140);
		// dua cac thao tac khac ve mau mac dinh
		TextColor(DEN);
	}
}

void DrawBoxItemBD() {
	for (int i = 0;i <= 3; i++) {
		TextColor(137);
		DrawBox(59,10+i*7,50,2);
		gotoxy(75,11);
		cout << "NHAP DIEM SINH VIEN";
		gotoxy(76,11+7);
		cout << "BANG DIEM MON HOC";
		gotoxy(65,11+14);
		cout << "BANG DIEM TRUNG BINH KET THUC KHOA HOC";
		gotoxy(68,11+21);
		cout << "BANG DIEM TONG KET CUA SINH VIEN";
	}
}

void ChoiceBD(int i,int j) {
	TextColor(j);
	if (i == 0) {
		gotoxy(75,11);
		cout << "NHAP DIEM SINH VIEN";
	}
	if (i == 1) {
		gotoxy(76,11+7);
		cout << "BANG DIEM MON HOC";
	}
	if (i == 2) {
		gotoxy(65,11+14);
		cout << "BANG DIEM TRUNG BINH KET THUC KHOA HOC";
	}
	if (i == 3) {
		gotoxy(68,11+21);
		cout << "BANG DIEM TONG KET CUA SINH VIEN";
	}
}

void Print_Item_BD()
{
	int thaoTac = 0;	
	bool exit = false;
	int So_item = 4;
	TextColor(DEN);
	DrawScreen();
	//	in tieu de chuong trinh
	for (int i=3;i<=165;i++) {
		gotoxy(i,2);
		cout << " ";
	}
	gotoxy(80,2);
	TextColor(138);
	cout << "BANG DIEM";
	gotoxy(71, HEIGHT - 1);
	TextColor(132);
	cout << "ESC: THOAT --- ENTER: CHON";
	TextColor(138);
	//in menu ra man hinh
	DrawBoxItemBD();
	//	highlight thao tac dau tien khi mo chuong trinh
	ChoiceBD(thaoTac,140);
	TextColor(DEN);
	while (!exit)
	{	
		char key;
		key = getch();
		if (key == UP)
		{
			ChoiceBD(thaoTac,137);
			if (thaoTac == 0)
				thaoTac = So_item - 1;
			else thaoTac--;			
		}
		else if (key == DOWN)
		{
			ChoiceBD(thaoTac,137);
			if (thaoTac == So_item - 1)
				thaoTac = 0;
			else thaoTac++;			
		}
		else if (key == ESC)
		{
			exit = true;
		}
		else if (key == ENTER)
		{
			
		}
		//	highlight thao tac duoc chon
		ChoiceBD(thaoTac,140);
		// dua cac thao tac khac ve mau mac dinh
		TextColor(DEN);
	}
}

void ReMenu()
{	
	char c;
	int So_item = 4;
	TextColor(DEN);
	gotoxy(3, 39);
	cout << "                                            ";
	gotoxy(3, 39);
	TextColor(DO);
	cout << "Bam Esc de ve menu";
	TextColor(DEN);	
	do
	{
		c = getch();
		if(c == ESC)
		{
			XoaManHinh();
			DrawScreen();
			gotoxy((WIDTH / 2 - tieude.length() / 2), 2);
			TextColor(LUC);
			cout << tieude;
			ReMenu();
		}
	} while(c != ESC);	
}

//void Lua_Chon() {
//	
//}

void Choice(int i,int j) {
	TextColor(j);
	if (i == 0) {
		gotoxy(78,11);
		cout << "LOP TIN CHI";
	}
	if (i == 1) {
		gotoxy(79,11+7);
		cout << "SINH VIEN";
	}
	if (i == 2) {
		gotoxy(80,11+14);
		cout << "MON HOC";
	}
	if (i == 3) {
		gotoxy(79,11+21);
		cout << "BANG DIEM";
	}
}

void DrawBoxItem() {
	for (int i = 0;i <= 3; i++) {
		TextColor(137);
		DrawBox(68,10+i*7,30,2);
		gotoxy(78,11);
		cout << "LOP TIN CHI";
		gotoxy(79,11+7);
		cout << "SINH VIEN";
		gotoxy(80,11+14);
		cout << "MON HOC";
		gotoxy(79,11+21);
		cout << "BANG DIEM";
	}
}

void Menu()
{
	int So_item = 4;
	int thaoTac = 0;	
	bool exit = false;
	DrawScreen();
	//	in tieu de chuong trinh
	gotoxy((WIDTH / 2 - tieude.length() / 2), 2);
	TextColor(LUC);
	cout << tieude;
	// in lua chon enter thoat
	gotoxy(71, HEIGHT - 1);
	TextColor(DODAM);
	cout << "ESC: THOAT --- ENTER: CHON";
	// ve box item
	DrawBoxItem();
	TextColor(DEN);
	//	highlight thao tac dau tien khi mo chuong trinh
		TextColor(140);
		gotoxy(78,11);
		cout << "LOP TIN CHI";
	while (!exit)
	{	
		//	in tieu de chuong trinh
		for (int i=3;i<=165;i++) {
			gotoxy(i,2);
			cout << " ";
		}
		gotoxy((WIDTH / 2 - tieude.length() / 2), 2);
		TextColor(LUC);
		cout << tieude;
		// in lua chon enter thoat
		for (int i=3;i<=165;i++) {
			gotoxy(i,39);
			cout << " ";
		}
		gotoxy(71, HEIGHT - 1);
		TextColor(DODAM);
		cout << "ESC: THOAT --- ENTER: CHON";
		char key;
		key = getch();
		if (key == UP)
		{
			Choice(thaoTac,137);
			if (thaoTac == 0)
				thaoTac = So_item - 1;
			else thaoTac--;			
		}
		else if (key == DOWN)
		{
			Choice(thaoTac,137);
			if (thaoTac == So_item - 1)
				thaoTac = 0;
			else thaoTac++;			
		}
		else if (key == ESC)
		{
			exit = true;
		}
		else if (key == ENTER)
		{
			if (thaoTac == 0)
			{
				Clearmen();
				Print_Item_LTC();
				Clearmen();
				//in menu ra man hinh
				DrawBoxItem();
			}
			else if (thaoTac == 1)
			{
				Clearmen();
				Print_Item_SV();
				Clearmen();
				DrawBoxItem();
			}
			else if (thaoTac == 2)
			{
				Clearmen();
				Print_Item_MH();
				Clearmen();
				DrawBoxItem();
			}
			else if (thaoTac == 3)
			{
				Clearmen();
				Print_Item_BD();
				Clearmen();
				DrawBoxItem();
			}
		}
		//	highlight thao tac duoc chon
		Choice(thaoTac,140);
		// dua cac thao tac khac ve mau mac dinh
		TextColor(DEN);
	}
}

void Clearmen() {
	for (int i=4;i<=37;i++) {
		for (int j=3;j<=165;j++) {
			gotoxy(j,i);
			cout << " ";
		}
	}
}

void ClearTable() {
	for (int i=4;i<=37;i++) {
		for (int j=3;j<=99;j++) {
			gotoxy(j,i);
			cout << " ";
		}
	}
}

void ClearChoice() {
	for (int i=4;i<=37;i++) {
		for (int j=100;j<=165;j++) {
			gotoxy(j,i);
			cout << " ";
		}
	}
}

void ClearSignalLTC(int i) {
	gotoxy(27,i);
	cout << " ";
	gotoxy(49,i);
	cout << " ";
	gotoxy(66,i);
	cout << " ";
	gotoxy(76,i);
	cout << " ";
	gotoxy(87,i);
	cout << " ";
}

void DrawTableLTC() {
	DrawBox(4,4,95,33);
	for (int i=5;i<=98;i++) { // line ngang 
		gotoxy(i,6);
		cout << char(196);
		gotoxy(4,6);
		cout << char(195);
		gotoxy(99,6);
		cout << char(180);
	}
	for (int i=5;i<=36;i++) { // line doc
		gotoxy(12,i);
		cout << char(179);
		gotoxy(12,4);
		cout << char(194);
		gotoxy(12,6);
		cout << char(197);
		gotoxy(12,37);
		cout << char(193);
		//
		gotoxy(26,i);
		cout << char(179);
		gotoxy(26,4);
		cout << char(194);
		gotoxy(26,6);
		cout << char(197);
		gotoxy(26,37);
		cout << char(193);
		//
		gotoxy(48,i);
		cout << char(179);
		gotoxy(48,4);
		cout << char(194);
		gotoxy(48,6);
		cout << char(197);
		gotoxy(48,37);
		cout << char(193);
		//
		gotoxy(65,i);
		cout << char(179);
		gotoxy(65,4);
		cout << char(194);
		gotoxy(65,6);
		cout << char(197);
		gotoxy(65,37);
		cout << char(193);
		//
		gotoxy(75,i);
		cout << char(179);
		gotoxy(75,4);
		cout << char(194);
		gotoxy(75,6);
		cout << char(197);
		gotoxy(75,37);
		cout << char(193);
		//
		gotoxy(86,i);
		cout << char(179);
		gotoxy(86,4);
		cout << char(194);
		gotoxy(86,6);
		cout << char(197);
		gotoxy(86,37);
		cout << char(193);
	}
	gotoxy(7,5);
	cout << "STT";
	gotoxy(16,5);
	cout << "MALOPTC";
	gotoxy(35,5);
	cout << "MA MH";
	gotoxy(52,5);
	cout << "NIEN KHOA";
	gotoxy(67,5);
	cout << "HOC KY";
	gotoxy(79,5);
	cout << "NHOM";
	gotoxy(89,5);
	cout << "SO SVMAX";
}

// phan cho mh
 
void DrawTableMH() {
	TextColor(DEN);
	DrawBox(4,4,95,33);
	for (int i=5;i<=98;i++) { // line ngang 
		gotoxy(i,6);
		cout << char(196);
		gotoxy(4,6);
		cout << char(195);
		gotoxy(99,6);
		cout << char(180);
	}
	for (int i=5;i<=36;i++) {
		gotoxy(10,i);
		cout << char(179);
		gotoxy(10,4);
		cout << char(194);
		gotoxy(10,6);
		cout << char(197);
		gotoxy(10,37);
		cout << char(193);
		//
		gotoxy(25,i);
		cout << char(179);
		gotoxy(25,4);
		cout << char(194);
		gotoxy(25,6);
		cout << char(197);
		gotoxy(25,37);
		cout << char(193);
		//
		gotoxy(83,i);
		cout << char(179);
		gotoxy(83,4);
		cout << char(194);
		gotoxy(83,6);
		cout << char(197);
		gotoxy(83,37);
		cout << char(193);
		//
		gotoxy(91,i);
		cout << char(179);
		gotoxy(91,4);
		cout << char(194);
		gotoxy(91,6);
		cout << char(197);
		gotoxy(91,37);
		cout << char(193);
	}
	gotoxy(6,5);
	cout << "STT";
	gotoxy(15,5);
	cout << "MA MH";
	gotoxy(52,5);
	cout << "TEN MH";
	gotoxy(85,5);
	cout << "STCLT";
	gotoxy(93,5);
	cout << "STCTH";
	TextColor(DEN);
}
// phan danh cho LTC
void Draw_LTC(NODETT ds,int i) {
	TextColor(DEN);
	DrawTableLTC();
	Show_Data_LTC(ds,i);
}
