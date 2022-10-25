#include <cstring>
#include <windows.h>
#include <iostream>

void taoTaiKhoan (char tkThietLap[], char mkThietLap[], char tkDangKy[], char mkDangKy[]);
void dangNhap (char tkThietLap[], char mkThietLap[]);

void ChayChu(char* s) {
    for (int i = 0; i < strlen(s); i++) {
        Sleep(50);
        printf("%c", s[i]);
    }
}

int main() {
    char tkThietLlap[255], mkThietLap[255];
    char tkDangKy[255], mkDangKy[255];

    taoTaiKhoan (tkThietLlap, mkThietLap, tkDangKy, mkDangKy);
    printf("\n\n");
    dangNhap (tkThietLlap, mkThietLap);
}

/*----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void taoTaiKhoan (char tkThietLap[], char mkThietLap[], char tkDangKy[], char mkDangKy[]) {
    printf("--------------------%s:--------------------\n", "Tao tai khoan FB");
    Sleep(1000);
    char text[] = "\nDe tao tai khoan, ban can su dung \"so dien thoai that su\", neu khong thoa yeu cau, Facebook se khong tao tai khoan cho ban duoc";
    ChayChu(text);
    Sleep(1000);
    system("cls");

    lapLaiTK:
    printf("+>Tai khoan <so dien thoai>: ");
    gets(tkDangKy);
    if (!(strlen(tkDangKy) == 10 && tkDangKy[0] == '0')) {
        system("cls");
        printf("So dien thoai khong hop le!");
        goto lapLaiTK;
    }

    char xacNhanMK[255];
    lapLaiMK:
    printf("+>Tao mat khau: ");
    gets(mkDangKy);
    printf("Xac nhan mat khau: ");
    gets(xacNhanMK);
    if (!(strcmp(mkDangKy, xacNhanMK) == 0)) {
        system("cls");
        printf("Mat khau xac nhan khong khop!\n");
        goto lapLaiMK;
    }

    strcpy(tkThietLap, tkDangKy);
    strcpy(mkThietLap, mkDangKy);
    system("cls");
    printf("-> TAO TAI KHOAN THANH CONG");
    Sleep(1000);
}

/*----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void dangNhap (char tkThietLap[], char mkThietLap[]) {
    char tkdn[255], mkdn[255];
    system("cls");
    printf("----------%s:----------\n", "Dang nhap tai khoan Facebook");
    Sleep(500);

    lapLaiTK:
    printf("+>Tai khoan: "); gets(tkdn);
    if (!(strcmp(tkThietLap, tkdn) == 0)) {
        system("cls");
        printf("Tai khoan khong chinh xac!\n");
        goto lapLaiTK;
    }

    lapLaiMK:
    printf("+>Mat khau: "); gets(mkdn);
    fflush(stdin);
    if (!(strcmp(mkdn, mkThietLap) == 0)) {
        system("cls");
        printf("Mat khau khong chinh xac!\n");
        goto lapLaiMK;
    }
    printf("-> DANG NHAP THANH CONG.");
}
/*----------------------------------------------------------------------------------------------------------------------------------------------------------------*/