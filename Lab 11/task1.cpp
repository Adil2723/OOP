#include <iostream>
#include <exception>
#include <string>

using namespace std;

class DimensionMismatchException : public exception {
    string message;
public:
    DimensionMismatchException(size_t rowsA, size_t colsA, size_t rowsB, size_t colsB) {
        message = "DimensionMismatchException\nMatrices must have same dimensions (" +
                  to_string(rowsA) + "x" + to_string(colsA) + " vs " +
                  to_string(rowsB) + "x" + to_string(colsB) + ")!";
    }

    const char* what() const noexcept override {
        return message.c_str();
    }
};

template<typename T, size_t ROWS, size_t COLS>
class Matrix {
    T data[ROWS][COLS];
public:
    Matrix(const T init[ROWS][COLS]) {
        for (size_t i = 0; i < ROWS; ++i)
            for (size_t j = 0; j < COLS; ++j)
                data[i][j] = init[i][j];
    }

    Matrix<T, ROWS, COLS> add(const Matrix<T, ROWS, COLS>& other) const {
        T resultData[ROWS][COLS];
        for (size_t i = 0; i < ROWS; ++i)
            for (size_t j = 0; j < COLS; ++j)
                resultData[i][j] = data[i][j] + other.data[i][j];
        return Matrix<T, ROWS, COLS>(resultData);
    }

    void print() const {
        for (size_t i = 0; i < ROWS; ++i) {
            for (size_t j = 0; j < COLS; ++j)
                cout << data[i][j] << " ";
            cout << '\n';
        }
    }

    template<size_t R, size_t C>
    Matrix<T, ROWS, COLS> operator+(const Matrix<T, R, C>& other) const {
        if (ROWS != R || COLS != C) {
            throw DimensionMismatchException(ROWS, COLS, R, C);
        }
        return this->add(reinterpret_cast<const Matrix<T, ROWS, COLS>&>(other));
    }
};

int main() {
    try {
        int a[2][2] = {{1, 2}, {3, 4}};
        int b[3][3] = {{5, 6, 7}, {8, 9, 10}, {11, 12, 13}};

        Matrix<int, 2, 2> A(a);
        Matrix<int, 3, 3> B(b);

        A + B;
    } catch (const exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}
