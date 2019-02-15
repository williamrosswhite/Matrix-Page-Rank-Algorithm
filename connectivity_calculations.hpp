//
// Created by rwhit on 2/3/2019.
//

#include <vector>

using namespace std;

#pragma once

//calculates importance
//returns an array
matrix& find_importance(matrix &mtx);

//assigns randomness
//returns an array
matrix& assign_randomness(matrix &mtx);

//runs markov process
//returns an array
matrix& markov_process(matrix &mtx);

//does scaled rank division
//returns an array
matrix& scaled_rank(matrix &mtx);

//fully processes a matrix
//returns an array
matrix& conduct_ranking(vector<double> input_vector_array);