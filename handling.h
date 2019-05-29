#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <fstream>
#include <string.h>
#include <conio.h>
#include <windows.h>
#define TRUE 1
#define FALSE 0
#define MAX_INPUT 255
#define BACKSPACE 8
struct InputSTR {
	unsigned int n;
	char *Key[MAX_INPUT];
};

int Find_Space(char *a);
int NumberOnly (char *a);
char* Trim (char *s);
void gotoxy(int x, int y);
void XoaManHinh();
void TextColor(int x);
void resizeConsole(int width, int height);
int getx();
int gety();
void InputString(char *variable, int max); //ham nhap chuoi khong co khoang trang
void InputStringSpace(char *variable, int max);
void InputNumber(char *variable, int max); // ham chi duoc nhap so

