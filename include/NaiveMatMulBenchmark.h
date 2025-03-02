#include "Benchmark.h"
#include <chrono>
#include <vector>
#include <thread>

class NaiveMatMulBenchmark : public MatMulBenchmark {
    double duration; // In milliseconds
    std::vector<std::vector<float>> GenerateRandomMatrix(int M, int N) {
        std::vector<std::vector<float>> matrix = std::vector<std::vector<float>>(M, std::vector<float>(N));
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                matrix[i][j] = static_cast<float>(rand()) / RAND_MAX;
            }
        }
        return matrix;
    }
public:
    void run(int M, int N, int K, int iterations=100) override {
        std::vector<std::vector<float>> matrixA = GenerateRandomMatrix(M, N);
        std::vector<std::vector<float>> matrixB = GenerateRandomMatrix(N, K);         

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
        duration = std::chrono::duration<double, std::milli>(end - start).count() / iterations;
    }

    double getResult() const override {
        return duration;
    }
};