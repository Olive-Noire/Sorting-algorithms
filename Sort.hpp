#ifndef DEF_SORT_HPP
#define DEF_SORT_HPP

#include <unordered_map>
#include <cstdlib>
#include <vector>

namespace Comparison {

    template <typename Type> auto croissant{[](Type l, Type r) -> bool { return l < r; }};
    template <typename Type> auto decroissant{[](Type l, Type r) -> bool { return l > r; }};

}

namespace Sort {

    // Use std::rand(std::time(0)); before first using
    template <typename Type, typename Lambda> void Bogo(std::vector<Type> &v, Lambda condition = Comparison::croissant<Type>) {

        if (v.size() > 1) {

            bool sorted{true};

            do {

                for (std::size_t i{0}; i < v.size()-1; i++) {

                    if (!condition(v[i], v[i+1])) sorted = false;

                }

                if (!sorted) {

                    for (Type& t : v) {

                        std::size_t r{rand()%v.size()};

                        Type swap{v[r]};
                        v[r] = t;
                        t = swap;

                    }

                }

            } while (!sorted);


        }

    }

    template <typename Type, typename Lambda> void Cube(std::vector<Type> &v, Lambda condition = Comparison::croissant<Type>) {

        if (v.size() > 1) {

            

        }

    }

    // Just vectors of positifs numbers and croissant order
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

