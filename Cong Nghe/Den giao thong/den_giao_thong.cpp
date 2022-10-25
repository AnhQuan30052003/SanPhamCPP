// Mo phong dot den giao thong !
#include <iostream>
#include <windows.h>
using namespace std;

void clear() {
    HANDLE time;
    COORD position;
    time = GetStdHandle(STD_OUTPUT_HANDLE);
    position.X = 0;
    position.Y = 0;
    SetConsoleCursorPosition(time, position);
}

string InGiay0(int giay) {
    if (giay < 10) return "0";
    else return "";
}

void XuLyMau(int mau, char& x, char& v, char& d) {
    if (mau == 1) {
        x = 'X';
        system("color a"); // Doi sang mau xanh la
    }
    else if (mau == 2) {
        v = 'V';
        system("color 6"); // Doi dang mau vang
    }
    else {
        d = 'D';
        system("color c"); // Doi sang mau do
    }
}

void VeCotDen(int giay, int mau) {
    char x = ' ', v = ' ', d = ' ';
    XuLyMau(mau, x, v, d);

    cout << endl;
    cout << "+---------------------------------------------------------+" << endl;
    cout << "|==============================[ " << x <<" ][ "<< v << " ][ " << d << " ]===<[" << InGiay0(giay) << giay<< "]>===|" << endl;
    cout << "+---------------------------------------------------------+";

    Sleep(1000);
    clear();
}

void ChayCotDen() {
    // quy uoc: 1 - den xanh(30s); 2 - den vang(3s); 3 - den do(30s)
    for (int mau = 1; mau <= 3; mau++) {
        if (mau == 1) {
            for (int x = 30; x >= 0; x--)
                VeCotDen(x, mau);
        }
        else if (mau == 2) {
            for (int v = 3; v >= 0; v--)
                VeCotDen(v, mau);
        }
        else {
            for (int d = 30; d >= 0; d--)
                VeCotDen(d, mau);
        }
    }
}

int main() {
    system("cls");
    while (true) {
        ChayCotDen();
    }
}