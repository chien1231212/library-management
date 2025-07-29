#include "library.h"
#include <stdio.h>

int main() {
    int choice;
    int id, userId, bookId;
    char title[MAX_TITLE_LENGTH], author[MAX_AUTHOR_LENGTH], name[MAX_NAME_LENGTH];

    while (1) {
        printf("\n===== HE THONG QUAN LY THU VIEN =====\n");
        printf("1. Them sach\n");
        printf("2. Sua sach\n");
        printf("3. Xoa sach\n");
        printf("4. Hien thi tat ca sach\n");
        printf("5. Them nguoi dung\n");
        printf("6. Sua nguoi dung\n");
        printf("7. Xoa nguoi dung\n");
        printf("8. Hien thi tat ca nguoi dung\n");
        printf("9. Muon sach\n");
        printf("10. Tra sach\n");
        printf("11. Tim sach theo tua de\n");
        printf("12. Tim sach theo tac gia\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap ID sach: ");
                scanf("%d", &id);
                printf("Nhap tua de: ");
                scanf(" %[^\n]s", title);
                printf("Nhap tac gia: ");
                scanf(" %[^\n]s", author);
                addBook(id, title, author);
                break;

            case 2:
                printf("Nhap ID sach can sua: ");
                scanf("%d", &id);
                printf("Nhap tua de moi: ");
                scanf(" %[^\n]s", title);
                printf("Nhap tac gia moi: ");
                scanf(" %[^\n]s", author);
                editBook(id, title, author);
                break;

            case 3:
                printf("Nhap ID sach can xoa: ");
                scanf("%d", &id);
                deleteBook(id);
                break;

            case 4:
                displayAllBooks();
                break;

            case 5:
                printf("Nhap ID nguoi dung: ");
                scanf("%d", &id);
                printf("Nhap ten: ");
                scanf(" %[^\n]s", name);
                addUser(id, name);
                break;

            case 6:
                printf("Nhap ID nguoi dung can sua: ");
                scanf("%d", &id);
                printf("Nhap ten moi: ");
                scanf(" %[^\n]s", name);
                editUser(id, name);
                break;

            case 7:
                printf("Nhap ID nguoi dung can xoa: ");
                scanf("%d", &id);
                deleteUser(id);
                break;

            case 8:
                displayAllUsers();
                break;

            case 9:
                printf("Nhap ID nguoi dung: ");
                scanf("%d", &userId);
                printf("Nhap ID sach muon muon: ");
                scanf("%d", &bookId);
                borrowBook(userId, bookId);
                break;

            case 10:
                printf("Nhap ID nguoi dung: ");
                scanf("%d", &userId);
                printf("Nhap ID sach muon tra: ");
                scanf("%d", &bookId);
                returnBook(userId, bookId);
                break;

            case 11:
                printf("Nhap tua de can tim: ");
                scanf(" %[^\n]s", title);
                searchBooksByTitle(title);
                break;

            case 12:
                printf("Nhap tac gia can tim: ");
                scanf(" %[^\n]s", author);
                searchBooksByAuthor(author);
                break;

            case 0:
                printf("Thoat chuong trinh...\n");
                return 0;

            default:
                printf("Lua chon khong hop le!\n");
        }
    }
}