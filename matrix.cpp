//
// Created by rwhit on 1/29/2019.
//

#include "matrix.hpp"
#include <math.h>
#include <iomanip>
#include <sstream>

using namespace std;

//constant expressino for default matrix size
constexpr int defaultMatrixSize = 1;

matrix::matrix() {

    //variable holding size of array
    int matrix_index = 1;

    // appropriately resizing one dimension of the 2D vector
    vect.resize(1);

    // incrementer for iterating through the thisVectorArray vector
    int v = 0;

    // loop for populating 2D vector
    for (int i = 0; i < matrix_index; i++) {
        vect[i].resize(matrix_index);
        for (int j = 0; j < matrix_index; j++) {
            vect[i][j] = 0;
            v++;
        }
    }
}

matrix::matrix(int n) {

    try {
        //guard against negative numbers and zero
        if (n <= 0) {
            throw "positive integers only";
        } else {

            //variable holding size of array
            int matrix_index = n;

            // appropriately resizing one dimension of the 2D vector
            vect.resize(matrix_index);

            // loop for populating 2D vector
            for (int i = 0; i < matrix_index; i++) {
                vect[i].resize(matrix_index);
                for (int j = 0; j < matrix_index; j++) {
                    vect[i][j] = 0.0;
                }
            }
        }
    }
    catch (const char *error_message) {
        cerr << error_message << endl;
        throw;
    }
}

matrix::matrix(int x, int y) {

    try {
        //guard against negative numbers and zero
        if (x <= 0 || y <= 0) {
            throw "positive integers only";
        } else {

            //variable holding size of array
            int matrix_index_x = x;
            int matrix_index_y = y;

            // appropriately resizing one dimension of the 2D vector
            vect.resize(x);

            // loop for populating 2D vector
            for (int i = 0; i < x; i++) {
                vect[i].resize(y);
                for (int j = 0; j < y; j++) {
                    vect[i][j] = 0.0;
                }
            }
        }
    }
    catch (const char *error_message) {
        cerr << error_message << endl;
        throw;
    }
}

matrix::matrix(vector<double> this_vector_array) {

    try {
        //variable holding size of array
        int array_size = this_vector_array.size();
        //variable holding square root of array
        int matrix_index = sqrt(array_size);

        //guard against non perfect square number of elements
        double perfectSquareCheck = sqrt((double) array_size);
        if (array_size != (matrix_index * matrix_index)) {
            throw "must be a perfect square";
        }

        // appropriately resizing one dimension of the 2D vector
        vect.resize(matrix_index);

        // incrementer for iterating through the this_vector_array vector
        int v = 0;

        // loop for populating 2D vector
        for (int i = 0; i < matrix_index; i++) {
            vect[i].resize(matrix_index);
            for (int j = 0; j < matrix_index; j++) {
                vect[i][j] = this_vector_array[v];
                v++;
            }
        }
    }
    catch (const char *error_message) {
        cerr << error_message << endl;
        throw;
    }
}

void matrix::set_value(int x, int y, double value) {

    try {
        if (x < 0 || y < 0) {
            throw "matrix paramaters must be greater than or equal to zero";
        }
        if (x >= vect.size() || y >= vect[0].size()) {
            throw "attempted location out of bounds of target matrix";
        }
        vect[x][y] = value;
    }
    catch (const char *error_message) {
        cerr << error_message << endl;
        throw;
    }
}

double matrix::get_value(int x, int y) {

    try {
        if (x >= vect.size() || y >= vect[0].size()) {
            throw "attempted location out of bounds of target matrix";
        }
        return vect[x][y];
    }
    catch (const char *error_message) {
        cerr << error_message << endl;
        throw;
    }
}

void matrix::clear() {

    for (int i = 0; i < vect.size(); i++) {
        for (int j = 0; j < vect[i].size(); j++) {
            vect[i][j] = 0;
        }
    }
}


matrix::~matrix() {

    /*
     * excluded for clean output
    cout << "matrix destroyed" << endl;
     */
}

ostream &operator<<(ostream &os, matrix &mtx) {

    for (int i = 0; i < mtx.vect.size(); i++) {
        for (int j = 0; j < mtx.vect[i].size(); j++) {
            os << fixed << setprecision(4) << mtx.vect[i][j] << " ";
        }
        os << endl;
    }
    os << endl;
    return os;
}

bool operator!=(matrix &lhs_mtx, matrix &rhs_mtx) {

    bool is_not_equal = false;
    for (int i = 0; i < lhs_mtx.vect.size(); i++) {
        for (int j = 0; j < lhs_mtx.vect[i].size(); j++) {
            if (abs((lhs_mtx.vect[i][j] - rhs_mtx.vect[i][j]) / rhs_mtx.vect[i][j]) > 0.0001) {
                is_not_equal = true;
                return is_not_equal;
            }
        }
    }
}

