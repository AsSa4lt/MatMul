#include <memory>
#include "NaiveMatMulBenchmark.h"
#include "NaiveTiledMatMulBenchmark.h"
#include "Benchmark.h"
#include "BenchmarkFactory.h"

class CPUBenchmarkFactory : public BenchmarkFactory {
    public:
        std::unique_ptr<MatMulBenchmark> createMatMulBenchmark(BenchmarkType type) override {
            if (type == BenchmarkType::TILED) {
                return std::make_unique<NaiveTiledMatMulBenchmark>();
            }else if (type == BenchmarkType::NAIVE) {
                return std::make_unique<NaiveMatMulBenchmark>();
            }
            throw std::runtime_error("Invalid benchmark type");
        }
};