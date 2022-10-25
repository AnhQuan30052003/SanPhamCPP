/// Game CAro 3x3 ///
// Thu vien --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
#include <iostream>
#include <ctime>
#include <conio.h>
#include <windows.h>

using namespace std;
// Thu vien --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//


// BIen gia tri ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
string a[13][25]; // Ban co
string nguoi_choi_danh, may_tinh_danh;

int K[10];
int so_lan_nguoi_choi_danh = 0, so_lan_may_tinh_danh = 0;
int b[3][3] = {1,2,3,4,5,6,7,8,9}; // Ma tran luc chon

bool lap = true;
bool lua_chon_danh_truoc = false;
// BIen gia tri ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//


// Chuong trinh con ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// Ham chay chu man hinh
void ChayChu(string s) {
	for (char _s : s) {
		Sleep(50);
		cout << _s;
	}
	Sleep(1000);
}
// Random suy nghi may tinh co the danh
inline int RandomMayTinh() {
	int a[3];
	srand(time(0));
	int so_duoc_chon = 0;
	while (true) {
		a[0] = rand() % 9 + 1;
		a[1] = rand() % 9 + 1;
		a[2] = rand() % 9 + 1;

		for (int i = 0; i < 3; i++) {
			if (a[i] == K[a[i]]) continue;
			K[a[i]] = a[i];
			so_duoc_chon = a[i];
			break;
		}
		if (so_duoc_chon != 0) break;
	}
	return so_duoc_chon;
}

// Giao dien ban co caro !
void InBanCo() {
	system("cls");
	int r = 25, d = 13;
	for (int i = 1; i <= d; i++) {
		cout << "  ";
		for (int j = 1; j <= r; j++) {
			if (i == 1 || i == 5 || i == 9 || i == d)
				if (j == 1 || j == 9 || j == 17 || j == r) cout << "+";
				else cout << "-";
			else
				if (j == 1 || j == 9 || j == 17 || j == r) cout << "|";
				else if (a[i][j] == "X" || a[i][j] == "O") cout << a[i][j];
				else cout << " ";
		}
		cout << endl;
	}
}

// Danh dau lai lua chon cua nguoi choi va may tinh tren ban co
void XuLyLuaChon(int so_chon, string nguoi_choi) {
	// Vi tri nao duoc dung se duoc danh dau la: 0
	switch(so_chon) {
		case 1: a[3][5] = nguoi_choi;
				b[0][0] = 0;
				break;
		case 2: a[3][13] = nguoi_choi;
				b[0][1] = 0;
				break;
		case 3: a[3][21] = nguoi_choi;
				b[0][2] = 0;
				break;
		case 4: a[7][5] = nguoi_choi;
				b[1][0] = 0;
				break;
		case 5: a[7][13] = nguoi_choi;
				b[1][1] = 0;
				break;
		case 6: a[7][21] = nguoi_choi;
				b[1][2] = 0;
				break;
		case 7: a[11][5] = nguoi_choi;
				b[2][0] = 0;
				break;
		case 8: a[11][13] = nguoi_choi;
				b[2][1] = 0;
				break;
		case 9: a[11][21] = nguoi_choi;
				b[2][2] = 0;
				break;
	}
}

// Ma tran hien thi vi tri con trong
void InMaTranB() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			cout << "  " << b[i][j];
		cout << endl;
	}
}

// Nhan phim de chuyen sang giao dien moi
void NhanDeTiepTuc() {
	cout << "\n[+] Nhan [Enter] hoac bat ky phim nao de tiep tuc.";
	getch();
}

// Ket qua tro choi
void KetQua(string c) {
	InBanCo();
	if (c == nguoi_choi_danh)
		cout << "\n[Ket qua]: Ban thang" << endl;
	else
		cout << "\n[Ket qua]: Ban thua" << endl;
	NhanDeTiepTuc();
	lap = false;
	return;
}

