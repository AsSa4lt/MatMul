#include "../include/NaiveTiledMatMulBenchmark.h"
#include "../include/utils/Randomize.h"
#include <cstdlib>

void NaiveTiledMatMulBenchmark::run(int M, int N, int K, int iterations){
    std::vector<std::vector<float>> matrixA = Randomize::GenerateMatrix(M, N);
    std::vector<std::vector<float>> matrixB = Randomize::GenerateMatrix(N, K);         

    auto start = std::chrono::high_resolution_clock::now();
    for (int iter = 0; iter < iterations; iter++) {
        std::vector<std::vector<float>> result = std::vector<std::vector<float>>(M, std::vector<float>(K));
        // Iterate over the tiles
        for (int i = 0; i < M; i+=TILE_SIZE) {
            for (int j = 0; j < K; j+=TILE_SIZE) {
                for (int k = 0; k < N; k+=TILE_SIZE) {
                    // Perform the multiplication of the submatrices
                    for (int ii = i; ii < std::min(i+TILE_SIZE, M); ii++) {
                        for (int jj = j; jj < std::min(j+TILE_SIZE, K); jj++) {
                            for (int kk = k; kk < std::min(k+TILE_SIZE, N); kk++) {
                                result[ii][jj] += matrixA[ii][kk] * matrixB[kk][jj];
                            }
                        }
                    }
                }
            }
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    double duration = std::chrono::duration<double, std::milli>(end - start).count() / iterations;
    result = Result(M, N, K, duration, iterations);
}