
#ifndef RESULT_H
#define RESULT_H

class Result{
    int M;
    int N;
    int K;
    double duration;
    int iterations;
public:
    Result(int M, int N, int K, double duration, int iterations) : M(M), N(N), K(K), duration(duration), iterations(iterations) {}
    Result() : M(0), N(0), K(0), duration(0.0), iterations(0) {}
    int getM() const { return M; }
    int getN() const { return N; }
    int getK() const { return K; }
    double getDuration() const { return duration; }
    int getIterations() const { return iterations; }
};



#endif //RESULT_H