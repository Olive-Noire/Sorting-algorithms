#include <iostream>

#include "./Sort.hpp"

int main() {

    std::vector<int> numbers{1, 6, 34, -56, -7, 23};

    std::cout << "Voici le vecteur : \n";
    for (int i : numbers) {

        std::cout << i << ' ';

    }

    std::vector<int> numbers2{1, 4, 1, 2, 7, 5, 2};
    Sort::Counting(numbers2, Comparison::croissant<int>);

    std::cout << "\n\nVoici le vecteur trie dans l'ordre croissant : \n";
    for (int i : numbers2) {

        std::cout << i << ' ';

    }

    std::cout << "\nresultat attendu : 1 1 2 2 4 5 7";

    std::cin.get();

    return 0;

}