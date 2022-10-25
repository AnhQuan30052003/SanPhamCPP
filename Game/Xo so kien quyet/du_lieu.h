#include <ctime>
#include <windows.h>
using namespace std;

int a[5]; // Biến lưu kết quả thạm thời
int d[11]; // Biến đối chiếu lựa chọn

// Hàm random của máy tính ---------------------------------------------------------------------------------
inline int KetQuaRandom() {
	int chon;
	while (true) {
		srand(time(0));
		chon = rand() % 10 + 1;
		if (d[chon] != chon) {
			d[chon] = chon;
			break;
		}
	}
	return chon;
}

// Hàm xử lý kết quả random -------------------------------------------------------------------------------
void XuLySoRandom(int* c, int& bien) {
	fill(d, d+11, 0);
	for (int i = 0; i < 5; i++) {
		c[bien] = a[i] = KetQuaRandom();
		++bien;
	}
}

// Xử lý dữ liệu nhập -------------------------------------------------------------------------------------
void DuLieu(int* b, int* c, int& bien, bool& trung_thuong) {
	for (int dong = 0; dong < 10; dong++) {
		system("cls");
		cout << "Lan " << dong << ": loading...";
		XuLySoRandom(c, bien);

		system("cls");
		cout << "Lan " << dong << ": ";
		Sleep(1000);
		int giong = 0;
		for (int i = 0; i < 5; i++) {
			cout << a[i] << (i == 4 ? "" : " ");
			Sleep(500);
			if (a[i] == b[i]) ++giong;
			if (giong == 5) trung_thuong = true;
		}
		Sleep(2000);
	}
}