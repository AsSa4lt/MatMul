#include <Eigen/Dense>
#include <EigenMatMulBenchmark.h>
#include <chrono>

void EigenMatMulBenchmark::run(int M, int N, int K, int iterations) {
    // Create matrices using Eigen's types (qualified)
    Eigen::MatrixXf A = Eigen::MatrixXf::Random(M, N);
    Eigen::MatrixXf B = Eigen::MatrixXf::Random(N, K);
    Eigen::MatrixXf C = Eigen::MatrixXf::Zero(M, K);

    // Record start time
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < iterations; i++) {
        // Use noalias() to hint that C doesn't alias with A or B, allowing optimizations.
        C.noalias() = A * B;
    }
    // Record end time
    auto end = std::chrono::high_resolution_clock::now();
    // Calculate average duration per iteration in milliseconds
    double duration = std::chrono::duration<double, std::milli>(end - start).count() / iterations;
    // Store the result (assuming Result has an appropriate constructor)
    result = Result(M, N, K, duration, iterations);
}
