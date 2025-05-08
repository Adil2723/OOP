#include <iostream>
#include <exception>

using namespace std;

class QueueOverflowException : public exception {};

class QueueUnderflowException : public exception {};

template <typename T, size_t Capacity>
class Queue {
    T data[Capacity];
    size_t front;
    size_t rear;
    size_t count;

public:
    Queue() : front(0), rear(0), count(0) {}

    void enqueue(const T& item) {
        if (count == Capacity) {
            throw QueueOverflowException();
        }
        data[rear] = item;
        rear = (rear + 1) % Capacity;
        ++count;
    }

    T dequeue() {
        if (count == 0) {
            throw QueueUnderflowException();
        }
        T item = data[front];
        front = (front + 1) % Capacity;
        --count;
        return item;
    }

    bool isEmpty() const {
        return count == 0;
    }

    bool isFull() const {
        return count == Capacity;
    }
};

int main() {
    Queue<int, 3> q;

    try {
        q.enqueue(1);
        q.enqueue(2);
        q.enqueue(3);
        cout << "Attempting to enqueue to a full queue..." << endl;
        q.enqueue(4);  // This should throw
    } catch (const QueueOverflowException& e) {
        cout << "Caught QueueOverflowException\nwhat(): " << e.what() << endl;
    }

    try {
        cout << "Dequeued: " << q.dequeue() << endl;
        cout << "Dequeued: " << q.dequeue() << endl;
        cout << "Dequeued: " << q.dequeue() << endl;
        cout << "Attempting to dequeue from an empty queue..." << endl;
        q.dequeue();  // This should throw
    } catch (const QueueUnderflowException& e) {
        cout << "Caught QueueUnderflowException\nwhat(): " << e.what() << endl;
    }

    return 0;
}
