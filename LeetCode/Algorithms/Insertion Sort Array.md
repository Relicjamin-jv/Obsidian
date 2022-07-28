```C++
#include <algorithm> // copy
#include <iostream> // cin, cout
#include <iterator> // back_inserter, istream_iterator, ostream_iterator, prev
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

std::vector<int> sort_list(std::vector<int> unsorted_list) {
    // WRITE YOUR BRILLIANT CODE HERE
    int key, j;
    for(int i = 0; i < unsorted_list.size(); i++){
        key = unsorted_list[i];
        j = i - 1; //always looking to the left of the current key position
        
        while(j >= 0 && unsorted_list[j] > key){
            unsorted_list[j+1] = unsorted_list[j];
            j = j -1;
        }
        unsorted_list[j + 1] = key;
    }
    
    return unsorted_list;
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

template<typename T>
void put_words(const std::vector<T>& v) {
    if (!v.empty()) {
        std::copy(v.begin(), std::prev(v.end()), std::ostream_iterator<T>{std::cout, " "});
        std::cout << v.back();
    }
    std::cout << '\n';
}

int main() {
    std::vector<int> unsorted_list = get_words<int>();
    std::vector<int> res = sort_list(unsorted_list);
    put_words(res);
}
```
Sorting an array in ascending order

# Solved
Take the current value you are wanting to place (iterated from left to right). If the values to the left (*index j*) are greater than the current value than shift that value to the right and move the pointer j to the right. Continue this until all the indexs have been interated over for. 

# Run Time / Space Time
Run Time - O(n^2) -> The true time complexity is O(n * (n-1) /2) -> O(n^2 - n / 2) -> O(n^2) 
Space Time - O(n) -> Only need one array of n elements

# Features
- In place (No addition data stucture is needed)
- Stable (All elements do not get switched unless the element is less the current value we are looking to insert -> Since we are looking right to left its less for sorting an array in ascending order)