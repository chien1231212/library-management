#include "library.h"
#include <stdio.h>

void runTests() {
    printf("===== BAT DAU KIEM THU =====\n");
    
    // Test thêm sách
    addBook(1, "Lap Trinh C", "Author A");
    addBook(2, "C Programming", "Author B");
    addBook(3, "Clean Code", "Robert Martin");
    displayAllBooks(); // Hiển thị 3 sách
    
    // Test thêm người dùng
    addUser(101, "Nguyen Van A");
    addUser(102, "Tran Thi B");
    displayAllUsers(); // Hiển thị 2 người dùng
    
    // Test mượn sách
    borrowBook(101, 1); // Mượn thành công
    borrowBook(101, 3); // Mượn thành công
    borrowBook(101, 2); // Thất bại (vượt quá MAX_BORROWED_BOOKS)
    displayAllBooks();  // Sách ID 1 và 3 hiển thị "Đã mượn"
    
    // Test trả sách
    returnBook(101, 1); // Trả thành công
    returnBook(101, 99); // Thất bại (sách không tồn tại)
    displayAllBooks();  // Sách ID 1 trở về "Có sẵn"
    
    // Test tìm kiếm
    searchBooksByTitle("C");      // Tìm thấy 2 sách
    searchBooksByAuthor("Martin");// Tìm thấy 1 sách
    
    // Test xóa
    deleteBook(2);      // Xóa sách ID 2
    deleteUser(102);    // Xóa người dùng ID 102
    displayAllBooks();  // Chỉ còn 2 sách
    displayAllUsers();  // Chỉ còn 1 người dùng
    
    printf("===== KET THUC KIEM THU =====\n");
}

int main() {
    runTests();
    return 0;
}