#include "handling.h"
#include "menu.h"
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

void InputString1(char *variable, char &key, int len)
{
	int MaxNhap = len;
	if(MaxNhap == 0)
		MaxNhap = MAX_INPUT;
	rewind(stdin);
	InputSTR Nhap;
	Nhap.n = strlen(variable);
	for(int i = 0; i < Nhap.n; i++)
	{
		*Nhap.Key[i] = variable[i];
	}
	while(true)
	{
			char c = _getch();
			if(!kbhit() && !(!((int)c >= 65 && (int)c <= 90) && !((int)c >= 97 && (int)c <= 122) && c != '-' && !((int) c >= 48 && (int)c <= 57)) && Nhap.n < MaxNhap)
			{
				if (Nhap.n == 0 && (int)c>=48 && (int)c<=57 ) {
					continue;
				}
				c = toupper(c);
				Nhap.Key[Nhap.n] = new char;
				cout << c;
				*Nhap.Key[Nhap.n] = c;
				Nhap.n++;
				
			}
			if((c == '\r' || c == -32 || c == 27 || c == 13))
			{
				if(Nhap.n > 0 && *Nhap.Key[Nhap.n - 1] == '-')
				{
					gotoxy(getx() - 1, gety());
					cout << " ";
					gotoxy(getx() - 1, gety());
					if(Nhap.n > 0)
					{
						Nhap.n--;
					}
				}	
				if(c == -32)
				{
					c = _getch();
					if(c == 72) key = UP;
					if(c == 80) key = DOWN;
					break;
				}	
				if(c == 13) key = ENTER;		
				if(c == 27) key = ESC;
				break;
			}
			if(c == BACKSPACE && Nhap.n > 0)
			{
				gotoxy(getx() - 1, gety());
				cout << " ";
				gotoxy(getx() - 1, gety());
				Nhap.n--;
			}
					
	}
	for(int i = 0; i < Nhap.n; i++)
	{
		variable[i] = *Nhap.Key[i];
	}
	variable[Nhap.n] = '\0';

}

void InputNumber1(int &variable, char *num, char &key, int len)
{
	rewind(stdin);
	int MaxNhap = len;
	if(MaxNhap == 0)
		MaxNhap = MAX_INPUT;
	InputSTR Nhap;
	Nhap.n = strlen(num);
	for(int i = 0; i < Nhap.n; i++)
	{
		*Nhap.Key[i] = num[i];
	}
	while(true)
	{
			char c = _getch();
			if(Nhap.n < 11)
			{
				if(!kbhit() && (int)c >= 48 && (int)c <= 57 && Nhap.n < MaxNhap)
				{
					Nhap.Key[Nhap.n] = new char;
					cout << c;
					*Nhap.Key[Nhap.n] = c;
					Nhap.n++;
				}
			}
			if((c == '\r' || c == -32  || c == 27 || c == 13))
			{
				if(c == -32)
				{
					c = _getch();
					if(c == 72) key = UP;
					if(c == 80) key = DOWN;
				}
				if(c == 13) key = ENTER;
				if(c == 27) key = ESC;
				break;
			}
				
			if(c == BACKSPACE && Nhap.n > 0)
			{
				gotoxy(getx() - 1, gety());
				cout << " ";
				gotoxy(getx() - 1, gety());
				Nhap.n--;
			}
	}
	for(int i = 0; i < Nhap.n; i++)
	{
		num[i] = *Nhap.Key[i];
	}
	num[Nhap.n] = '\0';
	variable = atoi(num);

}

void InputStringSpace1(char *variable, char &key, int len) //ham chi cho cach 1 khoang trang
{
	int MaxNhap = len;
	if(MaxNhap == 0) 
		MaxNhap = MAX_INPUT;
	rewind(stdin);
	InputSTR Nhap;	
	Nhap.n = strlen(variable);
	for(int i = 0; i < Nhap.n; i++)
	{
		*Nhap.Key[i] = variable[i];
	}
	while(true)
	{
		if(kbhit())
		{
			char c = _getch();
			if(!kbhit() && !(!((int)c >= 65 && (int)c <= 90) && !((int)c >= 97 && (int)c <= 122) && c != ' ' && !((int) c >= 48 && (int)c <= 57)) && Nhap.n < MaxNhap)
			{
				if(Nhap.n > 0 && *Nhap.Key[Nhap.n - 1] == ' ' && c == ' ')
				{
					continue;
				}
				if (Nhap.n == 0 && (int)c>=48 && (int)c<=57 ) {
					continue;
				}
				if(!(Nhap.n == 0 && c == ' '))
				{
					if(Nhap.n == 0)
						c = toupper(c);
					else
					{
						if(*Nhap.Key[Nhap.n - 1] == ' ')
							c = toupper(c);
						else 
							c = tolower(c);
					}
					Nhap.Key[Nhap.n] = new char;
					cout << c;
					*Nhap.Key[Nhap.n] = c;
					Nhap.n++;
				}
			}
			if((c == '\r' || c == -32  || c == 27 || c == 13))
			{
				if(Nhap.n > 0 && *Nhap.Key[Nhap.n - 1] == ' ')
				{
					gotoxy(getx() - 1, gety());
					cout << " ";
					gotoxy(getx() - 1, gety());
					if(Nhap.n > 0)
					{
						Nhap.n--;
					}
				}	
				if(c == -32)
				{
					c = _getch();
					if(c == 72) key = UP;
					if(c == 80) key = DOWN;
					break;
				}
				if(c == 13) key = ENTER;				
				if(c == 27) key = ESC;
				break;
			}
			if(c == BACKSPACE && Nhap.n > 0)
			{
				gotoxy(getx() - 1, gety());
				cout << " ";
				gotoxy(getx() - 1, gety());
				Nhap.n--;
			}
		}
			
	}
	for(int i = 0; i < Nhap.n; i++)
	{
		variable[i] = *Nhap.Key[i];
	}
	variable[Nhap.n] = '\0';
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

int getx()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.X;
	return -1;
}

