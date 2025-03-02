
#ifndef BENCHMARK_H
#define BENCHMARK_H
class MatMulBenchmark {
    public:
        virtual void run(int M, int N, int K, int iterations = 100) = 0;
        virtual double getResult() const = 0;
        virtual ~MatMulBenchmark() {}
};

#endif //BENCHMARK_H