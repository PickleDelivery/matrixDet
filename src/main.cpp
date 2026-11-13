#include "matrices.hpp"
#include "vectors.hpp"
#include <iostream>
#include <stdexcept>
//#include <string>

using namespace std;

int main(){
    cout << "Program showcases matrices and vectors.\n";
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

    try {
        cout << "Your matrix in equation system form is:\n" << matrix.toEqSystemForm() << endl;
    } catch (const invalid_argument& e) {
        cout << "Exception! " << e.what() << endl;
    }

    cout << "Moving on to vectors. There are 2 vectors: p and q.\n";
    cout << "To define each vector you must provide 3 numbers.\n";

    float coords[6];
    string coordnames[6] = {"px", "py", "pz", "qx", "qy", "qz"};

    for (size_t i = 0; i < 6; i++){
        cout << "Enter the value of " << coordnames[i] << " -> ";
        cin >> coords[i];
    }

    three_dim_vector<float> p(coords[0], coords[1], coords[2]);
    three_dim_vector<float> q(coords[3], coords[4], coords[5]);

    cout << "\nYou entered the following vectors:\n";
    cout << "p = " << p.denote() << endl;
    cout << "q = " << q.denote() << endl;

    cout << "\nMagnitude of p: " << p.magnitude() << endl;
    cout << "Magnitude of q: " << q.magnitude() << endl;

    cout << "\nThe scalar product p*q is: " << scalar_product(p, q) << endl;

    cout << "\nThe angle between the two vectors is:" << endl;

    try{
        cout << "(in radians) " << angle(p, q) << "; (in degrees) " << angle(p, q) * (180.0/M_PI) << endl;
    } catch (invalid_argument& e) {
        cout << "Exception! " << e.what() << endl;
    }
    return 0;

}