int gety()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.Y;
	return -1;
}

void InputString(char *variable, int max)
{
	int MaxNhap = max;
	rewind(stdin);
	InputSTR Nhap;	
	Nhap.n = 0;
	while(true)
	{
		if(kbhit())
		{
			char c = getch();
			if(!kbhit() && !(!((int)c >= 65 && (int)c <= 90) && !((int)c >= 97 && (int)c <= 122) && !((int)c>=48 && (int)c<=57)) && Nhap.n < MaxNhap)
			{
				if (Nhap.n == 0 && (int)c>=48 && (int)c<=57) {
					continue;
				}
				c = toupper(c);
				Nhap.Key[Nhap.n] = new char;
				cout << c;
				*Nhap.Key[Nhap.n] = c;
				Nhap.n++;
			}
			
			if(c == '\r')
			{
				if(Nhap.n > 0 && *Nhap.Key[Nhap.n - 1] == ' ')
				{
					gotoxy(getx() - 1, gety());
					cout << " ";
					gotoxy(getx() - 1, gety());
					if(Nhap.n > 0)
					{
						Nhap.n--;
					}
				}	
				break;
			}
			if(c == BACKSPACE && Nhap.n > 0)
			{
				gotoxy(getx() - 1, gety());
				cout << " ";
				gotoxy(getx() - 1, gety());
				Nhap.n--;
			}
		}
	}
	for(int i = 0; i < Nhap.n; i++)
	{
		variable[i] = *Nhap.Key[i];
	}
	variable[Nhap.n] = '\0';

}

void InputNumber(char *variable, int max)
{
	int MaxNhap = max;
	if(MaxNhap == 0) 
		MaxNhap = MAX_INPUT;
	rewind(stdin);
	InputSTR Nhap;	
	Nhap.n = 0;
	while(true)
	{
		if(kbhit())
		{
			char c = getch();
			if(!kbhit() && !(!((int)c>=48 && (int)c<=57)) && Nhap.n < MaxNhap)
			{
				c = toupper(c);
				Nhap.Key[Nhap.n] = new char;
				cout << c;
				*Nhap.Key[Nhap.n] = c;
				Nhap.n++;
				
			}
			if(c == '\r')
			{
				if(Nhap.n > 0 && *Nhap.Key[Nhap.n - 1] == ' ')
				{
					gotoxy(getx() - 1, gety());
					cout << " ";
					gotoxy(getx() - 1, gety());
					if(Nhap.n > 0)
					{
						Nhap.n--;
					}
				}	
				break;
			}
			if(c == BACKSPACE && Nhap.n > 0)
			{
				gotoxy(getx() - 1, gety());
				cout << " ";
				gotoxy(getx() - 1, gety());
				Nhap.n--;
			}
		}		
	}
	for(int i = 0; i < Nhap.n; i++)
	{
		variable[i] = *Nhap.Key[i];
	}
	variable[Nhap.n] = '\0';

}

void InputStringSpace(char *variable, int max) //ham chi cho cach 1 khoang trang
{
	int MaxNhap = max;
	if(MaxNhap == 0) 
		MaxNhap = MAX_INPUT;
	rewind(stdin);
	InputSTR Nhap;	
	Nhap.n = 0;
	while(true)
	{
		if(kbhit())
		{
			char c = getch();
			if(!kbhit() && !(!((int)c >= 65 && (int)c <= 90) && !((int)c >= 97 && (int)c <= 122) && c != ' ' && !((int)c>=48 && (int)c<=57)))
			{
				if(Nhap.n > 0 && *Nhap.Key[Nhap.n - 1] == ' ' && c == ' ')
				{
					continue;
				}
				if (Nhap.n == 0 && (int)c>=48 && (int)c<=57 ) {
					continue;
				}
				if(!(Nhap.n == 0 && c == ' '))
				{
					if(Nhap.n == 0)
						c = toupper(c);
					else
					{
						if(*Nhap.Key[Nhap.n - 1] == ' ')
							c = toupper(c);
						else 
							c = tolower(c);
					}
					Nhap.Key[Nhap.n] = new char;
					cout << c;
					*Nhap.Key[Nhap.n] = c;
					Nhap.n++;
				}
			}
			if(c == '\r')
			{
				if(Nhap.n > 0 && *Nhap.Key[Nhap.n - 1] == ' ')
				{
					gotoxy(getx() - 1, gety());
					cout << " ";
					gotoxy(getx() - 1, gety());
					if(Nhap.n > 0)
					{
						Nhap.n--;
					}
				}	
				break;
			}
			if(c == BACKSPACE && Nhap.n > 0)
			{
				gotoxy(getx() - 1, gety());
				cout << " ";
				gotoxy(getx() - 1, gety());
				Nhap.n--;
			}
		}
			
	}
	for(int i = 0; i < Nhap.n; i++)
	{
		variable[i] = *Nhap.Key[i];
	}
	variable[Nhap.n] = '\0';
}



