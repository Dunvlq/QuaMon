#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <string.h>
#include <conio.h>
#include <windows.h>
#define TRUE 1
#define FALSE 0



int Find_Space(char *a);
int NumberOnly (char *a);
char* Trim (char *s);
void gotoxy(int x, int y);
void XoaManHinh();
void TextColor(int x);
void resizeConsole(int width, int height);
