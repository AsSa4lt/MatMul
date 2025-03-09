#include <iostream>
#include <cstdint>  
#include <memory>
#include "BenchmarkFactory.h"
#include "MyBenchmarksFactory.h"
#include "ExternalBenchmarksFactory.h"
#include "Benchmark.h"

int main() {
    std::unique_ptr<BenchmarkFactory> factory = std::make_unique<MyBenchmarksFactory>(); 
    std::unique_ptr<MatMulBenchmark> benchmarkNaive = factory->createMatMulBenchmark(BenchmarkFactory::BenchmarkType::NAIVE);
    benchmarkNaive->run(256,256,256, 10);

    std::unique_ptr<MatMulBenchmark> benchmarkTiled = factory->createMatMulBenchmark(BenchmarkFactory::BenchmarkType::TILED);
    benchmarkTiled->run(256,256,256, 10);

    std::unique_ptr<MatMulBenchmark> benchmarkSIMDNaive = factory->createMatMulBenchmark(BenchmarkFactory::BenchmarkType::NAIVE_VECTOR_INSTRUCTION);
    benchmarkSIMDNaive->run(256,256,256, 10);

    std::unique_ptr<MatMulBenchmark> benchmarkSIMDAccums = factory->createMatMulBenchmark(BenchmarkFactory::BenchmarkType::SIMD_ACCUMULATOR);
    benchmarkSIMDAccums->run(256,256,256, 10);

    std::cout << "My MatMul implementations" << std::endl;
    std::cout << "Benchmark result naive 2D vector: " << benchmarkNaive->getResult().getDuration() << " ms" << std::endl;
    std::cout << "Benchmark result tiled 2D vector: " << benchmarkTiled->getResult().getDuration() << " ms" << std::endl;
    std::cout << "Benchmark result SIMD 1D vector: " << benchmarkSIMDNaive->getResult().getDuration() << " ms" << std::endl;
    std::cout << "Benchmark result SIMD Accumulator 1D vector: " << benchmarkSIMDAccums->getResult().getDuration() << " ms" << std::endl;

    std::unique_ptr<BenchmarkFactory> externalFactory = std::make_unique<ExternalBenchmarksFactory>(); 
    std::unique_ptr<MatMulBenchmark> benchmarkEigen = externalFactory->createMatMulBenchmark(BenchmarkFactory::BenchmarkType::EIGEN_DENSE);
    benchmarkEigen->run(256,256,256, 10);

    std::cout << "Reference MatMul implementations" << std::endl;
    std::cout << "Benchmark result eigen matmul: " << benchmarkEigen->getResult().getDuration() << " ms" << std::endl;
    return 0;
}