        if (v.size() > 1) {

            

        }

    }

    template <typename Type, typename Lambda> void Bucket(std::vector<Type> &v, Lambda condition = Comparison::croissant<Type>) {

        if (v.size() > 1) {

            

        }

    }

    template <typename Type, typename Lambda> void Shell(std::vector<Type> &v, Lambda condition = Comparison::croissant<Type>) {

        if (v.size() > 1) {

            

        }

    }

    template <typename Type, typename Lambda> void Tree(std::vector<Type> &v, Lambda condition = Comparison::croissant<Type>) {

        if (v.size() > 1) {

            struct Binary_Tree {

                public:

                Type value;

                Binary_Tree *parent{nullptr};

                std::pair<Binary_Tree*, Binary_Tree*> branches{nullptr, nullptr};

            };

            Binary_Tree tree{v[v.size()/2]};

            for (std::size_t i{0}; i < v.size(); i++) {

                if (i != v.size()/2) {

                    Binary_Tree &current{tree};

                    while (condition(v[i], v[v.size()/2])) {

                        if (current.branches.first == nullptr) {

                            current.branches.first = new Binary_Tree{v[i], &current};
                            break;

                        } else {

                            current = *current.branches.first;

                        }

                    }

                    while (!condition(v[i], v[v.size()/2])) {

                        if (current.branches.second == nullptr) {

                            current.branches.second = new Binary_Tree{v[i], &current};
                            break;

                        } else {

                            current = *current.branches.second;

                        }

                    }

                }

            }

            Binary_Tree &order{tree};
            while (order.parent != nullptr) order = *order.parent;

            while (order.branches.second != nullptr) order = *order.branches.second;

            // Work in progress

        }

    }

    template <typename Type, typename Lambda> void Stooge(std::vector<Type> &v, Lambda condition = Comparison::croissant<Type>, std::size_t i = 0, std::size_t j = 0) {

        if (v.size() > 1) {

            if (j == 0) j = v.size()-1;

            if (!condition(v[i], v[j])) {

                Type swap{v[i]};
                v[i] = v[j];
                v[j] = swap;

            }

            if ((j-i+1) > 2) {

                std::size_t temp{(j-i+1)/3};

                Sort::Stooge(v, condition, i, j-temp);
                Sort::Stooge(v, condition, i+temp, j);
                Sort::Stooge(v, condition, i, j-temp);

            }

        }

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

                for (std::size_t j{i}; j > 0; j--) {

                    if (condition(v[i-(i-j)], v[j-1])) {

                        Type swap{v[j-1]};
                        v[j-1] = v[i-(i-j)];
                        v[i-(i-j)] = swap;

                    } else break;

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

    template <typename Type, typename Lambda> void Comb(std::vector<Type> &v, Lambda condition = Comparison::croissant<Type>) {

        if (v.size() > 1) {

            bool swapped{true};
            std::size_t interval{v.size()};

            while (interval > 1 || swapped) {

                interval = static_cast<std::size_t>(interval/1.3);
                if (interval == 0) interval++;

                std::size_t i{0};
                swapped = false;

                while (i < v.size()-interval) {

                    if (!condition(v[i], v[i+interval])) {

                        Type swap{v[i]};
                        v[i] = v[i+interval];
                        v[i+interval] = swap;

                        swapped = true;

                    }

                    i++;

                }

            }

        }

    }

    template <typename Type, typename Lambda> void Gnome(std::vector<Type> &v, Lambda condition = Comparison::croissant<Type>) {

        if (v.size() > 1) {

            std::size_t pos{0}; // artificial index
            while (pos < v.size()) {

                if (pos == 0 || !condition(v[pos], v[pos-1])) {

                    pos++;

                } else {

                    Type swap{v[pos]};
                    v[pos] = v[pos-1];
                    v[pos-1] = swap;

                    pos--;

                }

            }

        }

    }

    template <typename Type, typename Lambda> void Parity(std::vector<Type> &v, Lambda condition = Comparison::croissant<Type>) {

        if (v.size() > 1) {

            for (std::size_t i{0}; i < v.size()-1; i++) {

                for (std::size_t j{1}; j < v.size()-1; j += 2) {

                    if (!condition(v[j], v[j+1])) {

                        Type swap{v[j]};
                        v[j] = v[j+1];
                        v[j+1] = swap;

                    }

                }

                for (std::size_t j{0}; j < v.size()-1; j += 2) {

                    if (!condition(v[j], v[j+1])) {

                        Type swap{v[j]};
                        v[j] = v[j+1];
                        v[j+1] = swap;

                    }

                }

            }

        }

    }

    template <typename Type, typename Lambda> void Introspective(std::vector<Type> &v, Lambda condition = Comparison::croissant<Type>) {

        if (v.size() > 1) {



        }

    }

    template <typename Type, typename Lambda> void Cocktail(std::vector<Type> &v, Lambda condition = Comparison::croissant<Type>) {

        if (v.size() > 1) {

            bool swapped{true};
            std::size_t start{0}, end{v.size()-1};

            while (swapped) {

                swapped = false;

                for (std::size_t i{start}; i < end; i++) {

                    if (!condition(v[i], v[i+1])) {

                        Type swap{v[i]};
                        v[i] = v[i+1];
                        v[i+1] = swap;

                        swapped = true;

                    }

                }

                end--;

                for (std::size_t i{end}; i > start; i--) {

                    if (condition(v[i], v[i-1])) {

                        Type swap{v[i]};
                        v[i] = v[i-1];
                        v[i-1] = swap;

                        swapped = true;

                    }

                }

                start++;

            }

        }

    }

    template <typename Type, typename Lambda> void Bitonic(std::vector<Type> &v, Lambda condition = Comparison::croissant<Type>) {

        if (v.size() > 1) {

            

        }

    }

    template <typename Type, typename Lambda> void Smooth(std::vector<Type> &v, Lambda condition = Comparison::croissant<Type>) {

        if (v.size() > 1) {

            

        }

    }

    template <typename Type, typename Lambda> void Heap(std::vector<Type> &v, Lambda condition = Comparison::croissant<Type>) {

        if (v.size() > 1) {

            

        }

    }

    template <typename Type, typename Lambda> void Tim(std::vector<Type> &v, Lambda condition = Comparison::croissant<Type>) {

        if (v.size() > 1) {

            

        }

    }

    template <typename Type, typename Lambda> void Merge(std::vector<Type> &v, Lambda condition = Comparison::croissant<Type>) {



    }

    template <typename Type, typename Lambda> void Quick(std::vector<Type> &v, Lambda condition = Comparison::croissant<Type>) {

        if (v.size() > 1) {

            std::size_t pivot{v.size()/2};

        }


    }

    template <typename Type, typename Lambda> void Optimal(std::vector<Type> &v, Lambda condition = Comparison::croissant<Type>) {

        if (v.size() > 1) {

            

        }

    }

}

#endif // DEF_SORT_HPP