// Xu ly cac truong hop dan den ket qua cua game
void DieuKienDungTroChoi() {
	bool GoiKetQua = false;
	string ky_tu_thang;
	InBanCo();
	if (so_lan_may_tinh_danh >= 3 || so_lan_nguoi_choi_danh >= 3) {
		// Dieu kien dung: Thang, Thua hoac Hoa
		string c = a[3][5];
		if (((c == a[3][13] && c == a[3][21]) || (c == a[7][5] && c == a[11][5])) && (c == "X" || c == "O")) {
			ky_tu_thang = c;
			GoiKetQua = true;
		}
		else {
			c = a[11][21];
			if (((c == a[7][21] && c == a[3][21]) || (c == a[11][13] && c == a[11][5])) && (c == "X" || c == "O")) {
				ky_tu_thang = c;
				GoiKetQua = true;
			}
			else {
				c = a[7][13];
				if (((c == a[3][13] && c == a[11][13]) || (c == a[7][5] && c == a[7][21])) && (c == "X" || c == "O")) {
					ky_tu_thang = c;
					GoiKetQua = true;
				}
				else if (((c == a[3][5] && c == a[11][21]) || (c == a[11][5] && c == a[3][21])) && (c == "X" || c == "O")) {
					ky_tu_thang = c;
					GoiKetQua = true;
				}
				else {
					int dem = 0;
					for (int i = 1; i < 10; i++)
						if (K[i] != 0) ++dem;
					if (dem == 9) {
						InBanCo();
						cout << "\n[Ket qua]: Hoa" << endl;
						NhanDeTiepTuc();
						lap = false;
						return;		
					}
				}
			}
		}
	}
	else return;
	if (GoiKetQua)
		KetQua(ky_tu_thang);
}

// Kiem tra vi tri x tai ban co da duoc chon hay chua
inline bool KiemTraViTri(int so_chon) {
	// true = da duoc su dung
	// false = chua duoc su dung
	if (K[so_chon] == so_chon)
		return true;
	else
		K[so_chon] = so_chon;
	return false;
}

// Luoc cua nguoi choi
void NguoiChoiChonViTri() {
	while (true) {
		cout << "[+] Vi tri con trong (so khac 0):" << endl;
		InMaTranB();
		int so_chon;
		cout << "[+] Ban chon vi tri so: ";
		cin >> so_chon;
		if (so_chon >= 1 && so_chon <= 9) {
			if (KiemTraViTri(so_chon)) {
				InBanCo();
				continue;
			}
			XuLyLuaChon(so_chon, nguoi_choi_danh);
			++so_lan_nguoi_choi_danh;
			DieuKienDungTroChoi();
			return;
		}
	}
}

