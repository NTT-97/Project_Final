
#include <stdio.h>

#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 50

// Mang luu tru thong tin sinh vien
int ids[MAX_STUDENTS];
char names[MAX_STUDENTS][MAX_NAME_LENGTH];
int ages[MAX_STUDENTS];
float gpas[MAX_STUDENTS];
int studentCount = 0;

// Ham them sinh vien moi
void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        printf("->Danh sach sinh vien da day.<-\n");
        return;
    }

    ids[studentCount] = studentCount + 1;  // Tu dong tang ma sinh vien

    printf("Nhap ten sinh vien: ");
    scanf(" %[^\n]", names[studentCount]);  // Doc chuoi co khoang trang

    printf("Nhap tuoi sinh vien: ");
    scanf("%d", &ages[studentCount]);

    printf("Nhap diem GPA: ");
    scanf("%f", &gpas[studentCount]);

    studentCount++;
    printf("->Sinh vien da duoc them thanh cong!<-\n");
}

// Ham hien thi danh sach sinh vien
void displayStudents() {
    if (studentCount == 0) {
        printf("->Chua co sinh vien nao trong danh sach.<-\n");
        return;
    }

    printf("Danh sach sinh vien:\n");
    printf("ID\tTen\t\tTuoi\tGPA\n");
    printf("-----------------------------------\n");
    for (int i = 0; i < studentCount; i++) {
        printf("%d\t%s\t\t%d\t%.2f\n", ids[i], names[i], ages[i], gpas[i]);
    }
}

// Ham xoa sinh vien
void deleteStudent() {
    int id;
    printf("Nhap ID sinh vien can xoa: ");
    scanf("%d", &id);

    int found = 0;
    for (int i = 0; i < studentCount; i++) {
        if (ids[i] == id) {
            // Dich chuyen cac phan tu phia sau ve phia truoc de xoa sinh vien
            for (int j = i; j < studentCount - 1; j++) {
                ids[j] = ids[j + 1];
                for (int k = 0; names[j][k] != '\0'; k++) {
                    names[j][k] = names[j + 1][k];
                }
                ages[j] = ages[j + 1];
                gpas[j] = gpas[j + 1];
            }
            studentCount--;
            found = 1;
            printf("->Sinh vien da duoc xoa thanh cong!<-\n");
            break;
        }
    }

    if (!found) {
        printf("->Khong tim thay sinh vien voi ID da nhap.<-\n");
    }
}

// Ham sua thong tin sinh vien
void updateStudent() {
    int id;
    printf("Nhap ID sinh vien can sua thong tin: ");
    scanf("%d", &id);

    int found = 0;
    for (int i = 0; i < studentCount; i++) {
        if (ids[i] == id) {
            printf("Nhap ten moi: ");
            scanf(" %[^\n]", names[i]);  // Doc chuoi co khoang trang

            printf("Nhap tuoi moi: ");
            scanf("%d", &ages[i]);

            printf("Nhap GPA moi: ");
            scanf("%f", &gpas[i]);

            printf("->Thong tin sinh vien da duoc cap nhat thanh cong!<-\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("->Khong tim thay sinh vien voi ID da nhap.<-\n");
    }
}

// Ham chinh
int main() {
    int choice;

    while (1) {
        printf("\nChuong trinh quan ly sinh vien\n");
        printf("1. Them sinh vien\n");
        printf("2. Hien thi danh sach sinh vien\n");
        printf("3. Xoa sinh vien\n");
        printf("4. Sua thong tin sinh vien\n");
        printf("5. Thoat\n");
        printf("-> Nhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                deleteStudent();
                break;
            case 4:
                updateStudent();
                break;
            case 5:
                return 0;  // Thoat chuong trinh
            default:
                printf("->Lua chon khong hop le. Vui long thu lai.<-\n");
        }
    }

    return 0;
}
