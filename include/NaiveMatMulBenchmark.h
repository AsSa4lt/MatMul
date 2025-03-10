#include "Benchmark.h"
#include <chrono>
#include <vector>
#include <thread>

class NaiveMatMulBenchmark : public MatMulBenchmark {
    Result result; // In milliseconds
public:
    void run(int M, int N, int K, int iterations=100) override;

    Result getResult() const override {
        return result;
    }
};