// Luoc cua may tinh
void MayTinhChonViTri() {
	int so_chon = RandomMayTinh();
	XuLyLuaChon(so_chon, may_tinh_danh);
	++so_lan_may_tinh_danh;
	DieuKienDungTroChoi();
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------
//			Phan giao dien cho game - begin
// Phan: "Chao mung nguoi choi & goi thieu ve game"
void TieuDe() {
	cout << "\t\t\t+----------------------------------------------------------+" << endl;
	cout << "\t\t\t|                     </> GAME CARO </>                    |" << endl;
	cout << "\t\t\t+----------------------------------------------------------+" << endl;
}
void GiaoDienThu_1() {
	TieuDe();
	cout << "\n[+]---[Huong Dan]:" << endl;
	ChayChu("[1] Chao mung ban den voi game Caro, day la tua game 3x3 (9 o), nguoi choi se chon X (hoac O) va se duoc danh voi may tinh !");

	NhanDeTiepTuc();
	InBanCo();
	ChayChu("[2] Vi tri duoc sap xep theo:");
	cout << "\n  1  2  3\n  4  5  6\n  7  8  9" << endl;
	NhanDeTiepTuc();
	system("cls");
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------------------------------------------------------------------
// Phan: "Chon dau tich de choi & chon ai danh truoc" (ai = may tinh hoac nguoi choi)
void GiaoDienThu_2() {
	string c;
	while (true) {
		TieuDe();
		cout << "[+]---[Cai Dat]" << endl;
		cout << "[1] Ban chon (X hay O)? - Vui long nhap ki tu in hoa: ";
		getline(cin, c);
		if (c == "X" || c == "O") break;
		else system("cls");
	}

	// Xu ly lua chon danh X / O
	nguoi_choi_danh = c;
	if (c == "X")
		may_tinh_danh = "O";
	else
		may_tinh_danh = "X";

	string choi;
	while (true) {
		cout << "[2] Ban co muon choi truoc khong ? (co/khong): ";
		getline(cin, choi);
		if (choi == "co" || choi == "khong") break;
		system("cls");
		TieuDe();
		cout << "\n[1] Ban chon (X hay O)? - Vui long nhap ki tu in hoa: " << c << endl;
	}
	if (choi == "co")
		lua_chon_danh_truoc = true;
	else
		lua_chon_danh_truoc = false;
	NhanDeTiepTuc();
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------------------------------------------------------------------
// Phan: "Giao dien trong tro choi"
void GiaoDienThu_3() {
	if (lua_chon_danh_truoc) {	// Neu "true" thi nguoi choi: danh truoc
		InBanCo();
		while (lap) {
			NguoiChoiChonViTri();
			if (lap == false) return;
			MayTinhChonViTri();
			if (lap == false) return;
		}
	}
	else {						// may tinh: danh truoc
		while (lap) {
			MayTinhChonViTri();
			if (lap == false) return;
			NguoiChoiChonViTri();
			if (lap == false) return;
		}
	}
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------------------------------------------------------------------
//			Phan chinh sua game
// Chinh sua cai dat
void ThayDoi() {
	system("cls");
	GiaoDienThu_2();
	return;
}
// Game van tiep tuc voi cai dat & bat dau van choi moi
void GiuNguyen() {
	lap = true;
	so_lan_may_tinh_danh = so_lan_nguoi_choi_danh = 0;
	for (int i = 1; i <= 9; i++) {
		K[i] = 0;
		XuLyLuaChon(i, " ");
	}
	int dem = 1;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			b[i][j] = dem++;			
}
// Qua trinh chinh sua cai dat cua game
void ChinhSuaGAme() {
	string lua_chon;
	while (true) {
		cout << "\n[+] Ban muon thay doi [cai dat] hay giu nguyen? (thay doi/giu nguyen): ";
		getline(cin, lua_chon);
		if (lua_chon == "thay doi" || lua_chon == "giu nguyen")
			break;
		system("cls");
		cout << "[+] Ban co muon choi van moi khong? (co/khong): co" << endl;
	}

	if (lua_chon == "thay doi") {
		ThayDoi();
		GiuNguyen();
	}
	else GiuNguyen();
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------
//			Phan giao dien cho game - end
// Chuong trinh con ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//


// Ham thuc thi chuong trinh ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
int main() {
	GiaoDienThu_1();
	GiaoDienThu_2();
	while (true) {
		GiaoDienThu_3();
		system("cls");
		string choi_lai;
		while (true) {
			fflush(stdin);
			cout << "[+] Ban co muon choi van moi khong? (co/khong): ";
			getline(cin, choi_lai);
			if (choi_lai.empty()) {
				system("cls");
				continue;
			}
			if (choi_lai == "co" || choi_lai == "khong") break;
			system("cls");
		}
		if (choi_lai == "khong") {
			int i = 3;
			while (i > 0) {
				system("cls");
				cout << "\t\t\t+----------------------------------------------------------+" << endl;
				cout << "\t\t\t|                     </> GOOD BYE </>                     |" << endl;
				cout << "\t\t\t+----------------------------------------------------------+" << endl;
				cout << "Thoat sau (" << i << ")";
				--i;
				Sleep(1000);
			}
			system("cls");
			break;
		}
		else ChinhSuaGAme();
	}
}
// Ham thuc thi chuong trinh ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//