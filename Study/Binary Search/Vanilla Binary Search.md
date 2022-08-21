# Code
```C++
#include <algorithm> // copy
#include <iostream> // cin, cout, streamsize
#include <iterator> // back_inserter, istream_iterator
#include <limits> // numeric_limits
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

int binary_search(std::vector<int> arr, int target, int start, int end){
  int mid = (end + start) / 2; //need to offset it by the start, need to sill get the correct indicies for where we are looking in the array
  
  if(end-start < 0) return -1;
  if(arr[mid] == target) return mid;

  if(arr[mid] < target){
    return binary_search(arr, target, mid+1, end);
  }
  if(arr[mid] > target){
    return binary_search(arr, target, start, mid-1);
  }

  return -1;
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
    int res = binary_search(arr, target, 0, arr.size()-1);
    std::cout << res << '\n';
}
```
# Notes
- A efficient way about going about searching an order array. The array must me *ordered* for this to work. If not the programmer will not get the desired output.
- The algorithm works by dividing the array in half each time starting with the middle (the floor of the size of the array divided by two). If the middle is not the target we are looking for. We then can look at the the part of the array that has the target since the array is in listed order (ascending). We can keep going this until we find the target index of the array we are looking for.
- We can use a binary search whenever we can make a decsion that will shink the range of where the target could possible be.

#### Calculating the Mid
- We take the (left + right) / 2. This will gives us a proper index to check the array. Offsets it by the start where we know the target is not place (since the array has ascending order).

# Run Time / Space Time
Run time - O(lgn)
Space time - O(1)

# Example
![[Pasted image 20220728144638.png]]
