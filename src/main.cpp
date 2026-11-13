#include "matrices.hpp"
#include "vectors.hpp"
#include <iostream>
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

    cout << "Your matrix in equation system form is:\n" << matrix.toEqSystemForm() << endl;

    cout << "Moving on to vectors. There are 2 vectors: p and q.\n";
    cout << "To define 1 vector you must provide 6 numbers. XYZ for the start point, XYZ for the end point\n";

    float coords[12];
    string coordnames[12] = {"px1", "px2", "py1", "py2", "pz1", "pz2", "qx1", "qx2", "qy1", "qy2", "qz1", "qz2"};

    for (size_t i = 0; i < 12; i++){
        cout << "Enter the value of " << coordnames[i] << " -> ";
        cin >> coords[i];
    }

    three_dim_vector<float> p(coords[0], coords[1], coords[2], coords[3], coords[4], coords[5]);
    three_dim_vector<float> q(coords[6], coords[7], coords[8], coords[9], coords[10], coords[11]);

    cout << "\nYou entered the following vectors:\n";
    cout << "p = " << p.denote() << endl;
    cout << "q = " << q.denote() << endl;

    cout << "\nMagnitude of p: " << p.magnitude() << endl;
    cout << "Magnitude of q: " << q.magnitude() << endl;

    cout << "\nThe scalar product p*q is: " << scalar_product(p, q) << endl;

    cout << "\nThe angle between the two vectors is: (in radians) " << angle(p, q) << "; (in degrees) " << angle(p, q) * (180.0/M_PI) << endl;

    return 0;

}