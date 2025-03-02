#include <memory>
#include "Benchmark.h"


#ifndef BENCHMARK_FACTORY_H
#define BENCHMARK_FACTORY_H

class BenchmarkFactory {
public:
    virtual std::unique_ptr<MatMulBenchmark> createMatMulBenchmark() = 0;
    virtual ~BenchmarkFactory() {}
};

#endif