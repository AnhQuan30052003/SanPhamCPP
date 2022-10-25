#include <windows.h>
using namespace std;

// Hàm để chạy câu thoại ---------------------------------------------------------------------------------------------
void ChayKyTu(string s) {
	for (char x : s) {
		cout << x;
		Sleep(50);
	}
}

// Tiêu đề khi vào chương trình -------------------------------------------------------------------------------------
void TieuDe() {
	cout << "------------------------------------------------- CHUONG TRINH XO SO ---------------------------------------------------" << endl;
	string text = "Chuong trinh xo so kien quyet voi ve so dai 5 so !\nTrung binh moi ngay se xuat ra 10 ket qua, quy khach chi can nhap 5 con so truoc khi xuat ket qua la co the tham gia !";
	ChayKyTu(text);
	Sleep(1000);
	cout << endl << endl;
}

// Hàm kiểm tra người dùng nhập thông tin vé số --------------------------------------------------------------------
bool KiemTraNhap(int* b) {
	// true: Nhập đúng hoàn toàn
	// false: Có số nhập sai
	int x[11];
	for (int i = 0; i < 5; i++) {
		if (b[i] < 1 || b[i] > 10 || x[b[i]] == b[i])
			return false;
		else x[b[i]] = b[i];
	}
	return true;
}

// Hàm nhập dữ liệu ------------------------------------------------------------------------------------------------
void Nhap(int* b) {
	while (true) {
		string text = "Nhap 5 so nguyen khac nhau tu (1-10): ";
		ChayKyTu(text);
		for (int i = 0; i < 5; i++)
			cin >> b[i];	
		if (KiemTraNhap(b)) {
			fflush(stdin);
			return;
		}
		system("cls");
	}
}

// Hàm restart ------------------------------------------------------------------------------------------------------
void TiepTuc(bool& trung_thuong, int& bien) {
	if (trung_thuong)
		trung_thuong = false;
	bien = 1;
	system("cls");
}

// Hiển thị bảng kết quả mỗi khi random số ! ------------------------------------------------------------------------
void InBangKetQua(int* c) {
	system("cls");
	cout << "[Bang Ket Qua]" << endl << endl;
	int i = 1;
	for (int dong = 0; dong < 10; dong++) {
		cout << "[" << dong << "]" << ": ";
		while (i < 51) {
			cout << c[i];
			if (i % 5 == 0) {
				cout << endl;
				++i;
				break;
			}
			else cout << " ";
			++i;
		}
	}
}

// Giao diện khi thoát chương trình -------------------------------------------------------------------------------
void ChuongTrinhThoat() {
	for (int i = 3; i > 0; i--) {
		system("cls");
		cout << "---------------------------------------------- CAM ON BAN DA THAM GIA ! ------------------------------------------------" << endl;
		cout << "Thoat sau (" << i << "s" << ")";
		Sleep(1000);
	}
	system("cls");
}