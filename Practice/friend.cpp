#include <iostream>
#include <string>
using namespace std;

class Member; // Forward declaration

class Book {
private:
    string title;
    string author;
    bool isAvailable;

    friend class Library;               // Library can access private members
    friend bool canBorrow(Member&, Book&); // Friend function

public:
    Book() {
        title = "";
        author = "";
        isAvailable = true;
    }

    Book(string t, string a) {
        title = t;
        author = a;
        isAvailable = true;
    }

    void display() {
        cout << "Title: " << title << ", Author: " << author;
        cout << ", Available: " << (isAvailable ? "Yes" : "No") << endl;
    }
};

class Library {
private:
    Book books[10];
    int bookCount;

public:
    Library() {
        bookCount = 0;
    }

    void addBook(Book book) {
        if (bookCount < 10) {
            books[bookCount] = book;
            bookCount++;
        } else {
            cout << "Library is full!" << endl;
        }
    }

    Book* getBookByTitle(string title) {
        for (int i = 0; i < bookCount; i++) {
            if (books[i].title == title && books[i].isAvailable) {
                return &books[i];
            }
        }
        return NULL;
    }

    void checkoutBook(Book* book) {
        if (book != NULL && book->isAvailable) {
            book->isAvailable = false;
        }
    }

    void returnBook(Book* book) {
        if (book != NULL) {
            book->isAvailable = true;
        }
    }

    void displayBooks() {
        for (int i = 0; i < bookCount; i++) {
            books[i].display();
        }
    }
};

class Member {
private:
    string name;
    Book* borrowedBooks[5];
    int borrowCount;

public:
    Member(string n) {
        name = n;
        borrowCount = 0;
    }

    friend bool canBorrow(Member& m, Book& b); // Friend function

    void borrowBook(Library& lib, string title) {
        Book* book = lib.getBookByTitle(title);
        if (book != NULL && canBorrow(*this, *book)) {
            borrowedBooks[borrowCount] = book;
            borrowCount++;
            lib.checkoutBook(book);
            cout << name << " borrowed \"" << title << "\"" << endl;
        } else {
            cout << "Cannot borrow \"" << title << "\"" << endl;
        }
    }

    void returnBook(Library& lib, string title) {
        for (int i = 0; i < borrowCount; i++) {
            if (borrowedBooks[i]->title == title) {
                lib.returnBook(borrowedBooks[i]);
                // Shift array elements
                for (int j = i; j < borrowCount - 1; j++) {
                    borrowedBooks[j] = borrowedBooks[j + 1];
                }
                borrowCount--;
                cout << name << " returned \"" << title << "\"" << endl;
                return;
            }
        }
        cout << "Book not found in borrowed list." << endl;
    }

    void displayBorrowedBooks() {
        cout << "Books borrowed by " << name << ":" << endl;
        if (borrowCount == 0) {
            cout << "None" << endl;
        } else {
            for (int i = 0; i < borrowCount; i++) {
                cout << "- " << borrowedBooks[i]->title << endl;
            }
        }
    }
};

bool canBorrow(Member& m, Book& b) {
    return b.isAvailable && m.borrowCount < 5;
}

// ---------------- Main ----------------

int main() {
    Library lib;

    lib.addBook(Book("Dune", "Frank Herbert"));
    lib.addBook(Book("The Alchemist", "Paulo Coelho"));
    lib.addBook(Book("1984", "George Orwell"));

    Member m1("Ali");
    Member m2("Sara");

    m1.borrowBook(lib, "Dune");
    m2.borrowBook(lib, "1984");
    m2.borrowBook(lib, "The Alchemist");

    cout << "\nLibrary Inventory:\n";
    lib.displayBooks();

    cout << "\nBorrowed Books:\n";
    m1.displayBorrowedBooks();
    m2.displayBorrowedBooks();

    m1.returnBook(lib, "Dune");

    cout << "\nAfter return:\n";
    lib.displayBooks();
    m1.displayBorrowedBooks();

    return 0;
}
