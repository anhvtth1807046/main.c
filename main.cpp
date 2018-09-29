#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct {
    char students_name[10];
    char students_id[50];
    char students_phone[50];
} danhSachSinhVien;
void themMoiSinhVien(int i, danhSachSinhVien sinhVien[]) {
    printf("Vui lòng nhập mã sinh viên:\n");
    while (1 == 1) {
        fgetc(stdin);
        scanf("%s",sinhVien[i].students_id);
        if (strlen(sinhVien[i].students_id) != 5) {
            printf("Mã sinh viên phải đủ 5 kí tự, vui lòng nhập lại.\n");
        } else break;
    }
    printf("Vui lòng nhập tên sinh viên:\n ");
    fgetc(stdin);
    scanf("%[^\n]", sinhVien[i].students_name);
    fgetc(stdin);
    printf("Vui lòng nhập số điện thoại sinh viên:\n");
    scanf("%s", sinhVien[i].students_phone);
    fgetc(stdin);
}
void hienThiSinhVien(int dem, danhSachSinhVien sinhVien[]) {
    printf("-%-20s|%-20s|%s", "Mã sinh viên", "Tên sinh viên", "Số điện thoại");
    for ( int i = 0; i < dem; i++) {
        printf("\n-%-18s|%-18s|%s", sinhVien[i].students_id, sinhVien[i].students_name, sinhVien[i].students_phone);
    }
}
void luuSinhVien(int i, danhSachSinhVien sinhVien[]) {
    int j;
    FILE *fp = fopen("danhsachsinhvien.txt", "w");
    fprintf(fp, "-%-20s|%-20s|%s", "Mã sinh viên", "Tên sinh viên", "Số điện thoại");
    for (j = 0; j < i; j++) {
        fprintf(fp, "\n-%-18s|%-18s|%s", sinhVien[j].students_id, sinhVien[j].students_name, sinhVien[j].students_phone);
    }
    fclose(fp);
}
void docSinhVien() {
    FILE *f = fopen("danhsachsinhvien.txt", "r");
    int bufferSize = 225;
    char buffer[bufferSize];
    while (fgets(buffer, bufferSize, f) != NULL) {
        printf("%s", buffer);
    }
}
int main() {
    int choice;
    int i = 0;
    danhSachSinhVien sinhVien[10];
    printf("--------------Menu--------------\n");
    printf("Vui lòng chọn một trong các lựa chọn sau:\n");
    printf("1.Thêm 1 sinh viên. \n");
    printf("2.Hiển thị danh sách sinh viên. \n");
    printf("3.Lưu danh sách sinh viên ra file. . \n");
    printf("4. Đọc danh sách sinh viên từ file\n");
    printf("5.Thoát chương trình. \n");
    while (1 == 1) {
        printf("--------------------------\n");
        printf("Vui lòng chọn từ 1 đến 5:\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Bạn đã chọn 1:\n---Thêm sinh viên.---\n");
                themMoiSinhVien(i, sinhVien);
                i++;
                if (i == 10) {
                    printf("Danh sách đã đầy.");
                    break;
                }
                break;
            case 2:
                printf("Bạn đã chọn 2:\n---Danh sách sinh viên.---\n");
                hienThiSinhVien(i, sinhVien);
                break;
            case 3:
                printf("Bạn đã chọn 3:\nDanh sách sinh viên đã được lưa vào file (danhsachsinhvien.txt)\n ");
                luuSinhVien(i, sinhVien);
                break;
            case 4:
                printf("Bạn đã chọn 4:\n---Danh sách sinh viên được đọc từ file.---\n");
                docSinhVien();
                break;
        }
        if (choice == 5) {
            printf("Bye bye.....!!!");
            break;
        }
    }
}