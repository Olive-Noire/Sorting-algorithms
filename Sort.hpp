#ifndef DEF_SORT_HPP
#define DEF_SORT_HPP

#include <unordered_map>
#include <vector>

namespace Comparison {

    template <typename Type>
    auto croissant{[](Type l, Type r) -> bool { return l < r; }};

    template <typename Type>
    auto decroissant{[](Type l, Type r) -> bool { return l > r; }};

}

namespace Sort {

    template <typename Type, typename Lambda> void Cube(std::vector<Type> &v, Lambda condition = Comparison::croissant<Type>) {



    }

    // Just vector of positif and integer number and croissant order
    template <typename Type> void Counting(std::vector<Type> &v) {

        if (v.size() > 1) {

            std::unordered_map<Type, size_t> count;

            for (Type t : v) {
                
                count[t]++;

            }

            {

                std::size_t sum{0};
                for (Type i{0}; i < count.size(); i++) {

                    sum += count[i];
                    count[i] = sum;

                }

            } // free `sum`

            for (Type i{count.size()-2}; i > 0; i--) count[i+1] = count[i];
            count[1] = count[0];

            std::vector<Type> output;
            for (Type i{0}; i < count.size(); i++) {

                if (i < count.size()-1) {

                    std::size_t duplicates{0};
                    while (i < count.size()-1 && count[i]+duplicates < count[i+1]) {

                        output.push_back(i);
                        duplicates++;

                    }

                } else {

                    output.push_back(i);

                }

            }

            v = output;

        }

    }

    template <typename Type, typename Lambda> void Radix(std::vector<Type> &v, Lambda condition = Comparison::croissant<Type>) {



    }

    template <typename Type, typename Lambda> void Bucket(std::vector<Type> &v, Lambda condition = Comparison::croissant<Type>) {



    }

    template <typename Type, typename Lambda> void Shell(std::vector<Type> &v, Lambda condition = Comparison::croissant<Type>) {



    }

    template <typename Type, typename Lambda> void Tree(std::vector<Type> &v, Lambda condition = Comparison::croissant<Type>) {



    }

    template <typename Type, typename Lambda> void Selection(std::vector<Type> &v, Lambda condition = Comparison::croissant<Type>) {

        if (v.size() > 1) {

            for (std::size_t i{0}; i < v.size(); i++) {

                std::size_t index{i};
                Type min{v[index]};

                for (std::size_t j{i}; j < v.size(); j++) {

                    if (condition(v[j], min)) {
                    
                        index = j;
                        min = v[index];

                    }

                }

                Type swap{v[i]};
                v[i] = v[index];
                v[index] = swap;

            }

        }

    }

    template <typename Type, typename Lambda> void Insertion(std::vector<Type> &v, Lambda condition = Comparison::croissant<Type>) {

        if (v.size() > 1) {

            for (std::size_t i{1}; i < v.size(); i++) {

                for (std::size_t j{i-1}; j > 0; j--) {

                    if (condition(v[i], v[j])) {

                    
                        break;

                    }

                }

            }

        }

    }

    template <typename Type, typename Lambda> void Bubble(std::vector<Type> &v, Lambda condition = Comparison::croissant<Type>) {

        if (v.size() > 1) {

            for (std::size_t i{0}; i < v.size(); i++) {

                for (std::size_t j{0}; j < v.size()-1-i; j++) {

                    if (!condition(v[j], v[j+1])) {

                        Type swap{v[j]};
                        v[j] = v[j+1];
                        v[j+1] = swap;

                    }

                }

            }

        }

    }

    template <typename Type, typename Lambda> void Heap(std::vector<Type> &v, Lambda condition = Comparison::croissant<Type>) {



    }

    template <typename Type, typename Lambda> void Tim(std::vector<Type> &v, Lambda condition = Comparison::croissant<Type>) {



    }

    template <typename Type, typename Lambda> void Merge(std::vector<Type> &v, Lambda condition = Comparison::croissant<Type>) {



    }

    template <typename Type, typename Lambda> void Quick(std::vector<Type> &v, Lambda condition = Comparison::croissant<Type>) {



    }

    template <typename Type, typename Lambda> void Optimal(std::vector<Type> &v, Lambda condition = Comparison::croissant<Type>) {



    }

}

#endif // DEF_SORT_HPP