#pragma once
#include "loptinchi.h"

#define ENTER 13
#define ESC 27
#define TAB 9
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define SPACE 32
#define PGUP 73
#define PGDN 81

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
void DrawScreen();
void ReMenu();
void Menu();

//phan cho mh
void Draw_MH(PTR_NODETREE ds,ARR arr[]);
void Print_Item_MH();
void Draw_Item_MH();
// phan cho ltc
void Draw_LTC(NODETT ds);
void Print_Item_LTC();
void Draw_Item_LTC();
// phan cho sv
void Print_Item_SV();
void Draw_Item_SV();
// phan cho bd
void Print_Item_BD();
void Draw_Item_BD();
