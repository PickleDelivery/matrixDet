#include <isSquareMatrix.hpp>
#include <getDeterminant.hpp>
#include <printMatrix.hpp>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int precision = 2; //for output

int runTest(vector<vector<float>>& matrix) {

    cout << "Testing matrix :\n";

    printMatrix(matrix, precision);

    cout << "Determinant: " << getDeterminant(matrix) << "\n\n";

    return 0;
};


// the below is AI generated (and only that)

int main(int argc, char* argv[]){

    filesystem::path testCasesPath = filesystem::path(argv[0]).parent_path() / "testCases.txt";
    ifstream testCasesFile(testCasesPath);
    if (!testCasesFile) {
        cerr << "Could not open test cases file: " << testCasesPath << "\n";
        return 1;
    }

    string testName;
    int matrixSize;
    float expectedDeterminant;
    while (testCasesFile >> testName) {
        if (!(testCasesFile >> matrixSize >> expectedDeterminant) || matrixSize <= 0) {
            cerr << "Invalid test case header for matrix " << testName << "\n";
            return 1;
        }

        vector<vector<float>> matrix(matrixSize, vector<float>(matrixSize));
        for (int row = 0; row < matrixSize; row++) {
            for (int column = 0; column < matrixSize; column++) {
                if (!(testCasesFile >> matrix[row][column])) {
                    cerr << "Missing or invalid matrix value in test case " << testName << "\n";
                    return 1;
                }
            }
        }

        cout << "Test " << testName << " (expected determinant: " << expectedDeterminant << ")\n";
        runTest(matrix);
    }

    return 0;
}