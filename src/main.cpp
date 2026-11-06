#include "matrices.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

int precision = 2; //for output

int main(){
    cout << fixed << setprecision(precision) << "Program will calculate determinant of a square matrix.\n";
    cout << "Please enter matrix size (1 positive int number) -> ";
    size_t size;

    cin >> size;

    cout << "\n";

    FlatMatrix<float> matrix(size, size);

    for (size_t i = 0; i < matrix.rowCount(); i++){
        for (size_t j = 0; j < matrix.colCount(); j++){
            cout << "Enter element a[" << i+1 << "][" << j+1 << "] -> ";
            cin >> matrix(i, j);
        }
    }

    cout << "\nYour matrix is:" << endl;

    cout << matrix << endl;

    cout << "Determinant is: " << matrix.determinant() << endl;;

    cout << "\nYour matrix (transposed) is:" << endl;

    cout << transpose(matrix) << endl;

    cout << "\n";

    return 0;

}