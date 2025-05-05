#include<iostream>
using namespace std;

class Library{
    private:
    string* books;
    int capacity;
    int count;
    public:
    Library(int size,){
        capacity = 5;
        count = 0;
        books = new string[capacity];
        for (int i = 0; i < capacity; ++i) {
            books[i] = "Untitled";
        }
    }
    void printLibrary() const {
        for (int i = 0; i < capacity; ++i) {
            std::cout << "Book " << (i + 1) << ": " << books[i] << std::endl;
        }
    }
    ~Library(){ delete[] books;
     }
};

int main(){
    Library lib;
    lib.printLibrary();
}