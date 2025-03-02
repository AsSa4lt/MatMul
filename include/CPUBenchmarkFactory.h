#include <memory>
#include "NaiveMatMulBenchmark.h"
#include "Benchmark.h"
#include "BenchmarkFactory.h"

class CPUBenchmarkFactory : public BenchmarkFactory {
    public:
        std::unique_ptr<MatMulBenchmark> createMatMulBenchmark() override {
            
            return std::make_unique<NaiveMatMulBenchmark>();
        }
};