#include <iostream>
#include <chrono>
#include <ctime>

#include "./Sort.hpp"

template<typename Lambda, std::intmax_t num = 1, std::intmax_t den = 1000>
double MesureInstructionsTime(Lambda instructions) {

    auto start = std::chrono::high_resolution_clock::now();
    instructions();

    return std::chrono::duration<double, std::ratio<num, den>>(std::chrono::high_resolution_clock::now()-start).count();

}

void BubbleSort(std::vector<int> &v) { Sort::Bubble(v, Comparison::croissant<int>); }
void MergeSort(std::vector<int> &v) { Sort::Merge(v, Comparison::croissant<int>); }

int main() {

    std::srand(std::time(0));

    double averageBubble{0}, averageMerge{0};

    for (std::size_t precision{0}; precision < 2000; precision++) {

        std::vector<int> numbers;
        for (std::size_t j{0}; j < precision; j++) {

            numbers.push_back((-RAND_MAX/2)+std::rand()%RAND_MAX);

        }

        averageMerge += MesureInstructionsTime([&numbers]() -> void { MergeSort(numbers); });
        averageBubble += MesureInstructionsTime([&numbers]() -> void { BubbleSort(numbers); });

    }

    std::cout << "Temps moyen pour MergeSort : " << averageMerge/1000 << " ms\nTemps moyen pour BubbleSort : " << averageBubble/1000 << " ms";
    std::cin.get();

    return 0;

}