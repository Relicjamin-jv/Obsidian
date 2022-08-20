# Code
```C++
#include <algorithm> // copy
#include <iostream> // boolalpha, cin, cout
#include <iterator> // back_inserter, istream_iterator
#include <sstream> // istringstream
#include <string> // getline, stoi, string
#include <vector> // vector
#include <bits/stdc++.h>

template <typename T>
struct Node {
    T val;
    Node<T>* left;
    Node<T>* right;

    explicit Node(T val, Node<T>* left = nullptr, Node<T>* right = nullptr)
        : val{val}, left{left}, right{right} {}

    ~Node() {
        delete left;
        delete right;
    }
};

bool valid_bst(Node<int>* root, Node<int>* minNode, Node<int>* maxNode) {
    if(root == nullptr) return true;
    if(minNode && (minNode->val > root->val) || maxNode && (maxNode->val < root->val)) return false;
    return valid_bst(root->left, minNode, root) && valid_bst(root->right, root, maxNode);
}

// this function build a tree from input
// learn more about how trees are encoded in https://algo.monster/problems/serializing_tree
template<typename T, typename Iter, typename F>
Node<T>* build_tree(Iter& it, F f) {
    std::string val = *it;
    ++it;
    if (val == "x") return nullptr;
    Node<T>* left = build_tree<T>(it, f);
    Node<T>* right = build_tree<T>(it, f);
    return new Node<T>{f(val), left, right};
}

template<typename T>
std::vector<T> get_words() {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream ss{line};
    std::vector<T> v;
    std::copy(std::istream_iterator<T>{ss}, std::istream_iterator<T>{}, std::back_inserter(v));
    return v;
}

int main() {
    std::vector<std::string> root_vec = get_words<std::string>();
    auto root_it = root_vec.begin();
    Node<int>* root = build_tree<int>(root_it, [](auto s) { return std::stoi(s); });
    bool res = valid_bst(root, nullptr, nullptr);
    std::cout << std::boolalpha << res << '\n';
}
```

### Description
A binary search tree is a binary tree with the property that any of its node's value is greater than or equal to _any_ node in its left subtree and less than or equal to _any_ node's value in its right subtree.

Given a binary tree, determine whether it is a binary search tree.

![](https://algomonster.s3.us-east-2.amazonaws.com/valid_bst.png)

# Notes
- A BST cannot have duplicate values.
- The way to solve this is to keep in mind what do we want to know at the position of the node we are currently at. In this case if we are going down the left we want the next node to the left to be strictly less than the parent and vice versa going down the right.
- Keeping in mind the last statement we also want to keep in mind that if we go left then right then we want a value that is more than the parent but not more than the parent of that parent beacause that grandparent states that all nodes in the left subtree are less than it. So there for the grandchild cannot be more in this case. Vice versa for other way included.

# Run Time / Space Time
Run time - O(n) have to run over every node to make sure it fits
Space time - O