
#include "library.h"
#include <stdio.h>
#include <string.h>

// Biến toàn cục
Book books[MAX_BOOKS];
User users[MAX_USERS];
int bookCount = 0;
int userCount = 0;

// ========== QUẢN LÝ SÁCH ==========
void addBook(int id, const char* title, const char* author) {
    if (bookCount >= MAX_BOOKS) {
        printf("Kho sach day! Khong the them.\n");
        return;
    }
    
    // Kiểm tra ID trùng
    for (int i = 0; i < bookCount; i++) {
        if (books[i].id == id) {
            printf("ID sach da ton tai!\n");
            return;
        }
    }

    // Thêm sách mới
    books[bookCount].id = id;
    strcpy(books[bookCount].title, title);
    strcpy(books[bookCount].author, author);
    books[bookCount].isBorrowed = 0; // Mặc định có sẵn
    bookCount++;
    printf("Them sach thanh cong!\n");
}

void editBook(int id, const char* newTitle, const char* newAuthor) {
    for (int i = 0; i < bookCount; i++) {
        if (books[i].id == id) {
            strcpy(books[i].title, newTitle);
            strcpy(books[i].author, newAuthor);
            printf("Sua sach thanh cong!\n");
            return;
        }
    }
    printf("Khong tim thay sach co ID: %d\n", id);
}

void deleteBook(int id) {
    for (int i = 0; i < bookCount; i++) {
        if (books[i].id == id) {
            // Di chuyển sách cuối lên vị trí xóa
            books[i] = books[bookCount - 1];
            bookCount--;
            printf("Xoa sach thanh cong!\n");
            return;
        }
    }
    printf("Khong tim thay sach co ID: %d\n", id);
}

void displayAllBooks() {
    printf("\n===== DANH SACH SACH =====\n");
    for (int i = 0; i < bookCount; i++) {
        printf("ID: %d | Tua de: %s | Tac gia: %s | Trang thai: %s\n",
               books[i].id,
               books[i].title,
               books[i].author,
               books[i].isBorrowed ? "Da muon" : "Co san");
    }
}

// ========== QUẢN LÝ NGƯỜI DÙNG ==========
void addUser(int id, const char* name) {
    if (userCount >= MAX_USERS) {
        printf("So nguoi dung toi da! Khong the them.\n");
        return;
    }
    
    // Kiểm tra ID trùng
    for (int i = 0; i < userCount; i++) {
        if (users[i].id == id) {
            printf("ID nguoi dung da ton tai!\n");
            return;
        }
    }

    // Thêm người dùng mới
    users[userCount].id = id;
    strcpy(users[userCount].name, name);
    users[userCount].borrowedCount = 0; // Chưa mượn sách
    userCount++;
    printf("Them nguoi dung thanh cong!\n");
}

void editUser(int id, const char* newName) {
    for (int i = 0; i < userCount; i++) {
        if (users[i].id == id) {
            strcpy(users[i].name, newName);
            printf("Sua nguoi dung thanh cong!\n");
            return;
        }
    }
    printf("Khong tim thay nguoi dung co ID: %d\n", id);
}

void deleteUser(int id) {
    for (int i = 0; i < userCount; i++) {
        if (users[i].id == id) {
            // Di chuyển người dùng cuối lên vị trí xóa
            users[i] = users[userCount - 1];
            userCount--;
            printf("Xoa nguoi dung thanh cong!\n");
            return;
        }
    }
    printf("Khong tim thay nguoi dung co ID: %d\n", id);
}

void displayAllUsers() {
    printf("\n===== DANH SACH NGUOI DUNG =====\n");
    for (int i = 0; i < userCount; i++) {
        printf("ID: %d | Ten: %s | So sach da muon: %d\n",
               users[i].id,
               users[i].name,
               users[i].borrowedCount);
    }
}

// ========== QUẢN LÝ MƯỢN/TRẢ SÁCH ==========
void borrowBook(int userId, int bookId) {
    User* user = NULL;
    Book* book = NULL;

    // Tìm người dùng
    for (int i = 0; i < userCount; i++) {
        if (users[i].id == userId) {
            user = &users[i];
            break;
        }
    }
    if (!user) {
        printf("Khong tim thay nguoi dung!\n");
        return;
    }

    // Tìm sách
    for (int i = 0; i < bookCount; i++) {
        if (books[i].id == bookId) {
            book = &books[i];
            break;
        }
    }
    if (!book) {
        printf("Khong tim thay sach!\n");
        return;
    }

    // Kiểm tra sách có sẵn không
    if (book->isBorrowed) {
        printf("Sach da duoc muon!\n");
        return;
    }

    // Kiểm tra người dùng đã mượn tối đa chưa
    if (user->borrowedCount >= MAX_BORROWED_BOOKS) {
        printf("Nguoi dung da muon toi da %d cuon sach!\n", MAX_BORROWED_BOOKS);
        return;
    }

    // Mượn sách
    book->isBorrowed = 1;
    user->borrowedBooks[user->borrowedCount] = bookId;
    user->borrowedCount++;
    printf("Muon sach thanh cong!\n");
}

void returnBook(int userId, int bookId) {
    User* user = NULL;
    Book* book = NULL;

    // Tìm người dùng
    for (int i = 0; i < userCount; i++) {
        if (users[i].id == userId) {
            user = &users[i];
            break;
        }
    }
    if (!user) {
        printf("Khong tim thay nguoi dung!\n");
        return;
    }

    // Tìm sách
    for (int i = 0; i < bookCount; i++) {
        if (books[i].id == bookId) {
            book = &books[i];
            break;
        }
    }
    if (!book) {
        printf("Khong tim thay sach!\n");
        return;
    }

    // Kiểm tra người dùng có mượn sách này không
    int found = 0;
    for (int i = 0; i < user->borrowedCount; i++) {
        if (user->borrowedBooks[i] == bookId) {
            // Xóa sách khỏi danh sách mượn
            for (int j = i; j < user->borrowedCount - 1; j++) {
                user->borrowedBooks[j] = user->borrowedBooks[j + 1];
            }
            user->borrowedCount--;
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Nguoi dung khong muon cuon sach nay!\n");
        return;
    }

    // Trả sách
    book->isBorrowed = 0;
    printf("Tra sach thanh cong!\n");
}

// ========== TÌM KIẾM ==========
void searchBooksByTitle(const char* title) {
    printf("\n===== KET QUA TIM KIEM (TUA DE: %s) =====\n", title);
    int found = 0;
    for (int i = 0; i < bookCount; i++) {
        if (strstr(books[i].title, title) != NULL) {
            printf("ID: %d | Tua de: %s | Tac gia: %s\n",
                   books[i].id,
                   books[i].title,
                   books[i].author);
            found = 1;
        }
    }
    if (!found) printf("Khong tim thay sach!\n");
}

void searchBooksByAuthor(const char* author) {
    printf("\n===== KET QUA TIM KIEM (TAC GIA: %s) =====\n", author);
    int found = 0;
    for (int i = 0; i < bookCount; i++) {
        if (strstr(books[i].author, author) != NULL) {
            printf("ID: %d | Tua de: %s | Tac gia: %s\n",
                   books[i].id,
                   books[i].title,
                   books[i].author);
            found = 1;
        }
    }
    if (!found) printf("Khong tim thay sach!\n");
}