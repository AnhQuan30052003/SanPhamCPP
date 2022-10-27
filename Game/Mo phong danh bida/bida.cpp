#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;

// Cac bien so
const int n = 29, m = 119;
int y, x;           // Toa do ban dau cua banh banh
int dy = 1, dx = 1; // Gia toc di chuyen

// An con tro
void Nocursortype() {
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = false;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}

// Di chuyen con tro
void Goto(short x, short y) {
    HANDLE time = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = {x, y};
    SetConsoleCursorPosition(time, pos);
    Nocursortype();
}

// Tao mau cho chu
void TextColor(int x) {
    HANDLE mau = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(mau, x);
}

// Mau nen - backgound
void TextBackground() {
    HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(screen, 1);
}

// Hien thi mau chu
void MauChu(char c) {
    TextColor(6);
    cout << c;
    TextColor(7);
}

// Hien thi man hinh
void HIenThiBang() {
    TextBackground();
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0 || i == n || j == m) cout << "#";
            else cout << ' ';
        }
        cout << (i == n ? "" : "\n");
    }
}

// hello nha

// Huong tiep theo nen chuyen toi
void BanhLan() {
    if (y + dy <= 0) dy = 1;
    else if (y + dy >= n) dy = -1;
    if (x + dx <= 0) dx = 1;
    else if (x + dx >= m) dx = -1;

    Goto(x+dx, y+dy);
    MauChu('O');
    Goto(x, y);
    cout << ' ';
}

int main() {
    cout << "Nhap toa do ban dau cua qua bida (y,x): ";
    cin >> y >> x;
    system("cls");

    HIenThiBang();
    while (true) {
        BanhLan();
        y += dy; x += dx;
        Sleep(100);
    }
}
