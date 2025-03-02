#include <iostream>
#include <cstdint>  
#include <memory>
#include "../include/BenchmarkFactory.h"
#include "../include/CPUBenchmarkFactory.h"
#include "../include/Benchmark.h"

int main() {
    std::unique_ptr<BenchmarkFactory> factory = std::make_unique<CPUBenchmarkFactory>(); 
    std::unique_ptr<MatMulBenchmark> benchmarkNaive = factory->createMatMulBenchmark(BenchmarkFactory::BenchmarkType::NAIVE);
    benchmarkNaive->run(256,256,256, 10);

    std::unique_ptr<MatMulBenchmark> benchmarkTiled = factory->createMatMulBenchmark(BenchmarkFactory::BenchmarkType::TILED);
    benchmarkTiled->run(256,256,256, 10);

    // Get and display the result
    std::cout << "Benchmark result naive: " << benchmarkNaive->getResult().getDuration() << " ms" << std::endl;
    // Get and display the result
    std::cout << "Benchmark result tiled: " << benchmarkTiled->getResult().getDuration() << " ms" << std::endl;
    return 0;
}
