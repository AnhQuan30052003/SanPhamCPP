// Chuong trinh mo phong phao hoa

#include <iostream>
#include <cmath>
#include <ctime>
#include <windows.h>

using namespace std;

// Ham xoa man hinh nhung van giu nguyen trang thai
void clear() {
	HANDLE time;
	COORD position;
	time = GetStdHandle(STD_OUTPUT_HANDLE);
	position.X = 0;
	position.Y = 0;
	SetConsoleCursorPosition(time, position);
}

// Ham phao hoa bay len
void PhaoHoaBay(int tab) {
	int end = 51;
	system("color f");
	while (end >= 11) {
		int i = 0;
		while (i <= end) {
			if (i == end) {
				for (int i = 1; i <= tab; i++) cout << "\t";
				cout << ".";
			}
			else cout << endl;
			++i;
		}
		Sleep(1);
		clear();
		--end;
	}
	system("cls");
}

// Ham phao hoa no: [[[]]]
void PhaoHoaNo(int tab) {
	tab -= 3;
	int n = 10, m = 21, q = 0, p = 0;
	int x;
	while (q <= n) {
		for (int dong = 0; dong < m; dong++) {
			for (int i = 1; i <= tab; i++) cout << "\t"; cout << "    ";
			for (int cot = 0; cot < m; cot++) {
				x = max(abs(n-dong), abs(n-cot));
				if (x >= p && x <= q) cout << "@ ";
				else cout << "  ";
			}
			cout << endl;
		}
		Sleep(1);
		clear();
		++q;
	}
}

// Chon mau de hien thi khi phao hoa no
void XuLyMau() {
	srand(time(0));
	int mau = rand() % 6 + 1;
	if (mau == 1) system("color 1");
	else if (mau == 2) system("color 2");
	else if (mau == 3) system("color 3");
	else if (mau == 4) system("color 4");
	else if (mau == 5) system("color 5");
	else system("color 6");
}

int main() {
	system("cls");
	for (int i = 5; i >= 0; i--) {
		cout << "CHUONG TRINH BAT DAU SAU: " << i << "s";
		Sleep(1000);
		clear();
	}
	system("cls");
	
	int tab;
	while (true) {
		int vt = rand() % 3 + 1;
		if (vt == 1) tab = 3;
		else if (vt == 2) tab = 10;
		else tab = 17;
		PhaoHoaBay(tab);
		XuLyMau();
		PhaoHoaNo(tab);
		Sleep(10);
	}
}