bool operator==(matrix &lhs_mtx, matrix &rhs_mtx) {

    bool is_equal = true;
    for (int i = 0; i < rhs_mtx.vect.size(); i++) {
        for (int j = 0; j < lhs_mtx.vect[i].size(); j++) {
            if (abs((lhs_mtx.vect[i][j] - rhs_mtx.vect[i][j]) / rhs_mtx.vect[i][j]) > 0.01) {
                is_equal = false;
                return is_equal;
            }
        }
    }
    return is_equal;
}

matrix &matrix::operator++() {

    for (int i = 0; i < this->vect.size(); i++) {
        for (int j = 0; j < this->vect[i].size(); j++) {
            ++this->vect[i][j];
        }
    }
    return *this;
}

matrix matrix::operator++(int) {

    matrix temp_matrix(*this);
    for (int i = 0; i < this->vect.size(); i++) {
        for (int j = 0; j < this->vect[i].size(); j++) {
            this->vect[i][j]++;
        }
    }
    return temp_matrix;
}

matrix &matrix::operator--() {

    for (int i = 0; i < this->vect.size(); i++) {
        for (int j = 0; j < this->vect[i].size(); j++) {
            --this->vect[i][j];
        }
    }
    return *this;
}

matrix matrix::operator--(int) {

    matrix temp_matrix(*this);
    for (int i = 0; i < this->vect.size(); i++) {
        for (int j = 0; j < this->vect[i].size(); j++) {
            this->vect[i][j]--;
        }
    }
    return temp_matrix;
}

void mySwap(matrix &lhs_mtx, matrix rhs_mtx) {

    using std::swap;
    swap(lhs_mtx.vect, rhs_mtx.vect);
}

matrix &matrix::operator=(const matrix &rhs_mtx) {

    mySwap(*this, rhs_mtx);
    return *this;
}

matrix &matrix::operator+(const matrix &rhs_mtx) {

    try {
        if (rhs_mtx.vect.size() != this->vect.size() || rhs_mtx.vect[0].size() != this->vect[0].size()) {
            throw "cannot add these matrices";
        } else {
            for (int i = 0; i < this->vect.size(); i++) {
                for (int j = 0; j < this->vect[i].size(); j++) {
                    this->vect[i][j] += rhs_mtx.vect[i][j];
                }
            }
        }
        return *this;
    }
    catch (const char *error_message) {
        cerr << error_message << endl;
        throw;
    }
}

matrix &matrix::operator+=(const matrix &rhs_mtx) {

    try {
        if (rhs_mtx.vect.size() != this->vect.size() || rhs_mtx.vect[0].size() != this->vect[0].size()) {
            throw "cannot add, matrices not equivalent";
        } else {
            *this = *this + rhs_mtx;
        }
        return *this;
    }
    catch (const char *error_message) {
        cerr << error_message << endl;
        throw;
    }
}

matrix &matrix::operator-(const matrix &rhs_mtx) {

    try {
        if (rhs_mtx.vect.size() != this->vect.size() || rhs_mtx.vect[0].size() != this->vect[0].size()) {
            throw "cannot add, matrices not equivalent";
        } else {
            for (int i = 0; i < this->vect.size(); i++) {
                for (int j = 0; j < this->vect[i].size(); j++) {
                    this->vect[i][j] -= rhs_mtx.vect[i][j];
                }
            }
        }
        return *this;
    }
    catch (const char *error_message) {
        cerr << error_message << endl;
        throw;
    }
}

matrix &matrix::operator-=(const matrix &rhs_mtx) {

    try {
        if (rhs_mtx.vect.size() != this->vect.size() || rhs_mtx.vect[0].size() != this->vect[0].size()) {
            throw "cannot add, matrices not equivalent";
        } else {
            *this = *this - rhs_mtx;
        }
        return *this;
    }
    catch (const char *error_message) {
        cerr << error_message << endl;
        throw;
    }
}

matrix &matrix::operator*=(const matrix &rhs_mtx) {

    try {
        if (this->vect[0].size() != rhs_mtx.vect.size()) {
            throw "cannot multiply these matrices";
        } else {
            matrix mtx3(this->vect.size(), rhs_mtx.vect[0].size());
            for (int i = 0; i < mtx3.vect.size(); i++) {
                for (int j = 0; j < mtx3.vect[0].size(); j++) {
                    for (int k = 0; k < this->vect.size(); k++) {
                        mtx3.vect[i][j] += this->vect[i][k] * rhs_mtx.vect[k][j];
                    }
                }
            }
            *this = mtx3;
        }
        return *this;
    }
    catch (const char *error_message) {
        cerr << error_message << endl;
        throw;
    }
}

matrix operator*(matrix lhs_mtx, const matrix &rhs_mtx) {

    return lhs_mtx *= rhs_mtx;
}
