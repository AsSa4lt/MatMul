#include "SIMDAccumulatorMatMulBenchmark.h"
#include <arm_neon.h>
#include <vector>
#include <chrono>
#include "utils/Randomize.h"

// approach here is to use 4 accumulators to allow parallel usage
void SIMDAccumulatorMatMulBenchmark::run(int M, int N, int K, int iterations){
    // Generate matrices A and B (stored as a flat vector in row-major order)
    std::vector<float> matrixA = Randomize::GenerateMatrixVector<float>(M, N);
    std::vector<float> matrixB = Randomize::GenerateMatrixVector<float>(N, K);
    std::vector<float> matrixC(M * K, 0.0f);

    auto start = std::chrono::high_resolution_clock::now();
    for(int it = 0; it < iterations; it++){
        for(int i = 0; i < M; i++){
            // Simular to naive SIMD, we are using vectors of 4 
            for (int j = 0; j< N; j+=4){
                // now there is a difference, we are using 4 accumulators two achieve better performance
                float32x4_t acc0 = vdupq_n_f32(0.0f);
                float32x4_t acc1 = vdupq_n_f32(0.0f);
                float32x4_t acc2 = vdupq_n_f32(0.0f);
                float32x4_t acc3 = vdupq_n_f32(0.0f);
                for(int k = 0; k < K; k+=4){
                    // create four accumulators for broadcasting A
                    float32x4_t a_vec0 = vdupq_n_f32(matrixA[i*N+k]);
                    float32x4_t a_vec1 = vdupq_n_f32(matrixA[i*N+k+1]);
                    float32x4_t a_vec2 = vdupq_n_f32(matrixA[i*N+k+2]);
                    float32x4_t a_vec3 = vdupq_n_f32(matrixA[i*N+k+3]);
                    // create four accumulators for B
                    float32x4_t b_vec0 = vld1q_f32(&matrixB[k * K + j]);
                    float32x4_t b_vec1 = vld1q_f32(&matrixB[(k+1) * K + j]);
                    float32x4_t b_vec2 = vld1q_f32(&matrixB[(k+2) * K + j]);
                    float32x4_t b_vec3 = vld1q_f32(&matrixB[(k+3) * K + j]);
                    // multiply and accumulate sum
                    acc0 = vmlaq_f32(acc0, a_vec0, b_vec0);
                    acc1 = vmlaq_f32(acc1, a_vec1, b_vec1);
                    acc2 = vmlaq_f32(acc2, a_vec2, b_vec2);
                    acc3 = vmlaq_f32(acc3, a_vec3, b_vec3);
                }
                // combine recieved vectors 
                float32x4_t sum1 = vaddq_f32(acc0, acc1);
                float32x4_t sum2 = vaddq_f32(acc2, acc3);
                float32x4_t sum = vaddq_f32(sum1, sum2);
                vst1q_f32(&matrixC[i * K + j], sum);
            }
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    double duration = std::chrono::duration<double, std::milli>(end - start).count() / iterations;
    result = Result(M, N, K, duration, iterations);
}
