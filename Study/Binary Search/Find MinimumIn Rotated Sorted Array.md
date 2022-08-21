# Code
```C++
#include <algorithm> // copy
#include <iostream> // cin, cout
#include <iterator> // back_inserter, istream_iterator
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

/*Rotated array search*/

int find_min_rotated(std::vector<int> arr) {
  int left = 0, right = arr.size() - 1, boundary = -1;

  while(left <= right){
    int mid = left + (right - left) / 2;
    if(arr[mid] <= arr[arr.size() - 1]){
      boundary = mid;
      right = mid - 1;
    }
    else{
      left = mid + 1;
    }
  }

  return boundary;
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
    std::vector<int> arr = get_words<int>();
    int res = find_min_rotated(arr);
    std::cout << res << '\n';
}

```

### Description
A sorted array of unique integers was rotated at an unknown pivot. For example, `[10, 20, 30, 40, 50]` becomes `[30, 40, 50, 10, 20]`. Find the index of the minimum element in this array. All the numbers are unique.

Input: `[30, 40, 50, 10, 20]`

Output: `3`

Explanation: the smallest element is 10 and its index is 3.

Input: `[3, 5, 7, 11, 13, 17, 19, 2]`

Output: `7`

Explanation: the smallest element is 2 and its index is 7.

# Notes
- Now it may seem that this can't be solved in anything less than linear time, however, this is not the case. By look at the pattern provided ->
	- ![[Pasted image 20220731143033.png]]
	We can see that there are two sections. A section that is bigger than the last index and a section that is smaller than the last index. This allows use to reduce the range while looking for the smallest indexed value. We do this by checking the mid whether is is greater or less than the last index. this allows for us to reduce the range of index that the smallest value could be. -> (arr -> mid <= arr -> end) then set the boundary index to be mid (possible boundary) and move the right index pointer to mid - 1. If the above boolean check come to be false than we know that those values are greater and we can move the left indexed pointer to the mid + 1. Thus either way we are reducing the range and can find a solution to finding the index with the smallest value.

# Run Time / Space Time
Run time - O(logn) -> we cut n in half every while loop
Space time - O(1) -> no additional space