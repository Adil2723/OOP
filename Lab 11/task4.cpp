#include <iostream>
#include <exception>
#include <string>

using namespace std;

// Base Exception Class
class DatabaseException : public exception {
public:
    const char* what() const noexcept override {
        return "A database error occurred.";
    }
};

// Derived Exception Class for Connection Failures
class ConnectionFailedException : public DatabaseException {};

// Derived Exception Class for Query Timeout Failures
class QueryTimeoutException : public DatabaseException {};

template <typename T>
class DatabaseConnector {
public:
    void connect(const string& dbName) {
        if (dbName == "invalid_db") {
            throw ConnectionFailedException();
        } else if (dbName == "slow_db") {
            throw QueryTimeoutException();
        } else {
            cout << "Successfully connected to " << dbName << endl;
        }
    }

    void query(const string& query) {
        if (query == "SELECT * FROM timeout") {
            throw QueryTimeoutException();
        }
        cout << "Query executed successfully: " << query << endl;
    }
};

int main() {
    DatabaseConnector<int> dbConnector;

    try {
        cout << "Attempting to connect to invalid_db..." << endl;
        dbConnector.connect("invalid_db");
    } catch (const ConnectionFailedException& e) {
        cout << "Caught ConnectionFailedException - what(): " << e.what() << endl;
    } catch (const DatabaseException& e) {
        cout << "Caught a general DatabaseException - what(): " << e.what() << endl;
    }

    try {
        cout << "Attempting to connect to slow_db..." << endl;
        dbConnector.connect("slow_db");
    } catch (const QueryTimeoutException& e) {
        cout << "Caught QueryTimeoutException - what(): " << e.what() << endl;
    } catch (const DatabaseException& e) {
        cout << "Caught a general DatabaseException - what(): " << e.what() << endl;
    }

    return 0;
}
