#include<iostream>

using namespace std;

class Book {
private:	
	int id;
	string title;
	string author;
	double price;
public:
	Book():	id(-1),title("unknown"),author("unknown"),price(0.0){
	 cout << "Book object with ID " << id << " is created." << endl;
	 }
	Book(int id, string t, string a, double p) : id(id), title(t), author(a), price(p){
	} 	
	 ~Book() {
        cout << "Book object with ID " << id << " is being destroyed." << endl;
    }
	void display() const {
        cout << "ID: " << id << ", Title: " << title << ", Author: " << author << ", Price" << price << endl;
    }
    
};
 

int main(){
	Book b1;
	b1.display();
	Book b2(2,"OOP","Paul",2300);
	b2.display();
	
}