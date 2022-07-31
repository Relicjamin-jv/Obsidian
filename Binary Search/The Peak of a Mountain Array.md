# Code
```C++
#include <algorithm> // copy
#include <iostream> // cin, cout
#include <iterator> // back_inserter, istream_iterator
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

int peak_of_mountain_array(std::vector<int> arr) {
  int left = 0, right = arr.size() - 1, boundary = -1;
  while(left <= right){
    int mid = left + (right - left);
    if(arr[mid] > arr[mid+1]){ //peak element is always bigger than the next element
      boundary = mid;
      right = mid - 1;
    }else{
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
    int res = peak_of_mountain_array(arr);
    std::cout << res << '\n';
}
```

### Description
A mountain array is defined as an array that

-   has at least 3 elements
-   has an element with the largest value called "peak", with index `k`. The array elements monotonically increase from the first element to `A[k]`, and then monotonically decreases from `A[k + 1]` to the last element of the array. Thus creating a "mountain" of numbers.

That is, given `A[0]<...<A[k-1]<A[k]>A[k+1]>...>A[n-1]`, we need to find the index `k`. Note that the peak element is neither the first nor the last element of the array.

Find the index of the peak element. Assume there is only one peak element.

Input: `0 1 2 3 2 1 0`

Output: `3`

Explanation: the largest element is 3 and its index is 3.

# Notes
- The same idea as all other BS problems. We want to find a truth table through an if statment (some condition that lets us reduce the range). Once we find that reduce condition we implement it and update the left and right pointers and get a new mid to redo the whole algorithm again. In this case when we are looking for a peak, the peak is always going to be bigger than the next element. This makes a truth table and all we have to do is look for the boundary of truths to false of that condition.  

# Run Time / Space Time
Run time - O(lgn) -> we reduce the search space in half
Space time - O(1) -> no additional space required