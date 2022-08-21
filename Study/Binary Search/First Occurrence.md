# Code
```C++
#include <algorithm> // copy
#include <iostream> // cin, cout, streamsize
#include <iterator> // back_inserter, istream_iterator
#include <limits> // numeric_limits
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

int find_first_occurrence(std::vector<int> arr, int target) {
  int left = 0, right = arr.size() - 1, boundaryI = -1;
  while(left <= right){
    int mid = left + (right - left) / 2;
    if(arr[mid] == target){
      boundaryI = mid;
      right = mid - 1;
    }
    else if (arr[mid] < target){
      left = mid + 1;
    }
    else{
      right = mid - 1;
    }
  }
  return boundaryI;
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
  std::vector<int> arr = get_words<int>();
  int target;
  std::cin >> target;
  ignore_line();
  int res = find_first_occurrence(arr, target);
  std::cout << res << '\n';
}

```

### Description
Given a sorted array of integers and a target integer, find the _first occurrence_ of the target and return its index. Return -1 if the target is not in the array.

Input:

-   `arr = [1, 3, 3, 3, 3, 6, 10, 10, 10, 100]`
-   `target = 3`

Output: `1`

Explanation: First occurrence of 3 is at index 1.

Input:

-   `arr = [2, 3, 5, 7, 11, 13, 17, 19]`
-   `target = 6`

Output: `-1`

Explanation: `6` does not exists in the array.

# Notes
- Same idea as vanilla search but looking for the first occurence of the target. This means we have to account for more than two possibilites. The possibilites are that arr -> mid less than the target and we have to move the left pointer up to mid + 1, the arr -> mid is greater than the target but not equal and we have to move right to mid not including mid, and that the target is equal to arr -> mid and that we have to move right to mid not including mid and update the boundary index. 

# Run Time / Space Time
Run time - O(lgn) -> cutting the array in half everytime we go through the while loop
Space time - O(1) -> No additional memory taken.