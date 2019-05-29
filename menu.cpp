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
	for (int i = 0;i <= 3; i++) {
		TextColor(137);
		DrawBox(59,10+i*7,50,2);
		gotoxy(76,11);
		cout << "THEM LOP TIN CHI";
		gotoxy(77,11+7);
		cout << "XOA LOP TIN CHI";
		gotoxy(74,11+14);
		cout << "CHINH SUA LOP TIN CHI";
		gotoxy(71,11+21);
		cout << "IN TAT CAC CAC LOP TIN CHI";
	}
}

void ChoiceLTC(int i,int j) {
	TextColor(j);
	if (i == 0) {
		gotoxy(76,11);
		cout << "THEM LOP TIN CHI";
	}
	if (i == 1) {
		gotoxy(77,11+7);
		cout << "XOA LOP TIN CHI";
	}
	if (i == 2) {
		gotoxy(74,11+14);
		cout << "CHINH SUA LOP TIN CHI";
	}
	if (i == 3) {
		gotoxy(71,11+21);
		cout << "IN TAT CAC CAC LOP TIN CHI";
	}
}

void Print_Item_LTC()
{
	NODETT ds;
	DocFile_LTC(ds);
	int max = 10;
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
	gotoxy(71, HEIGHT - 1);
	TextColor(132);
	cout << "ESC: THOAT --- ENTER: CHON";
	TextColor(138);
	// in menu ra man hinh
	DrawBoxItemLTC();
	//	highlight thao tac dau tien khi mo chuong trinh
		TextColor(140);
		gotoxy(76,11);
		cout << "THEM LOP TIN CHI";
	TextColor(DEN);
	while (!exit)
	{	
		for (int i=3;i<=165;i++) {
			gotoxy(i,2);
			cout << " ";
		}
		gotoxy(79,2);
		TextColor(138);
		cout << "LOP TIN CHI";
		TextColor(DEN);
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
		else if (key == ENTER)
		{
			if (thaoTac == 0) {
				Create_LopTinChi(ds);
				GhiFile_LTC(ds);
				Clearmen();
				DrawBoxItemLTC();
			}
			else if (thaoTac == 1) {
				Clearmen();
				DrawBox(64,19,40,2);
				gotoxy(66,19);
				cout << "Nhap ma mon hoc can xoa!";
				char a[10];
				fflush(stdin);
				gotoxy(66,20);
				InputString(a,max);
				Delete_LTC_MAMONHOC(ds,a);
				GhiFile_LTC(ds);
				Clearmen();
				DrawBoxItemLTC();
			}
			else if (thaoTac == 3) {
				
				Draw_LTC(ds);
				Clearmen();
				DrawBoxItemLTC();
				for (int i=3;i<=165;i++) {
					gotoxy(i,39);
					cout << " ";
				}
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
			
		}
		//	highlight thao tac duoc chon
		ChoiceSV(thaoTac,140);
		// dua cac thao tac khac ve mau mac dinh
		TextColor(DEN);
	}
}

void DrawBoxItemMH() {
	for (int i = 0;i <= 4; i++) {
		TextColor(137);
		DrawBox(59,9+i*6,50,2);
		gotoxy(78,10);
		cout << "THEM MON HOC";
		gotoxy(79,10+6);
		cout << "XOA MON HOC";
		gotoxy(76,10+12);
		cout << "CHINH SUA MON HOC";
		gotoxy(75,10+18);
		cout << "IN DANH SACH MON HOC";
		gotoxy(78,10+24);
		cout << "LUU VAO FILE";
	}
}

void ChoiceMH(int i,int j) {
	TextColor(j);
	if (i == 0) {
		gotoxy(78,10);
		cout << "THEM MON HOC";
	}
	if (i == 1) {
		gotoxy(79,10+6);
		cout << "XOA MON HOC";
	}
	if (i == 2) {
		gotoxy(76,10+12);
		cout << "CHINH SUA MON HOC";
	}
	if (i == 3) {
		gotoxy(75,10+18);
		cout << "IN DANH SACH MON HOC";
	}
	if (i == 4) {
		gotoxy(78,10+24);
		cout << "LUU VAO FILE";
	}
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
	int So_item = 5;
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
	gotoxy(71, HEIGHT - 1);
	TextColor(132);
	cout << "ESC: THOAT --- ENTER: CHON";
	TextColor(138);
	//in menu ra man hinh
	DrawBoxItemMH();
	//	highlight thao tac dau tien khi mo chuong trinh
	ChoiceMH(thaoTac,140);
	TextColor(DEN);
	while (!exit)
	{	
		for (int i=3;i<=165;i++) {
			gotoxy(i,39);
			cout << " ";
		}
		for (int i=3;i<=165;i++) {
			gotoxy(i,2);
			cout << " ";
		}
		gotoxy(81,2);
		TextColor(138);
		cout << "MON HOC";
		TextColor(128);
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
		else if (key == ENTER)
		{
			if (thaoTac == 0) {
		
				mh = Input_Tree(kd);
				Insert_Node_Tree(kd,mh);
				Clearmen();
				DrawBoxItemMH();
			}
			else if (thaoTac == 1) {
				Clearmen();
				DeleteNode(kd,mh);
				Clearmen();
				DrawBoxItemMH();
			}
			else if (thaoTac == 3) {
				do {
					Draw_MH(kd);
					Show_Tree(kd,k);
					CTRL = getch();
					if(CTRL == PGDN)
					{
						k=k+33;
						if (k>=CountNode(kd)) {
							k=0;
						}
						XoaManHinh();
					}
					else if (CTRL == PGUP)
					{
						k=k-33;
						if (k<0) {
							k=0;
						}
						XoaManHinh();
					}
					else if (CTRL == ESC) {
						exit = true;
					}	
				} while (!exit);
				exit = false;
				Clearmen();
				DrawBoxItemMH();
			}
			else if (thaoTac == 4) {
				Clearmen();
				GhiFile_MH(kd);
				DrawBox(69,19,30,2);
				gotoxy(82,20);
				cout << "DONE";
				getch();
				Clearmen();
				DrawBoxItemMH();
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

// phan cho mh
 
void Draw_MH(PTR_NODETREE ds) {
	Clearmen();
	gotoxy(72,2);
	cout<<"DANH SACH CAC MON HOC";
	gotoxy(6,4);
	cout << "STT";
	for (int i = 4; i < HEIGHT -2; i++)
	{
		gotoxy(12, i);
		cout << char(179);
	}
	gotoxy(22,4);
	cout << "Ma MH";
	for (int i = 4; i < HEIGHT -2; i++)
	{
		gotoxy(37, i);
		cout << char(179);
	}
	gotoxy(85,4);
	cout << "Ten MH";
	for (int i = 4; i < HEIGHT -2; i++)
	{
		gotoxy(138, i);
		cout << char(179);
	}
	gotoxy(142,4); 
	cout << "So TCLT";
	for (int i = 4; i < HEIGHT -2; i++)
	{
		gotoxy(152, i);
		cout << char(179);
	}
	gotoxy(156,4);
	cout << "So TCTH";		
	TextColor(DEN);
}
// phan danh cho LTC
void Draw_LTC(NODETT ds) {
	char CTRL;
	int k=0;
	bool EXIT = true;
	Clearmen();
	for (int i=3;i<=165;i++) {
		gotoxy(i,2);
		cout << " ";
	}
	for (int i=3;i<=165;i++) {
		gotoxy(i,39);
		cout << " ";
	}
	TextColor(132);
	gotoxy(4,39);
	cout << "PAGE UP - PAGE DOWN : CHUYEN TRANG";
	while (EXIT) {
		TextColor(138);
		gotoxy(72,2);
		cout<<"DANH SACH CAC LOP TIN CHI";
		TextColor(DEN);
		gotoxy(14,4);
		cout << "STT ";
		for (int i = 4; i < HEIGHT -2; i++)
		{
			gotoxy(28, i);
			cout << char(179);
		}
		gotoxy(39,4);
		cout << "MALOPTC";
		for (int i = 4; i < HEIGHT -2; i++)
		{
			gotoxy(56, i);
			cout << char(179);
		}
		gotoxy(68,4); 
		cout << "MA MH";
		for (int i = 4; i < HEIGHT -2; i++)
		{
			gotoxy(84, i);
			cout << char(179);
		}
		gotoxy(94,4);
		cout << "NIEN KHOA";
		for (int i = 4; i < HEIGHT -2; i++)
		{
			gotoxy(112, i);
			cout << char(179);
		}
		gotoxy(123,4);
		cout << "HOC KY";
		for (int i = 4; i < HEIGHT -2; i++)
		{
			gotoxy(140, i);
			cout << char(179);
		}
		gotoxy(150,4);  
		cout << "SO SVMAX";
		Show_Data_LTC(ds,k);
		CTRL = getch();
		if(CTRL == PGDN)
		{
			k=k+33;
			if (k>=ds.n) {
				k=0;
			}
			Clearmen();
		}
		else if (CTRL == PGUP)
		{
			k=k-33;
			if (k<0) {
				k=0;
			}
			Clearmen();
		}
		else if (CTRL == ESC)
			EXIT = false;
	};
	
}
