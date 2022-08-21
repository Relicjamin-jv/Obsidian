# Code
```C++
#include <algorithm> // copy
#include <iostream> // cin, cout, streamsize
#include <iterator> // back_inserter, istream_iterator
#include <limits> // numeric_limits
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

int first_not_smaller(std::vector<int> arr, int target) {
  int left = 0, right = arr.size() - 1, boundaryI = -1;
  while(left <= right){
    int mid = left + (right - left) / 2;
    if(arr[mid] >= target){
      boundaryI = mid;
      right = mid - 1;
    }
    else{
      left = mid + 1;
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
  int res = first_not_smaller(arr, target);
  std::cout << res << '\n';
}
```
Given an array of integers sorted in increasing order and a target, find the index of the first element in the array that is _larger than or equal_ to the target. Assume that it is guaranteed to find a satisfying number.

Input:

-   `arr = [1, 3, 3, 5, 8, 8, 10]`
-   `target = 2`

Output: `1`

Explanation: the first element larger than 2 is 3 which has index 1.

Input:

-   `arr = [2, 3, 5, 7, 11, 13, 17, 19]`
-   `target = 6`

Output: `3`

Explanation: the first element larger than 6 is 7 which has index 3.

# Notes
- Has same idea where we do a binary search save the boundary index of when arr -> mid >= target. We continue this until left <= right and then we have the the index which is at least greater than or equal to the current target.
- The array must be in sorted order.

# Run Time / Space Time
Run time - O(logn) - we cut the array in half each time we interate through the while loop
Space time - O(1) - no additiional space is allocated during the procedure.