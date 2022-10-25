//-------------------------------------------- Thư viện ------------------------------------------------
#include <iostream>
#include <windows.h>
#include "giao_dien.h"
#include "du_lieu.h"
using namespace std;
//-------------------------------------------- Thư viện ------------------------------------------------

//------------------------------------------ Biến giá trị ----------------------------------------------
const int n = 5;
int b[n];  // Biến lưu trữ dữ liệu người nhập
int c[51]; // Biến lưu kết quả random để in ra bảng
int bien = 1;

bool lap = true;
bool trung_thuong = false;
//------------------------------------------ Biến giá trị ----------------------------------------------

//-------------------------------------------- Ham main ------------------------------------------------
int main() {
	TieuDe();
	while (lap) {
		Nhap(b);
		DuLieu(b, c, bien, trung_thuong);
		InBangKetQua(c);
		cout << "\nVe so: ";
		for (int x : b) cout << x << " ";
		if (trung_thuong) cout << "trung thuong" << endl;
		else cout << "khong trung thuong !" << endl;

		string tra_loi;
		while (true) {
			string text = "\nBan co muon tiep tuc (co/khong): ";
			ChayKyTu(text);
			getline(cin, tra_loi);
			if (tra_loi == "co" || tra_loi == "khong") break;
			else system("cls");
		}

		if (tra_loi == "co") TiepTuc(trung_thuong, bien);
		else {
			lap = false;
			ChuongTrinhThoat();
		}
	}
}
//-------------------------------------------- Ham main ------------------------------------------------