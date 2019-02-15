//
// Created by rwhit on 2/3/2019.
//

#include <vector>

using namespace std;

#pragma once

class Connectivity_matrix : public matrix {

public:

    //constructors
    Connectivity_matrix() : matrix() {};
    Connectivity_matrix(int single) : matrix(single) {};
    Connectivity_matrix(int twin1, int twin2) : matrix (twin1, twin2) {} ;
    Connectivity_matrix(vector<double> thisVectorArray) : matrix (thisVectorArray) {};

};