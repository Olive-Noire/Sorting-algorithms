#include <iostream>

#include "./Sort.hpp"

int main() {

    std::vector<int> numbers{1, 6, 34, -56, -7, 23};
    std::vector<unsigned int> numbers2{7, 4, 3, 8, 0, 9, 1};

    std::cout << "Voici le vecteur : \n";
    for (int i : numbers2) {

        std::cout << i << ' ';

    }

    Sort::Heap(numbers2, Comparison::croissant<int>);

    std::cout << "\n\nVoici le vecteur trie dans l'ordre croissant : \n";
    for (int i : numbers2) {

        std::cout << i << ' ';

    }

    std::cin.get();

    return 0;

}