 #include<iostream>

using namespace std;

class ArrayClass {
private:
    int* arr;
    int size;

public:
    ArrayClass(int s) {
        size = s;
        arr = new int[size];
        for (int i = 0; i < size; ++i) {
            arr[i] = i;
        }
    }

    ~ArrayClass() {
        delete[] arr;
    }

    ArrayClass(const ArrayClass& obj) {
        size =  new int(*obj.size);
        arr = obj.arr;
    }

    void display() const {
        cout << "Array: ";
        for (int i = 0; i < size; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void modify(int index, int value) {
        if (index >= 0 && index < size) {
            arr[index] = value;
        }
    }
};

int main() {
    ArrayClass first(5);

    ArrayClass second = first;

    cout << "Before modification:" << endl;
    first.display();
    second.display();

    second.modify(2, 99);

    cout << "\nAfter modification:" << endl;
    first.display();
    second.display();

    return 0;
}
