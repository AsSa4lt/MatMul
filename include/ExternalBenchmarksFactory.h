#include <memory>
#include "Benchmark.h"
#include "BenchmarkFactory.h"
#include "EigenMatMulBenchmark.h"

class ExternalBenchmarksFactory : public BenchmarkFactory {
    public:
    std::unique_ptr<MatMulBenchmark> createMatMulBenchmark(BenchmarkType type) override {
        if(type == BenchmarkType::EIGEN_DENSE){
            return std::make_unique<EigenMatMulBenchmark>();
        }
        throw std::runtime_error("Invalid benchmark type");
    }
};