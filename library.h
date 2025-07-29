#ifndef LIBRARY_H
#define LIBRARY_H

#define MAX_BOOKS 100
#define MAX_USERS 50
#define MAX_BORROWED_BOOKS 5
#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 50
#define MAX_NAME_LENGTH 50

// Cấu trúc lưu thông tin sách
typedef struct {
    int id;                         // ID sách
    char title[MAX_TITLE_LENGTH];   // Tên sách
    char author[MAX_AUTHOR_LENGTH]; // Tác giả
    int isBorrowed;                 // 0: có sẵn, 1: đã mượn
} Book;

// Cấu trúc lưu thông tin người dùng
typedef struct {
    int id;                                 // ID người dùng
    char name[MAX_NAME_LENGTH];             // Tên người dùng
    int borrowedBooks[MAX_BORROWED_BOOKS];  // Danh sách ID sách đã mượn
    int borrowedCount;                      // Số sách đã mượn
} User;

// Khai báo mảng và biến toàn cục
extern Book books[];
extern User users[];
extern int bookCount;
extern int userCount;

// Hàm quản lý sách
void addBook(int id, const char* title, const char* author);
void editBook(int id, const char* newTitle, const char* newAuthor);
void deleteBook(int id);
void displayAllBooks();

// Hàm quản lý người dùng
void addUser(int id, const char* name);
void editUser(int id, const char* newName);
void deleteUser(int id);
void displayAllUsers();

// Hàm mượn/trả sách
void borrowBook(int userId, int bookId);
void returnBook(int userId, int bookId);

// Hàm tìm kiếm
void searchBooksByTitle(const char* title);
void searchBooksByAuthor(const char* author);

#endif