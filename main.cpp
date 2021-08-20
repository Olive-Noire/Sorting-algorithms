#include <iostream>

#include "./Sort.hpp"

int main() {

    std::vector<int> numbers{1, 6, 34, -56, -7, 23};

    std::cout << "Voici le vecteur : \n";
    for (int i : numbers) {

        std::cout << i << ' ';

    }

    Sort::Comb(numbers, Comparison::croissant<int>);

    std::cout << "\n\nVoici le vecteur trie dans l'ordre croissant : \n";
    for (int i : numbers) {

        std::cout << i << ' ';

    }

    std::cin.get();

    return 0;

}