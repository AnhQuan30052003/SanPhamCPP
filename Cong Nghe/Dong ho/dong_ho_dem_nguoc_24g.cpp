#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

// các hằng số !
const short n = 9, m = 77;      // Kích thước viền
const short xd = 21, yd = 9;    // Tọa độ bảng viền
const short g1 = 5, g2 = 15;    // Tọa độ in giờ
const short p1 = 29, p2 = 39;   // Tọa độ in phút
const short j1 = 53, j2 = 63;   // Tọa độ in giây
const short d1 = 24, d2 = 48;   // Tạo độ in dấu ngăn cách

// Thay đổi màu
void Color(short mau) {
    HANDLE t = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(t, mau);
}

// Ẩn con trỏ chuột trên màn hình Console
void HidenPoint() {
    HANDLE t = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO p;
    p.bVisible = false;
	p.dwSize = 20;
    SetConsoleCursorInfo(t, &p);
}

// Di chuyển con trỏ màn hình
void Gotoxy(short x, short y) {
    HANDLE t = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = {x, y};
    SetConsoleCursorPosition(t, pos);
}

// Chữ só quy ước: 0_9
string so[11] = {"||||||||||||   ||||||   ||||||   ||||||||||||",
                "      |||      |||      |||      |||      |||",
                "|||||||||      |||||||||||||||      |||||||||",
                "|||||||||      ||||||||||||      ||||||||||||",
                "|||   ||||||   ||||||||||||      |||      |||",
                "||||||||||||      |||||||||      ||||||||||||",
                "||||||||||||      ||||||||||||   ||||||||||||",
                "|||||||||      |||      |||      |||      |||",
                "||||||||||||   |||||||||||||||   ||||||||||||",
                "||||||||||||   ||||||||||||      ||||||||||||",
                "      |||       |||      "};

// HIển thị số ra màn hình
void In(short so_in, short x, short y) {
    short x_tam = x;
    int dem = 0;
    for (char s : so[so_in]) {
        Gotoxy(x, y);
        cout << s;
        dem += 1;
        if (dem % 9 == 0) {
            y += 1;
            x = x_tam;
        }
        else x += 1;
    }
}

// In giờ
void InGio(short gio) {
    Color(12);
    if (gio < 10) {
        In(0, g1 + xd, 11);
        In(gio, g2 + xd, 11);
    }
    else {
        short so_dau = gio/10, so_cuoi = gio%10;
        In(so_dau, g1 + xd, 11);
        In(so_cuoi, g2 + xd, 11);
    }
}

// In phút
void InPhut(short phut) {
    Color(6);
    if (phut < 10) {
        In(0, p1 + xd, 11);
        In(phut, p2 + xd, 11);
    }
    else {
        short so_dau = phut/10, so_cuoi = phut%10;
        In(so_dau, p1 + xd, 11);
        In(so_cuoi, p2 + xd, 11);
    }
}

// In giây
void InGiay(short giay) {
    Color(10);
    if (giay < 10) {
        In(0, j1 + xd, 11);
        In(giay, j2 + xd, 11);
    }
    else {
        short so_dau = giay/10, so_cuoi = giay%10;
        In(so_dau, j1 + xd, 11);
        In(so_cuoi, j2 + xd, 11);
    }
}

// In dấu ngăn cách
void InDau(short dau) {
    Color(1);
    if (dau == 1) {
        short x = d1 + xd, x_tam = d1 + xd, y = 11;
        int dem = 0;
        for (char s : so[10]) {
            Gotoxy(x, y);
            cout << s;
            dem += 1;
            if (dem % 5 == 0) {
                y += 1;
                x = x_tam;
            }
            else x += 1;
        }
    }
    else {
        short x = d2 + xd, x_tam = d2 + xd, y = 11;
        int dem = 0;
        for (char s : so[10]) {
            Gotoxy(x, y);
            cout << s;
            dem += 1;
            if (dem % 5 == 0) {
                y += 1;
                x = x_tam;
            }
            else x += 1;
        }
    }
}

// Hiển thị viền ngoài
void VienNgoai() {
    short x = xd, y = yd;
    Color(1);
    for (short i = 0; i < n; i++) {
        Gotoxy(x, y);
        for (short j = 0; j < m; j++) {
            if (i == 0 || j <= 1 || i == n-1 || j >= m-2) cout << '#';
            else cout << ' ';
        }
        y += 1;
        x = xd;
    }
}

// Nhập thời gian băt đầu
void NhapThoiGian(short& gio, short& phut, short& giay) {
    NhapLai:
    bool nhap_lai = false;
    system("cls");

    // Giao diện nhập
    Gotoxy(42, 0);
    cout << "/// DONG HO DEM NGUOC THOI GIAN - 24G ///" << endl << endl;
    if (!nhap_lai) Sleep(500);
    nhap_lai = true;

    int x = 54, y = 2, x_tam = 54;
    int n = 3, m = 10;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            Gotoxy(x_tam++, y);
            if (i == 0 || i == n-1) {
                if (j == 0 || j == m-1) cout << '+';
                else cout << '-';
            }
            else if (j == 0 || j == m-1) cout << '|';
            else if (j == 3 || j == 6) cout << ':';
            else cout << ' ';
        }
        x_tam = x;
        y += 1;
    }

    // Giao diện lưu ý
    Gotoxy(45, 8);
    cout << "Chu y: Nhan [Enter] sau moi lan nhap !";
    Gotoxy(45, 9);
    cout << "+ Gio  (0<=gio<=23)";
    Gotoxy(45, 10);
    cout << "+ Phut (0<=phut<=59)";
    Gotoxy(45, 11);
    cout << "+ Giay (0<=giay<=59)";

    string a, b, c;
    // Nhập giờ
    Gotoxy(x+1, 3);
    cin >> a;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] >= 'a' && a[i] <= 'z' || a[i] >= 'A' && a[i] <= 'Z')
            goto NhapLai;
    }
    gio = atoi(a.c_str());
    if (gio < 0 || gio > 23) goto NhapLai;

    // Nhập phút
    Gotoxy(x+4, 3);
    cin >> b;
    for (int i = 0; i < b.size(); i++) {
        if (b[i] >= 'a' && b[i] <= 'z' || b[i] >= 'A' && b[i] <= 'Z')
            goto NhapLai;
    }
    phut = atoi(b.c_str());
    if (phut < 0 || phut > 59) goto NhapLai;

    // Nhập giây
    Gotoxy(x+7, 3);
    cin >> c;
    for (int i = 0; i < c.size(); i++) {
        if (c[i] >= 'a' && c[i] <= 'z' || c[i] >= 'A' && c[i] <= 'Z')
            goto NhapLai;
    }
    giay = atoi(c.c_str());
    if (giay < 0 || giay > 59) goto NhapLai;

    system("cls");
}

int main() {
    short gio, phut, giay;
    NhapThoiGian(gio, phut, giay);

    VienNgoai();
    InGio(gio); InDau(1); InPhut(phut); InDau(2); InGiay(giay);

    while (gio >= 0 && phut >= 0 && giay >= 0) {
        giay -= 1;
        HidenPoint();
        Sleep(1000);

        if (giay == -1 && phut == -1 && gio == -1) break;
        if (giay == -1 && phut > 0) {
            phut -= 1;
            giay = 59;
            if (phut == -1 && gio > 0) {
                gio -= 1;
                phut = 59;
                InGio(gio);
            }
            InPhut(phut);
        }
        InGiay(giay);
    }
    getch();
}