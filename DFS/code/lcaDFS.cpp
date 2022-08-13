#include <algorithm> // copy
#include <iostream> // cin, cout
#include <iterator> // back_inserter, istream_iterator
#include <sstream> // istringstream
#include <string> // getline, stoi, string
#include <vector> // vector
#include <limits>

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

Node<int>* lca(Node<int>* root, Node<int>* node1, Node<int>* node2) {
  if(root == nullptr) return nullptr;
  if(root == node1 || root == node2) return root; //check if they are within the same left or right subtree and tells the parent to look down that tree
  Node<int>* left = lca(root->left, node1, node2);
  Node<int>* right = lca(root->right, node1, node2);
  if(left && right) return root; //check to see if the nodes we are looking for are in the right or left subtree, if not found then return which subtree that has node 1 or 2

  if(left) return left;
  if(right) return right;

  return nullptr; //not found anywhere currently at the left or right subtree.
}

template<typename T, typename Iter, typename F>
Node<T>* build_tree(Iter& it, F f) {
  std::string val = *it;
  ++it;
  if (val == "x") return nullptr;
  Node<T>* left = build_tree<T>(it, f);
  Node<T>* right = build_tree<T>(it, f);
  return new Node<T>{f(val), left, right};
}

Node<int>* find_node(Node<int>* root, int target) {
  if (root == nullptr || root->val == target) return root;
  Node<int>* left_search = find_node(root->left, target);
  if (left_search != nullptr) {
    return left_search;
  }
  return find_node(root->right, target);
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

void ignore_line() {
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
  std::vector<std::string> tree_vec = get_words<std::string>();
  auto tree_it = tree_vec.begin();
  Node<int>* root = build_tree<int>(tree_it, [](auto s) { return std::stoi(s); });
  int target;
  std::cin >> target;
  ignore_line();
  Node<int>* node1 = find_node(root, target);
  std::cin >> target;
  ignore_line();
  Node<int>* node2 = find_node(root, target);
  Node<int>* res = lca(root, node1, node2);
  if (res == nullptr) {
    std::cout << "null" << '\n';
  } else {
    std::cout << res->val << '\n';
  }
}
