//
// Created by rwhit on 2/3/2019.
//

#include "connectivity_calculations.hpp"
#include <math.h>
#include <iomanip>
#include <sstream>

constexpr double P{0.85};
constexpr double Q{1 - P};

matrix &find_importance(matrix &mtx) {

    for (int i = 0; i < mtx.vect.size(); i++) {
        double columnSum = 0;
        double columnValuedCount = 0;
        for (int j = 0; j < mtx.vect[i].size(); j++) {
            columnSum += mtx.vect[j][i];
            if (mtx.vect[j][i] != 0) {
                columnValuedCount++;
            }
        }
        if (columnSum == 0) {
            for (int j = 0; j < mtx.vect[i].size(); j++) {
                mtx.vect[j][i] = (double) 1 / mtx.vect[i].size();
            }
        } else {
            for (int j = 0; j < mtx.vect[i].size(); j++) {
                if (mtx.vect[j][i] != 0) {
                    mtx.vect[j][i] = (double) 1 / columnValuedCount;
                }
            }
        }
    }
}

matrix &assign_randomness(matrix &mtx) {

    double S, R;
    for (int i = 0; i < mtx.vect.size(); i++) {
        for (int j = 0; j < mtx.vect[i].size(); j++) {
            S = mtx.vect[i][j] * P;
            R = ((double) 1 / mtx.vect[i].size()) * Q;
            double newValue = S + R;
            mtx.vect[i][j] = newValue;
        }
    }
}

matrix &markov_process(matrix &mtx) {

    matrix mtxRank(mtx.vect[0].size(), 1);
    for (int i = 0; i < mtx.vect[0].size(); i++) {
        mtxRank.vect[i][0] = (double) 1;
    }
    matrix mtxPrevRank;
    do {
        mtxPrevRank = mtxRank;
        mtxRank = mtx * mtxPrevRank;
    } while (mtxRank != mtxPrevRank);
    mtx = mtxRank;
    return mtx;
}

matrix &scaled_rank(matrix &mtx) {

    double mtxSum = 0;
    for (int i = 0; i < mtx.vect.size(); i++) {
        for (int j = 0; j < mtx.vect[0].size(); j++) {
            mtxSum += mtx.vect[i][j];
        }
    }
    for (int i = 0; i < mtx.vect.size(); i++) {
        for (int j = 0; j < mtx.vect[0].size(); j++) {
            mtx.vect[i][j] /= mtxSum;
        }
    }
    return mtx;
}

matrix& conduct_ranking(vector<double> input_vector_array) {

    matrix base_matrix(input_vector_array);

    find_importance(base_matrix);

    matrix important_matrix = base_matrix;

    assign_randomness(important_matrix);

    matrix random_matrix = important_matrix;

    markov_process(random_matrix);

    matrix markov_matrix = random_matrix;

    scaled_rank(markov_matrix);

    matrix scaled_rank_matrix = markov_matrix;

    cout << "Page A: " << setw(5) << setprecision(2) << fixed << right << 100*scaled_rank_matrix.get_value(0,0) << "%" << endl;
    cout << "Page B: " << setw(5) << setprecision(2) << fixed << right << 100*scaled_rank_matrix.get_value(1,0) << "%" << endl;
    cout << "Page C: " << setw(5) << setprecision(2) << fixed << right << 100*scaled_rank_matrix.get_value(2,0) << "%" << endl;
    cout << "Page D: " << setw(5) << setprecision(2) << fixed << right << 100*scaled_rank_matrix.get_value(3,0) << "%\n" << endl;

}
