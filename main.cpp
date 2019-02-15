#include <iostream>
#include <fstream>
#include "matrix.cpp"
#include "connectivity_matrix.cpp"
#include "connectivity_calculations.cpp"

int main() {

    vector<double> input_vector_array{};

    try {
        ifstream in("connectivity.txt");
        if (!in) {
            throw "file not found";
        } else {
            int value;
            while (in >> value) {
                input_vector_array.push_back(value);
            }
        }
    }
    catch (const char *error_message) {
        cerr << error_message << endl;
        throw;
    }

    conduct_ranking(input_vector_array);

    return 0;
}

