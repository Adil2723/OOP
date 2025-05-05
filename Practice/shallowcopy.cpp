#include<iostream>
using namespace std;

class ShallowCopy {
private:
  	  int* data;

public:
    ShallowCopy(int a) {
        data = new int(a);
    }
	 ~ShallowCopy() {
        delete data; 
    }
    ShallowCopy(const ShallowCopy& nxt) {
        data = new int(*nxt.data);  
    }
    int getdata()const{
    	return *data;
	}
	void setdata(int value){
		*data = value;
	}
    void display() const {
        cout << "Data: " << *data << endl;  
    }
};
int main() {
    ShallowCopy first(135); 
    ShallowCopy nxt = first;  

    cout << "Before modification:" << endl;
    first.display();  
    nxt.display();    

  
    nxt.setdata(155);  

    cout << "\nAfter modification:" << endl;
    first.display(); 
    nxt.display();   
    

    return 0;
}
