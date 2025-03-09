#include <memory>
#include "NaiveMatMulBenchmark.h"
#include "NaiveTiledMatMulBenchmark.h"
#include "SIMDNaiveMatMulBenchmark.h"
#include "Benchmark.h"
#include "BenchmarkFactory.h"

class MyBenchmarksFactory : public BenchmarkFactory {
    public:
        std::unique_ptr<MatMulBenchmark> createMatMulBenchmark(BenchmarkType type) override {
            if (type == BenchmarkType::TILED) {
                return std::make_unique<NaiveTiledMatMulBenchmark>();
            }else if (type == BenchmarkType::NAIVE) {
                return std::make_unique<NaiveMatMulBenchmark>();
            }else if (type == BenchmarkType::NAIVE_VECTOR_INSTRUCTION){
                return std::make_unique<SIMDNaiveMatMulBenchmark>();
            }
            throw std::runtime_error("Invalid benchmark type");
        }
};