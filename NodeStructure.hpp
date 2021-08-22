#ifndef DEF_NODE_STRUCTURE_HPP
#define DEF_NODE_STRUCTURE_HPP

#include <vector>
#include <cmath>

struct Node_Index {

    public:

    bool HasParent() const { return value != 0; }

    std::size_t Left() const { return 2*value+1; }
    std::size_t Right() const { return 2*value+2; }

    std::size_t Parent() const { return value/2+!(value%2); }

    operator std::size_t&() { return value; }
    operator std::size_t() const { return value; }

    std::size_t value;

};

template <typename Type> class Node_Structure {

    public:

    Node_Structure() = default;

    Node_Structure(const std::vector<Type> &t) : tree{t} {}

    Node_Structure(const Node_Structure&) = default;
    Node_Structure(Node_Structure&&) noexcept = default;

    ~Node_Structure() = default;

    bool Empty() const { return tree.empty(); }

    std::size_t Size() const { return tree.size(); }
    std::size_t Recursions() const { return static_cast<std::size_t>(log2(Size()))+1; }

    void Push(const Type &v) { tree.push_back(v); }
    void Pop() { tree.pop_back(); }

    Node_Structure<Type> operator+(const Node_Structure<Type> &n) {

        Node_Structure<Type> result{*this};
        for (Type t : n.tree) result.Push(t);

        return result;

    }

    Node_Structure& operator+=(const Node_Structure &n) {

        *this = *this+n;
        return *this;

    }

    bool operator==(const Node_Structure<Type> &n) { return tree == n.tree; }
    bool operator!=(const Node_Structure<Type> &n) { return !(*this == n); }

    const Type& operator[](std::size_t index) const { return tree[index]; }
    const Type& operator[](Node_Index n) const { return tree[n.value]; }

    Type& operator[](std::size_t index) { return tree[index]; }
    Type& operator[](Node_Index n) { return tree[n.value]; }

    Node_Structure& operator=(const Node_Structure&) = default;
    Node_Structure& operator=(Node_Structure&&) noexcept = default;

    private:

    std::vector<Type> tree;

};

template <typename Type> bool HasChildrens(Node_Index n, const Node_Structure<Type> &t) {
    
    return static_cast<std::size_t>(log2(n.value))+1 < t.Recursions();
    
}

#endif // DEF_NODE_STRUCTURE_HPP