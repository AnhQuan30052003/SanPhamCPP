// Chuong trinh tro choi caro cho 2 nguoi
// Thu vien
#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;

// Bien va hang so
const int n = 28, m = 119;
char a[n+1][m+1];
int y = 14, x = 59, dy, dx, ty, tx;
int dem_x = 1, dem_o = 1, dem_danh_x = 0, dem_danh_o = 0;
int thang = -1; // 1 la X, 2 la O

// Gia toc kiem tra va huong di chuyen
int huong;
int xx[4] = { 0,+1,+1,+1};
int yy[4] = {+1,+1, 0,-1};

// Ham doi mau
void TextColor(char mau) {
    HANDLE q = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(q, mau);
}

// Ham di chuyen con tro
void Gotoxy(short x, short y) {
    HANDLE q = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD p = {x,y};
    SetConsoleCursorPosition(q, p);
}

// Bat dau in tu dong thu 1
void InBanCo() {
    TextColor(1);
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0 || i == n || j == m) a[i][j] = '#';
            else a[i][j] = '.';
        }
    }
    Gotoxy(0, 1);
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++)
            cout << a[i][j];
        cout << (i == n ? "" : "\n");
    }
}

// Luon danh ! - in ra dong 0
void Luoc(int x) {
    Gotoxy(0,0);
    char c;
    if (x == 1) {
        c = 'X';
        TextColor(4);
    }
    else {
        c = 'O';
        TextColor(6);
    }
    cout << "[Turn]: " << c;
}

// Ra soat dieu kien thang
void Thu(int x, int y, int dem, int dau_thang, char ki_tu) {
	if (thang == dau_thang) return;
	for (int i = 0; i < 4; i++) {
		int p = x + xx[i];
		int q = y + yy[i];
		if (a[p][q] == ki_tu) {
			if (dem == 1) {
				huong = i;
			}
			if (i == huong) {
				x = p;
				y = q;
				++dem;
				if (dem == 5) {
					thang = dau_thang;
                    return;
				}
				Thu(x, y, dem, dau_thang, ki_tu);
	            if (thang == dau_thang) return;
				--dem;
				x -= xx[i];
				y -= yy[i];
			}
			else continue;
		}
	}
}

// Kiem tra thang
bool KiemTraThang() {
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (thang == -1 && a[i][j] == 'X') Thu(i, j, dem_x, 1,'X');
            if (thang == -1 && a[i][j] == 'O') Thu(i, j, dem_o, 2,'O');
            if (thang != -1) return true;
        }
    }
    return false;
}

int main() {
    cout << "Tro choi CARO!";
    getch();
    system("cls");
    Luoc(1);
    InBanCo();

    // quy uoc 1 la X. 2 la O
    int k = 1;
    char c;
    Gotoxy(x, y);
    while (c != 27) { 
        // Lay phim !
        c = getch();
        // Phim di chuyen !
        if (c == 72 || c == 80 || c == 75 || c == 77) {
            if (c == 72 && y > 2) { dy = -1; dx = 0; }  // len
            if (c == 80 && y < n-1) { dy = 1; dx = 0; } // xuong
            if (c == 75 && x > 1) { dx = -1; dy = 0; }  // trai
            if (c == 77 && x < m-1) { dx = 1; dy = 0; } // phai
            y += dy; x += dx;
        }
        // Phim danh !
        else if (c == 32 && a[y][x] == '.') {
            if (k == 1) {
                a[y][x] = 'X';
                ty = y; tx = x;
                TextColor(4);
                cout << 'X';
                ++dem_danh_x;
                k = 2;
                Luoc(k);
            }
            else {
                a[y][x] = 'O';
                ty = y; tx = x;
                TextColor(6);
                cout << 'O';
                ++dem_danh_o;
                k = 1;
                Luoc(k);
            }
            if (dem_danh_x >= 5 || dem_danh_o >= 5) {
                if (KiemTraThang()) {
                    char t;
                    if (thang == 1) {
                        t = 'X';
                        TextColor(4);
                    }
                    else {
                        t = 'O';
                        TextColor(6);
                    }
                    Gotoxy(0,0);
                    cout << "======================================================[  " << t << " WIN  ]======================================================";
                    getch();
                    break;
                }

                if (dem_danh_x + dem_danh_o == (n-1)*(m-1)) {
                    Gotoxy(0,0);
                    TextColor(7);
                    cout << "======================================================[  DRAW  ]=======================================================";
                    getch();
                    break;
                }
            }
        }
        // Xu ly xoa
        else if (c == 8 && ty == y && tx == x) {
            a[y][x] = '.';
            TextColor(1);
            cout << '.';
            if (k == 2) k = 1;
            else k = 2;
            Luoc(k);
        }
        Gotoxy(x, y);
    }
}