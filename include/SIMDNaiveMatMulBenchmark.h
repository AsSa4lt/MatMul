
#include "Benchmark.h"

class SIMDNaiveMatMulBenchmark : public MatMulBenchmark {
    Result result; // In milliseconds
public:
    void run(int M, int N, int K, int iterations=100) override;

    Result getResult() const override {
        return result;
    }
};