#include "menu.h"

using namespace std;

string tieude = "CHUONG TRINH QUAN LY SINH VIEN";

void DrawScreen()
{
	
	gotoxy((WIDTH / 2 - tieude.length() / 2), 2);
	TextColor(LUC);
	cout << tieude;
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
	cout << "\n\n";
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

void Print_Item_LTC()
{
	int thaoTac = 0;	
	bool exit = false;
	int So_item = 4;
	TextColor(DEN);
	DrawScreen();
	//	in tieu de chuong trinh
	gotoxy((WIDTH / 2 - tieude.length() / 2), 2);
	TextColor(LUC);
	cout << tieude;
	string *item = new string[So_item];
	item[0] = "THEM SINH VIEN";
	item[1] = "XOA SINH VIEN";
	item[2] = "SUA THONG TIN SINH VIEN";
	item[3] = "IN DANH SACH SINH VIEN";
	gotoxy(71, HEIGHT - 1);
	TextColor(132);
	cout << "ESC: THOAT --- ENTER: CHON";
	TextColor(138);
	//in menu ra man hinh
	for (int i = 0; i < So_item; i++)
	{
		gotoxy((WIDTH / 2 - 12), i + 20);
		TextColor(DEN);
		cout << item[i] << endl;
	}
	//	highlight thao tac dau tien khi mo chuong trinh
	gotoxy((WIDTH / 2 - 12), 20);
	TextColor(HIGHTLIGHT);
	cout << item[thaoTac];
	TextColor(DEN);
	while (!exit)
	{	
		char key;
		key = getch();
		if (key == UP)
		{
			gotoxy((WIDTH / 2 - 12), thaoTac + 20);
			TextColor(DEN);
			cout << item[thaoTac];
			if (thaoTac == 0)
				thaoTac = So_item - 1;
			else thaoTac--;			
		}
		else if (key == DOWN)
		{
			gotoxy((WIDTH / 2 - 12), thaoTac + 20);
			TextColor(DEN);
			cout << item[thaoTac];
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
		gotoxy((WIDTH / 2 - 12), thaoTac + 20);
		TextColor(HIGHTLIGHT);
		cout << item[thaoTac];
		// dua cac thao tac khac ve mau mac dinh
		TextColor(DEN);
	}
}

void Print_Item_SV()
{
	int thaoTac = 0;	
	bool exit = false;
	int So_item = 4;
	TextColor(DEN);
	DrawScreen();
	//	in tieu de chuong trinh
	gotoxy((WIDTH / 2 - tieude.length() / 2), 2);
	TextColor(LUC);
	cout << tieude;
	string *item = new string[So_item];
	item[0] = "THEM SINH VIEN";
	item[1] = "XOA SINH VIEN";
	item[2] = "SUA THONG TIN SINH VIEN";
	item[3] = "IN DANH SACH SINH VIEN";
	gotoxy(71, HEIGHT - 1);
	TextColor(132);
	cout << "ESC: THOAT --- ENTER: CHON";
	TextColor(138);
	//in menu ra man hinh
	for (int i = 0; i < So_item; i++)
	{
		gotoxy((WIDTH / 2 - 12), i + 20);
		TextColor(DEN);
		cout << item[i] << endl;
	}
	//	highlight thao tac dau tien khi mo chuong trinh
	gotoxy((WIDTH / 2 - 12), 20);
	TextColor(HIGHTLIGHT);
	cout << item[thaoTac];
	TextColor(DEN);
	while (!exit)
	{	
		char key;
		key = getch();
		if (key == UP)
		{
			gotoxy((WIDTH / 2 - 12), thaoTac + 20);
			TextColor(DEN);
			cout << item[thaoTac];
			if (thaoTac == 0)
				thaoTac = So_item - 1;
			else thaoTac--;			
		}
		else if (key == DOWN)
		{
			gotoxy((WIDTH / 2 - 12), thaoTac + 20);
			TextColor(DEN);
			cout << item[thaoTac];
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
		gotoxy((WIDTH / 2 - 12), thaoTac + 20);
		TextColor(HIGHTLIGHT);
		cout << item[thaoTac];
		// dua cac thao tac khac ve mau mac dinh
		TextColor(DEN);
	}
}

void Print_Item_MH()
{
	int thaoTac = 0;	
	bool exit = false;
	int So_item = 4;
	TextColor(DEN);
	DrawScreen();
	//	in tieu de chuong trinh
	gotoxy((WIDTH / 2 - tieude.length() / 2), 2);
	TextColor(LUC);
	cout << tieude;
	string *item = new string[So_item];
	item[0] = "THEM MON HOC";
	item[1] = "XOA MON HOC";
	item[2] = "CHINH SUA MON HOC";
	item[3] = "IN DANH SACH MON HOC";
	gotoxy(71, HEIGHT - 1);
	TextColor(132);
	cout << "ESC: THOAT --- ENTER: CHON";
	TextColor(138);
	//in menu ra man hinh
	for (int i = 0; i < So_item; i++)
	{
		gotoxy((WIDTH / 2 - 11), i + 20);
		TextColor(DEN);
		cout << item[i] << endl;
	}
	//	highlight thao tac dau tien khi mo chuong trinh
	gotoxy((WIDTH / 2 - 11), 20);
	TextColor(HIGHTLIGHT);
	cout << item[thaoTac];
	TextColor(DEN);
	while (!exit)
	{	
		char key;
		key = getch();
		if (key == UP)
		{
			gotoxy((WIDTH / 2 - 11), thaoTac + 20);
			TextColor(DEN);
			cout << item[thaoTac];
			if (thaoTac == 0)
				thaoTac = So_item - 1;
			else thaoTac--;			
		}
		else if (key == DOWN)
		{
			gotoxy((WIDTH / 2 - 11), thaoTac + 20);
			TextColor(DEN);
			cout << item[thaoTac];
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
		gotoxy((WIDTH / 2 - 11), thaoTac + 20);
		TextColor(HIGHTLIGHT);
		cout << item[thaoTac];
		// dua cac thao tac khac ve mau mac dinh
		TextColor(DEN);
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
	gotoxy((WIDTH / 2 - tieude.length() / 2), 2);
	TextColor(LUC);
	cout << tieude;
	string *item = new string[So_item];
	item[0] = "NHAP DIEM";
	item[1] = "IN BANG DIEM MON HOC";
	item[2] = "IN BANG DIEM TRUNG BINH KET THUC KHOA HOC";
	item[3] = "BANG DIEM TONG KET CUA SINH VIEN";	
	gotoxy(71, HEIGHT - 1);
	TextColor(132);
	cout << "ESC: THOAT --- ENTER: CHON";
	TextColor(138);
	//in menu ra man hinh
	for (int i = 0; i < So_item; i++)
	{
		gotoxy((WIDTH / 2 - 19), i + 20);
		TextColor(DEN);
		cout << item[i] << endl;
	}
	//	highlight thao tac dau tien khi mo chuong trinh
	gotoxy((WIDTH / 2 - 19), 20);
	TextColor(HIGHTLIGHT);
	cout << item[thaoTac];
	TextColor(DEN);
	while (!exit)
	{	
		char key;
		key = getch();
		if (key == UP)
		{
			gotoxy((WIDTH / 2 - 19), thaoTac + 20);
			TextColor(DEN);
			cout << item[thaoTac];
			if (thaoTac == 0)
				thaoTac = So_item - 1;
			else thaoTac--;			
		}
		else if (key == DOWN)
		{
			gotoxy((WIDTH / 2 - 19), thaoTac + 20);
			TextColor(DEN);
			cout << item[thaoTac];
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
		gotoxy((WIDTH / 2 - 19), thaoTac + 20);
		TextColor(HIGHTLIGHT);
		cout << item[thaoTac];
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
	string *item = new string[So_item];
	item[0] = "LOP TIN CHI";
	item[1] = "SINH VIEN";
	item[2] = "MON HOC ";
	item[3] = "BANG DIEM";
	gotoxy(71, HEIGHT - 1);
	TextColor(DODAM);
	cout << "ESC: THOAT --- ENTER: CHON";
	//in menu ra man hinh
	for (int i = 0; i < So_item; i++)
	{
		gotoxy((WIDTH / 2 - 6), i + 20);
		TextColor(DEN);
		cout << item[i] << endl;
	}
	//	highlight thao tac dau tien khi mo chuong trinh
	gotoxy((WIDTH / 2 - 6), 20);
	TextColor(HIGHTLIGHT);
	cout << item[thaoTac];
	TextColor(DEN);
	while (!exit)
	{	
		char key;
		key = getch();
		if (key == UP)
		{
			gotoxy((WIDTH / 2 - 6), thaoTac + 20);
			TextColor(DEN);
			cout << item[thaoTac];
			if (thaoTac == 0)
				thaoTac = So_item - 1;
			else thaoTac--;			
		}
		else if (key == DOWN)
		{
			gotoxy((WIDTH / 2 - 6), thaoTac + 20);
			TextColor(DEN);
			cout << item[thaoTac];
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
				XoaManHinh();
				Print_Item_SV();
				XoaManHinh();
				DrawScreen();
				//	in tieu de chuong trinh
				gotoxy((WIDTH / 2 - tieude.length() / 2), 2);
				TextColor(LUC);
				cout << tieude;
				gotoxy(71, HEIGHT - 1);
				TextColor(DODAM);
				cout << "ESC: THOAT --- ENTER: CHON";
				//in menu ra man hinh
				for (int i = 0; i < So_item; i++)
				{
					gotoxy((WIDTH / 2 - 6), i + 20);
					TextColor(DEN);
					cout << item[i] << endl;
				}
			}
			else if (thaoTac == 1)
			{
				XoaManHinh();
				Print_Item_SV();
				XoaManHinh();
				DrawScreen();
				//	in tieu de chuong trinh
				gotoxy((WIDTH / 2 - tieude.length() / 2), 2);
				TextColor(LUC);
				cout << tieude;
				gotoxy(71, HEIGHT - 1);
				TextColor(DODAM);
				cout << "ESC: THOAT --- ENTER: CHON";
				//in menu ra man hinh
				for (int i = 0; i < So_item; i++)
				{
					gotoxy((WIDTH / 2 - 6), i + 20);
					TextColor(DEN);
					cout << item[i] << endl;
				}
			}
			else if (thaoTac == 2)
			{
				XoaManHinh();
				Print_Item_MH();
				XoaManHinh();
				DrawScreen();
				//	in tieu de chuong trinh
				gotoxy((WIDTH / 2 - tieude.length() / 2), 2);
				TextColor(LUC);
				cout << tieude;
				gotoxy(71, HEIGHT - 1);
				TextColor(DODAM);
				cout << "ESC: THOAT --- ENTER: CHON";
				//in menu ra man hinh
				for (int i = 0; i < So_item; i++)
				{
					gotoxy((WIDTH / 2 - 6), i + 20);
					TextColor(DEN);
					cout << item[i] << endl;
				}
			}
			else if (thaoTac == 3)
			{
				XoaManHinh();
				Print_Item_BD();
				XoaManHinh();
				DrawScreen();
				//	in tieu de chuong trinh
				gotoxy((WIDTH / 2 - tieude.length() / 2), 2);
				TextColor(LUC);
				cout << tieude;
				gotoxy(71, HEIGHT - 1);
				TextColor(DODAM);
				cout << "ESC: THOAT --- ENTER: CHON";
				//in menu ra man hinh
				for (int i = 0; i < So_item; i++)
				{
					gotoxy((WIDTH / 2 - 6), i + 20);
					TextColor(DEN);
					cout << item[i] << endl;
				}
			}
		}
		//	highlight thao tac duoc chon
		gotoxy((WIDTH / 2 - 6), thaoTac + 20);
		TextColor(HIGHTLIGHT);
		cout << item[thaoTac];
		// dua cac thao tac khac ve mau mac dinh
		TextColor(DEN);
	}
}

// phan cho mh
 
void Draw_MH(PTR_NODETREE ds) {
	XoaManHinh();
	gotoxy(72,2);
	cout<<"DANH SACH CAC MON HOC";
	gotoxy(6,4);
	cout << "STT";
	for (int i = 4; i < HEIGHT -1; i++)
	{
		gotoxy(12, i);
		cout << "|";
	}
	gotoxy(22,4);
	cout << "Ma MH";
	for (int i = 4; i < HEIGHT -1; i++)
	{
		gotoxy(37, i);
		cout << "|";
	}
	gotoxy(85,4);
	cout << "Ten MH";
	for (int i = 4; i < HEIGHT -1; i++)
	{
		gotoxy(138, i);
		cout << "|";
	}
	gotoxy(142,4); 
	cout << "So TCLT";
	for (int i = 4; i < HEIGHT -1; i++)
	{
		gotoxy(152, i);
		cout << "|";
	}
	gotoxy(156,4);
	cout << "So TCTH";
	for (int i=1;i<=CountNode(ds);i++) {
		gotoxy(6,i+4);
		cout << i;
	}
	
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
