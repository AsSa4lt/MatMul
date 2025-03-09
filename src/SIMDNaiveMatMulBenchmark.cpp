#include "SIMDNaiveMatMulBenchmark.h"
#include "utils/Randomize.h"
#include <arm_neon.h>
#include <chrono>

/** Approach is to use NEON Arm vector instructions */
void SIMDNaiveMatMulBenchmark::run(int M, int N, int K, int iterations) {
    // Generate matrices A and B (stored as a flat vector in row-major order)
    std::vector<float> matrixA = Randomize::GenerateMatrixVector<float>(M, N);
    std::vector<float> matrixB = Randomize::GenerateMatrixVector<float>(N, K);
    // Allocate a result matrix C (M x K)
    std::vector<float> matrixC(M * K, 0.0f);
    auto start = std::chrono::high_resolution_clock::now();
    // Run the multiplication 'iterations' times (for benchmarking)
    for (int it = 0; it < iterations; it++) {
        // Clear the result matrix at the beginning of each iteration.
        std::fill(matrixC.begin(), matrixC.end(), 0.0f);
        // Loop over rows of A (and C)
        for (int i = 0; i < M; i++) {
            // Loop over columns of C in blocks of 4
            for (int j = 0; j < K; j += 4) {
                // Initialize sum vector for 4 elements of row i of C
                float32x4_t sum = vdupq_n_f32(0.0f);
                // Inner loop: iterate over columns of A / rows of B
                for (int k = 0; k < N; k++) {
                    // Load A(i,k) and broadcast it into a vector.
                    float a_val = matrixA[i * N + k];
                    float32x4_t a_vec = vdupq_n_f32(a_val);
                    // Load 4 contiguous floats from row k of B, starting at column j.
                    // Since B is row-major, row k starts at index k*K.
                    float32x4_t b_vec = vld1q_f32(&matrixB[k * K + j]);
                    // Accumulate: sum += a_vec * b_vec
                    sum = vmlaq_f32(sum, a_vec, b_vec);
                }
                // Store the computed 4 floats back into matrixC
                vst1q_f32(&matrixC[i * K + j], sum);
            }
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    double duration = std::chrono::duration<double, std::milli>(end - start).count() / iterations;
    result = Result(M, N, K, duration, iterations);
}
