//
// Created by rwhit on 1/29/2019.
//
#include <vector>

using namespace std;

#pragma once

class matrix {

public:

    //member variables
    vector<vector<double>> vect;

    //constructors


    //default constructor
    matrix();
    // one variable constructor
    matrix(int);
    //two variable constructor
    matrix(int, int);
    //vector input constructor
    matrix(vector<double> this_vector_array);

    //member functions

    //sets value of a particular vector position
    void set_value(int, int, double);
    //returns value of a particular vector position
    double get_value(int, int);
    //sets all matrix values to zero
    void clear();

    //overloads

    //overloaded destructor
    ~matrix();
    //overloaded insertion operator
    //specifies a cout for a matrix
    friend ostream& operator<<(ostream&, const matrix&);
    //overloaded is equal to operator
    //returns a boolean
    friend bool operator==(const matrix&, const matrix&);
    //overloaded not equals operator
    //returns a boolean
    friend bool operator!=(const matrix&, const matrix&);
    //overloaded prefix incrementer operator
    //returns a matrix
    matrix& operator++();
    //overloaded postfix incrementer operator
    //returns a matrix
    matrix operator++(int);
    //overloaded prefix decrementer operator
    //returns a matrix
    matrix& operator--();
    //overloaded postfix decrementer operator
    //returns a matrix
    matrix operator--(int);
    //helper swap function
    //returns a matrix
    friend void mySwap(matrix&, matrix);
    //overloaded assignment operator
    //returns a matrix
    matrix& operator=(const matrix&);
    //overloaded addition operator
    //returns a matrix
    matrix& operator+(const matrix&);
    //overloaded minus operator
    //returns a matrix
    matrix& operator-(const matrix&);
    //overloaded plus equals operator
    //returns a matrix
    matrix& operator+=(const matrix&);
    //overloaded minus equals operator
    //returns a matrix
    matrix& operator-=(const matrix&);
    //overloaded multiply operator
    //returns a matrix
    friend matrix operator*(matrix, const matrix&);
    //overloaded times equal operator
    //returns a matrix
    matrix& operator*=(const matrix&);
};