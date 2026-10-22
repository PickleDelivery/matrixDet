#include "matrices.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

int precision = 2; //for output

int main(){
    cout << "Program will calculate determinant of a square matrix.\n";
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

    cout << "\n";

    cout << matrix;

    cout << "\n";

    cout << "Determinant is: " << fixed << setprecision(precision) << matrix.determinant();

    return 0;

}