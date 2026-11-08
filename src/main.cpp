#include "matrices.hpp"
#include <iostream>
//#include <string>

using namespace std;

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

    cout << "\nYour matrix is:\n" << matrix << endl;
    cout << "Your matrix (transposed) is:\n" << transpose(matrix) << endl;

    cout << "Determinant is: " << matrix.determinant() << endl;;

    cout << "Your matrix in equation system form is:\n" << matrix.toEqSystemForm() << endl;

    return 0;

}