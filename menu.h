#pragma once
#include "loptinchi.h"

#define ENTER 13
#define ESC 27
#define TAB 9
#define UP 72
#define DOWN 80
#define Left 75
#define Right 77
#define SPACE 32
#define PGUP 73
#define PGDN 81
#define F7 118
#define F8 119
#define F9 120
#define F10 121
#define F11 122
#define F12 123
#define BACKSPACE 8

#define WIDTH 168
#define HEIGHT 40

#define DEN 128
#define LAMDAM 129
#define LUCDAM 130
#define DATROIDAM 131
#define DODAM 132
#define HONGDAM 133
#define VANGDAM 134
#define TRANGDAM 135
#define XAM 136
#define LAM 137
#define LUC 138
#define DATROI 139
#define DO 140
#define HONG 141
#define VANG 142
#define TRANG 143
#define HIGHTLIGHT 176

void DrawBox(int x, int y, int width, int height);
void DrawBoxItem();
void Choice(int i,int j);
void DrawScreen();
void ReMenu();
void Menu();
void Clearmen();

//phan cho mh
void Draw_MH(PTR_NODETREE ds);
void Print_Item_MH();
void DrawBoxItemMH();
void ChoiceMH(int i,int j);
// phan cho ltc
void Draw_LTC(NODETT ds);
void Print_Item_LTC();
void DrawBoxItemLTC();
void ChoiceLTC(int i,int j);
// phan cho sv
void Print_Item_SV();
void DrawBoxItemSV();
void ChoiceSV(int i,int j);
// phan cho bd
void Print_Item_BD();
void DrawBoxItemBD();
void ChoiceBD(int i,int j);
