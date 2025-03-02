
#ifndef BENCHMARK_H
#define BENCHMARK_H

#include "Result.h"

class MatMulBenchmark {
    public:
        virtual void run(int M, int N, int K, int iterations = 100) = 0;
        virtual Result getResult() const = 0;
        virtual ~MatMulBenchmark() {}
};

#endif //BENCHMARK_H