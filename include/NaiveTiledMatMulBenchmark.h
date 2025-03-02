
#include "Benchmark.h"
#include <chrono>
#include <vector>
#include <thread>

class NaiveTiledMatMulBenchmark : public MatMulBenchmark {
    Result result; // In milliseconds
public:
    int TILE_SIZE = 32;
    void run(int M, int N, int K, int iterations=100) override;

    Result getResult() const override {
        return result;
    }
};