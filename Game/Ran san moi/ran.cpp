// Mo phong game ran san moi
// Thu vien ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <ctime>
// Thu vien ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//


// Bien hang so ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
using namespace std;
const short n = 28, m = 119;
// Bien hang so ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//


// Van toc & gia toc di nguyen
const int doc = 150, ngang = 50;
short dx = 1, dy = 0;


// Bien so ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
int diem = 3;
int len_snake = 3;
struct ToaDo { short x, y; };
ToaDo ran[10000], moi;
// Bien so ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//


// Chuong trinh con ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// Phan xu ly mau sac----------------------------------------------------------------------------------
void TextColor(char x) {
    HANDLE mau = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(mau, x);
}

void MauDoiTuong(char c, char mau) {
    TextColor(mau);
    cout << c;
}

void TextBrackground() {
    HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(screen, 1);
}
// Phan xu ly mau sac----------------------------------------------------------------------------------


// Phan ham xu ly hinh anh ----------------------------------------------------------------------------
// An con tro chuot
void HidenPoint() {
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}

// Di chuyen con tro
void Goto(short x, short y) {
    HANDLE time = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position = {x, y};
    SetConsoleCursorPosition(time, position);
    HidenPoint();
}

// In diem so 
void HienThiDiem() {
    Goto(0, 0);
    TextColor(6);
    cout << "Diem: " << diem << endl;
}

// Hien thi ma tran, ram & moi
void HienThiTuong() {
    TextBrackground();
    for (int i = 0; i <= n; i++) {
        Goto(0, 1 + i);
        for (int j = 0; j <= m; j++) {
            if (i == 0 || i == n || j == 0 || j == m) cout << "#";
            else cout << " ";
        }
        cout << (i == n ? "" : "\n");
    }
}

// In Ran
void InRan() {
    for (int i = 0; i < len_snake; i++) {
        Goto(ran[i].x, ran[i].y + 1);
        if (i == len_snake-1) MauDoiTuong('X', 2);
        else MauDoiTuong('O', 2);
    }
}
// Phan ham xu ly hinh anh ----------------------------------------------------------------------------


// Xy ly con ran di chuyen & moi-----------------------------------------------------------------------
// Random vi tri cua moi !
void Random() {
    srand((unsigned short)time(0));
    moi.y = rand() % (n-2) + 1;
    moi.x = rand() % (m-2) + 1;
}

// Huong di chuyen khi nhan phim
void HuongDiChuyen(char c, short& dx, short& dy, int& thoi_gian) {
    // Xu ly huong di chuyen
    if (c == 72 && dy == 0) { dx = 0; dy = -1; }            // di len
    else if (c == 80 && dy == 0) { dx = 0; dy = 1; }        // di xuong
    else if (c == 75 && dx == 0) { dx = -1; dy = 0; }       // di sang trai
    else if (c == 77 && dx == 0) { dx = 1; dy = 0; }        // di sang phai
    
    // Xu ly toc do di chuyen
    if (c == 72 || c == 80) thoi_gian = doc;
    if (c == 75 || c == 77) thoi_gian = ngang;
}

// Ham ket qua game- dung tro choi !
bool GameOver(ToaDo r) {
    // Ran dung tuong
    short y = r.y, x = r.x;
    if (y <= 0 || y >= n || x <= 0 || x >= m)
        return true;

    // Ran tu dam vao chinh minh
    for (int i = 0; i < len_snake; i++) {
        if (y == ran[i].y && x == ran[i].x)
            return true;
    }
    return false;
}

// Bat dau game
void BatDauGame() {
    system("cls");
    ran[0].y = 3; ran[0].x = 1;
    ran[1].y = 3; ran[1].x = 2;
    ran[2].y = 3; ran[2].x = 3;
}

// Kiem tra moi co o tren nguoi ran hay khong ?
bool MoiTrenRan(ToaDo ran[], ToaDo moi) {
    for (int i = 0; i < len_snake; i++) {
        if (ran[i].y == moi.y && ran[i].x == moi.x)
            return true;
    }
    return false;
}

// Sinh ra moi khong nam tren minh ran
void SinhMoi() {
    while (true) {
        Random();
        if (!MoiTrenRan(ran, moi)) {
            Goto(moi.x, moi.y + 1);
            MauDoiTuong('X', 4);
            return;
        }
    }
}

bool RanAnDuocMoi(ToaDo ran, ToaDo moi) {
    if (ran.x == moi.x && ran.y == moi.y)
        return true;
    return false;
}

void ChuyenViTriRan(ToaDo ran[], int len_snake) {
    Goto(ran[0].x, ran[0].y+1);
    TextColor(1);
    cout << ' ';
    for (int i = 0; i < len_snake; i++) {
        ran[i] = ran[i+1];
    }
}
// Xy ly con ran di chuyen & moi-----------------------------------------------------------------------
// Chuong trinh con ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//


// Ham xu ly trong game
void Game() {
    char c;
    int thoi_gian = ngang;
    BatDauGame();
    HienThiDiem();
    HienThiTuong();
    SinhMoi();
    while (c != 27) {
        while (!kbhit()) {
            // Lay toa do dau ran tiep theo
            ran[len_snake].x = ran[len_snake-1].x + dx;
            ran[len_snake].y = ran[len_snake-1].y + dy;
            if (GameOver(ran[len_snake])) return;

            // Kiem tra xem ran co an duoc moi hay khong ?
            if (RanAnDuocMoi(ran[len_snake], moi)) {
                SinhMoi();
                ++diem;
                HienThiDiem();
                ++len_snake;
            }
            else ChuyenViTriRan(ran, len_snake);

            InRan();
            Sleep(thoi_gian);
        }
        c = getch();
        HuongDiChuyen(c, dx, dy, thoi_gian);
    }
}

// Ham chinh
int main() {
    Game();
    Goto(m/2-5,n/2);
    cout << "GAME OVER !" << endl;
    getch();
} 