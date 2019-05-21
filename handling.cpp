#include "handling.h"

using namespace std;

int Find_Space(char *a) { 
	for (int i=0;i<strlen(a);i++) {
		if (a[i] == 32) {
			return FALSE;
		}
	}
	return TRUE;
}

char* Trim (char *s) { // ham cat khoang trang dau va cuoi chuoi (giua cac ki tu chi co 1 khoang trang )
	int i=0,n,j,dem;
	dem=0;
	n=strlen(s);
    while (s[i]) i++ ;
    while (s[i-1]==32) i--;
    s[i] = 0 ;
    while (*s == 32) s++;
	while (s[i] == ' ') {
		s[i] = s[i+1];
		i++;
	}	
	for(i=0;i<n;i++) {
		if((s[i]==' ')&&(s[i+1]==' ')) {
			for(j=i;j<n;j++) {
				s[j]=s[j+1];
			}
				n--;	//so ki tu cua chuoi giam xuong
				i--;	//sau buoc nay thi i se tang (vong for) nen ta se giam no xuong
		}
	}
	return s;
}

int NumberOnly (char *a) {
	
	for (int i=0;i<strlen(a);i++){
		if (a[i] < 48 || a[i] > 57 ) {
			return FALSE;
		}	
	}
	return TRUE;
}

void gotoxy(int x, int y)
{
  static HANDLE h = NULL;  
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };  
  SetConsoleCursorPosition(h,c);
}

void XoaManHinh()
{
	HANDLE                     hStdOut;
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  DWORD                      count;
  DWORD                      cellCount;
  COORD                      homeCoords = { 0, 0 };

  hStdOut = GetStdHandle( STD_OUTPUT_HANDLE );
  if (hStdOut == INVALID_HANDLE_VALUE) return;

  /* Get the number of cells in the current buffer */
  if (!GetConsoleScreenBufferInfo( hStdOut, &csbi )) return;
  cellCount = csbi.dwSize.X *csbi.dwSize.Y;

  /* Fill the entire buffer with spaces */
  if (!FillConsoleOutputCharacter(
    hStdOut,
    (TCHAR) ' ',
    cellCount,
    homeCoords,
    &count
    )) return;

  /* Fill the entire buffer with the current colors and attributes */
  if (!FillConsoleOutputAttribute(
    hStdOut,
    csbi.wAttributes,
    cellCount,
    homeCoords,
    &count
    )) return;

  /* Move the cursor home */
  SetConsoleCursorPosition( hStdOut, homeCoords );
}

void TextColor(int x)
{
	HANDLE mau;
	mau=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}
