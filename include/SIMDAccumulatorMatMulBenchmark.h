#include "Benchmark.h"

class SIMDAccumulatorMatMulBenchmark : public MatMulBenchmark {
    Result result;
public:
    void run(int M, int N, int K, int iterations = 100) override;
    Result getResult() const override {
        return result;
    }
};