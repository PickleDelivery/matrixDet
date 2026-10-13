#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int printMatrix(vector<vector<float>>& matrix, int precision = 4){

    for (int i = 0; i < matrix.size(); i++){
        cout << "{ ";
        for (int j = 0; j< matrix[i].size(); j++){
            cout << fixed << setprecision(precision) << matrix[i][j];
            for (int spaces = 0; spaces <= precision; spaces++) cout << " ";
        }
        cout << "}\n";
    }
    return 0;
}