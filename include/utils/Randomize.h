
#pragma once

#include <vector>
#include <cstdlib>

class Randomize{
public: 
    static std::vector<std::vector<float>> GenerateMatrix(int rows, int cols) {
        std::vector<std::vector<float>> mat(rows, std::vector<float>(cols));
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                mat[i][j] = static_cast<float>(rand()) / RAND_MAX;
        return mat;
    }
};