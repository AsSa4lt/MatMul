#include <iostream>
#include <cstdint>  
#include <memory>
#include "../include/BenchmarkFactory.h"
#include "../include/CPUBenchmarkFactory.h"
#include "../include/Benchmark.h"

int main() {
    std::unique_ptr<BenchmarkFactory> factory = std::make_unique<CPUBenchmarkFactory>(); 
    std::unique_ptr<MatMulBenchmark> benchmark = factory->createMatMulBenchmark();
    benchmark->run(32,4096,4096);
    
    // Get and display the result
    std::cout << "Benchmark result: " << benchmark->getResult() << " ms" << std::endl;
    return 0;
}
