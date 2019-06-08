#include "handling.h"
#define MAXSV 100

using namespace std;

struct danhsachsinhvien{
	char MASV[15];
	char HO[30];
	char TEN[10];
	char SEX[10];
	int SDT;
	char MALOP[15];
};
typedef struct danhsachsinhvien DSSV;

struct nodesinhvien{
	DSSV SINHVIEN;
	struct nodesinhvien *next;
};
typedef struct nodesinhvien NODESV;
typedef NODESV* PTR_NODESV;

struct linklistsinhvien{
	NODESV *FIRSTSV;
	NODESV *LASTSV;
};
typedef struct linklistsinhvien LISTSV;


void tao_list(LISTSV &l); //khoi tao dskld
NODESV* KhoitaoNodeSV(DSSV ds); //cap phat vung nho
void add_last(LISTSV &l, NODESV *p); //them vao cuoi ds lkd.
int Empty(LISTSV &l); //ham kiem tra danh sach rong
int ktmasv(LISTSV l,char s[]); //kiem tra ma sinh vien da co chua
char* chuyenstringquachar(string str);
void Giai_Phong_Vung_Nho(LISTSV &l); //hàm giai phóng vùng nho cho danh sách liên ket don
void Ghi_File_1SV(DSSV &ds); // hàm ghi thông tin sinh viên vào file
void Doc_File(LISTSV &l); //doc thong tin sv trong file
DSSV Nhapsv1lop(LISTSV l); //nhap dssv cua 1 lop
void input(LISTSV &l); //ham nhap nhieu node dssv
void xuat(DSSV *arrtemp,int i,int k); //ham xuat 1 sinh vien
void output(LISTSV l, int k); // hàm xuat danh sách sinh viên
void Del_First(LISTSV &l); // hàm xóa dau danh sach
void Del_Last(LISTSV &l); //ham xoa cuoi danh sach
DSSV Traverse2(DSSV ds, LISTSV l);
void clearlist(LISTSV &l); //ham xoa toan bo danh sach
// danh sach dang ki

struct danhsachdangki { // cau truc danh sach dang ki
	int MASV; 
	float DIEM;
};
typedef struct danhsachdangki DSDK;

struct nodedangki { // node cua danh sach lien ket don	
	DSDK DANGKI;
	struct nodedangki *NEXT;
};
typedef struct nodedangki NODEDK;

struct linkedlistdangki { // hai con tro quan li danh sach lien ket don 
	DSDK *FIRSTDK; // con tro first cua danh sach dang ki
	DSDK *LASTDK; // con tro last cua danh sach dang ki
};
typedef struct linkedlistdangki LISTDK;


