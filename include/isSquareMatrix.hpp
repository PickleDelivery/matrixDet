#include <iostream>
#include <vector>

using namespace std;

bool isSquareMatrix(vector<vector<float>>& matrix){
    bool square = true;
    for (int i = 0; i < matrix.size(); i++){
        if (matrix.size() != matrix[i].size()){
            square = false;
        }
    }

    return square;
}