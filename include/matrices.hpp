#pragma once

#include <stdexcept>
#include <vector>
#include <iostream>

template<std::floating_point T>
class FlatMatrix {

private:
    size_t rows;
    size_t cols;
    std::vector<T> data;
    size_t index(size_t r, size_t c) const {
        return r * cols + c;
    }

public:
    FlatMatrix(size_t r, size_t c)
        : rows(r), cols(c), data(r*c, T{}) {}

    T& operator()(size_t r, size_t c) {
        return data.at(index(r, c));
    }
    const T& operator()(size_t r, size_t c) const {
        return data.at(index(r, c));
    }

    [[nodiscard]]
    size_t rowCount() const {return rows; }
    [[nodiscard]]
    size_t colCount() const {return cols; }
    [[nodiscard]]
    bool isSquare() const {return rows==cols; }

    T determinant() const {
        if (!isSquare()) {
            throw std::invalid_argument("Determinant is only defined for square matrices");
        }

        if (rows == cols && rows == 1){
            return data.at(index(0, 0));
        }
        
        if (rows == cols && rows == 2){
            return data.at(index(0, 0)) * data.at(index(1, 1)) - data.at(index(0, 1)) * data.at(index(1, 0));
        }
        
        T determinant = 0.0;
        for (size_t ignored_major_column = 0; ignored_major_column < cols; ignored_major_column++){
            FlatMatrix<T> minor_matrix(rows-1, cols-1);
            
            size_t minor_column = 0;
            for (size_t major_column = 0; major_column < rows; major_column++){
                if (major_column != ignored_major_column){
                    for (size_t major_row = 1; major_row < rows; major_row++){
                        size_t minor_row = major_row - 1;
                        minor_matrix(minor_row, minor_column) = (* this)(major_row, major_column);
                    }
                    minor_column++;
                }
            }

            // cofactor sum
            T cofactor = (* this)(0, ignored_major_column) * minor_matrix.determinant();

            if (ignored_major_column % 2 != 0) cofactor *= -1;
            determinant += cofactor;

        }

        return determinant;
    }
};

template<std::floating_point T>
std::ostream& operator<<(
    std::ostream& os,
    const FlatMatrix<T>& matrix
) {
    for (size_t r = 0; r < matrix.rowCount(); r++){
        os << "| ";
        for (size_t c = 0; c < matrix.colCount(); c++) {
            os << matrix(r, c) << ' ';
        }
        os << "|\n";
    }
    return os;
}