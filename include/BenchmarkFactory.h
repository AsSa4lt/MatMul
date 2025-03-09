#include <memory>
#include "Benchmark.h"


#ifndef BENCHMARK_FACTORY_H
#define BENCHMARK_FACTORY_H

class BenchmarkFactory {
public:
    enum class BenchmarkType {
        NAIVE,
        TILED,
        NAIVE_VECTOR_INSTRUCTION,
        SIMD_ACCUMULATOR,
        EIGEN_DENSE
    };
    virtual std::unique_ptr<MatMulBenchmark> createMatMulBenchmark(BenchmarkType type) = 0;
    virtual ~BenchmarkFactory() {}
};

#endif