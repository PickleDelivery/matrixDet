#include "getDeterminant.hpp"
#include "printMatrix.hpp"
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int precision = 2; //for output

int main(){
    cout << "Program will calculate determinant of a square matrix.\n";
    cout << "Please enter matrix size (1 positive int number) -> ";
    int size;

    cin >> size;

    cout << "\n";

    vector<vector<float>> matrix(
        size,
        vector<float>(size)
    );

    for (int i = 0; i < matrix.size(); i++){
        for (int j = 0; j < matrix[i].size(); j++){
            cout << "Enter element a[" << i+1 << "][" << j+1 << "] -> ";
            cin >> matrix[i][j];
        }
    }

    cout << "\n";

    printMatrix(matrix, precision);

    cout << "\n";

    cout << "Determinant is: " << fixed << setprecision(precision) << getDeterminant(matrix);

    return 0;

}