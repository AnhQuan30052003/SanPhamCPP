/// Tro choi keo - bua - bao ///

// Thu vien -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
#include <iostream>
#include <ctime>
using namespace std;
// Thu vien -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

// Phan chuong trinh con ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// Lua chon cua may tinh
string MayTinhChon() {
	srand(time(0));
	int chon = rand() % 3 + 1;
	if (chon == 1)
		return "keo";
	else if (chon == 2)
		return "bua";
	else
		return "bao";
}

// Lua chon cua nguoi choi
string NguoiChoiChon() {
	string chon;
	while (true) {
		cout << "**********| Game (Keo, Bua, Bao) |**********" << endl;
		cout << "Hay chon (keo, bua hoac bao) ?" << endl;
		cout << "Lua chon cua ban: ";
		getline(cin, chon);
		if (chon == "keo" || chon == "bua" || chon == "bao") break;
		system("cls");
	}
	return chon;
}

// Xu ly lua chon 2 ben
string XuLy(string may_tinh, string nguoi_choi) {
	if (may_tinh == nguoi_choi)
		return "Hoa";
	else if (may_tinh == "keo") {
		if (nguoi_choi == "bua")
			return "Ban thang";
		else
			return "Ban thua";
	}
	else if (may_tinh == "bua") {
		if (nguoi_choi == "keo")
			return "Ban thua";
		else
			return "Ban thang";
	}
	else {
		if (nguoi_choi == "keo")
			return "Ban thang";
		else
			return "Ban thua";
	}
}

// Ham resart game
void TiepTuc(bool &lap) {
	string tiep_tuc;
	do {
		cout << "Ban co muon tiep tuc? (co/khong): ";
		getline(cin, tiep_tuc);
		if (tiep_tuc == "khong") {
			system("cls");
			cout << "**********| Cam on ban da tham gia tro choi ! |**********" << endl;
			lap = false;
			return;
		}
		else if (tiep_tuc == "co") {
			system("cls");
			return;
		}
		else system("cls");
	} while (!(tiep_tuc == "co" || tiep_tuc == "khong"));
}
// Phan chuong trinh con ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

// Ham chinh ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
int main() {
	bool lap = true;
	while (lap) {
		string may_tinh = MayTinhChon();
		string nguoi_choi = NguoiChoiChon();
		system("cls");
		cout << "Ban chon: " << nguoi_choi << endl;
		cout << "May tinh chon: " << may_tinh << endl;
		cout << "\n[Ket qua]: " << XuLy(may_tinh, nguoi_choi) << endl;
		TiepTuc(lap);
		if (lap == false) break;
	}
}
// Ham chinh ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//