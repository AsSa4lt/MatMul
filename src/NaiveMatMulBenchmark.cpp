#include "../include/NaiveMatMulBenchmark.h"
#include "../include/utils/Randomize.h"
#include <cstdlib>

void NaiveMatMulBenchmark::run(int M, int N, int K, int iterations) {
    std::vector<std::vector<float>> matrixA = Randomize::GenerateMatrix(M, N);
    std::vector<std::vector<float>> matrixB = Randomize::GenerateMatrix(N, K);         

    auto start = std::chrono::high_resolution_clock::now();
    for (int iter = 0; iter < iterations; iter++) {
        std::vector<std::vector<float>> result = std::vector<std::vector<float>>(M, std::vector<float>(K));
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < K; j++) {
                for (int k = 0; k < N; k++) {
                    result[i][j] += matrixA[i][k] * matrixB[k][j];
                }
            }
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    double duration = std::chrono::duration<double, std::milli>(end - start).count() / iterations;
    result = Result(M, N, K, duration, iterations);
}