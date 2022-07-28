
Topic: Quick Sort
Date: Jul 3, 2022

---
```C++
#include <algorithm> // copy
#include <iostream> // cin, cout
#include <iterator> // back_inserter, istream_iterator, ostream_iterator, prev
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

/*O(nlgn) average ture worst case is O(n^2)
 *Space Time - lg(n) -> recurusion layers 
 * */

void sort_list_interval(std::vector<int> &unsorted_list, int start, int end) {
  if (end - start <= 1) return;
    int pivot = unsorted_list[end - 1];
    int start_ptr = start, end_ptr = end - 1;
    while (start_ptr < end_ptr) {
        while (unsorted_list[start_ptr] < pivot && start_ptr < end_ptr) {
            start_ptr++;
        }
        while (unsorted_list[end_ptr] >= pivot && start_ptr < end_ptr) {
            end_ptr--;
        }
        if (start_ptr == end_ptr) break;
        int temp = unsorted_list[start_ptr];
        unsorted_list[start_ptr] = unsorted_list[end_ptr];
        unsorted_list[end_ptr] = temp;
    }
    int temp = unsorted_list[start_ptr];
    unsorted_list[start_ptr] = unsorted_list[end - 1];
    unsorted_list[end - 1] = temp;
    sort_list_interval(unsorted_list, start, start_ptr);
    sort_list_interval(unsorted_list, start_ptr + 1, end);
}


std::vector<int> sort_list(std::vector<int> unsorted_list) {

    sort_list_interval(unsorted_list, 0, unsorted_list.size());

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
### Questions/Cues
- Item

### Notes
- There is an arbitrary element in the list that is known as the pivot.
- We use the pivot by moving all the elements less than the pivot to the left and all the elements more or equal to the right of the pivot. After this is done we swap the pivot with the first element of the side that is larger or equal to the pivot. This puts the pivot right in the middle where the elements to the right are larger and to the left are smaller.
- We can have two pointers represent each side of the pivot. We can have one at the beginning and one at the end. If we find an element larger or equal to the pivot for the starting pointer and move the ending pivot until we find an element smaller than the pivot and then we can swap them. = 

### Summary
Runtime - O(nlgn) although worst time is O(n^2)
Space time = O(lgn) recursion layers.
