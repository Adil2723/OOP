#include <iostream>
#include <exception>

using namespace std;

// Exception for setting stock to a negative value
class NegativeStockException : public exception {};

// Exception for exceeding stock limit
class OverCapacityException : public exception {};

// Template class for Inventory Item
template <typename T>
class InventoryItem {
    T stock;
    const T maxCapacity;

public:
    // Constructor initializes stock and maxCapacity
    InventoryItem(T initialStock, T maxStock) : stock(initialStock), maxCapacity(maxStock) {}

    // Set the stock value, throwing exceptions as needed
    void setStock(T newStock) {
        if (newStock < 0) {
            throw NegativeStockException();
        } else if (newStock > maxCapacity) {
            throw OverCapacityException();
        } else {
            stock = newStock;
        }
    }

    // Getter for stock
    T getStock() const {
        return stock;
    }

    // Getter for max capacity
    T getMaxCapacity() const {
        return maxCapacity;
    }
};

int main() {
    try {
        // Create an InventoryItem with a max capacity of 100
        InventoryItem<int> item(10, 100);
        
        cout << "Attempting to set stock to -5..." << endl;
        item.setStock(-5);  // This should throw NegativeStockException
    } catch (const NegativeStockException& e) {
        cout << "Caught NegativeStockException - what(): " << e.what() << endl;
    }

    try {
        // Create an InventoryItem with a max capacity of 100
        InventoryItem<int> item(10, 100);
        
        cout << "Attempting to set stock to 120 (max 100)..." << endl;
        item.setStock(120);  // This should throw OverCapacityException
    } catch (const OverCapacityException& e) {
        cout << "Caught OverCapacityException - what(): " << e.what() << endl;
    }

    return 0;
}
