#include <stdexcept>
#include <vector>
#include "isSquareMatrix.hpp"

using namespace std;

float getDeterminant(vector<vector<float>>& major_matrix){

    if (!isSquareMatrix(major_matrix)){
        throw invalid_argument("[ERR] Matrix is not square!");
    }

    int matrixsize = major_matrix.size();

    if (matrixsize == 1) { //recursion break, matrix is 1x1
        return major_matrix[0][0];
    }

    float determinant = 0;
    for (int ignored_major_column = 0; ignored_major_column < matrixsize; ignored_major_column++){

        vector<vector<float>> minor_matrix( // vector is bul;shit
            matrixsize - 1,
            vector<float>(matrixsize - 1)
        );

        int minor_column = 0;
        for (int major_column = 0; major_column < matrixsize; major_column++){
            if (major_column != ignored_major_column){
                for (int major_row = 1; major_row < matrixsize; major_row++){
                    int minor_row = major_row - 1;
                    minor_matrix[minor_row][minor_column] = major_matrix[major_row][major_column];
                }
                minor_column++;
            }

        }

        // cofactor sum

        float cofactor = major_matrix[0][ignored_major_column] * getDeterminant(minor_matrix);
        if ((ignored_major_column & 2) != 0) cofactor = cofactor * -1;

        determinant += cofactor;
        

    }

    return determinant;
    

}