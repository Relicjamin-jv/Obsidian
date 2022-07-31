# Code
```C++
#include <iostream> // cin, cout, streamsize
#include <limits> // numeric_limits

int square_root(int n) {
  int left = 0, right = n, boundary = -1;
  while (left <= right){
    int middle = left + (right - left) / 2;
    if (middle * middle <= n){
      boundary = middle;
      left = middle + 1;
    } 
    else if(middle * middle > n){
      right = middle - 1;
    }
  }
  return boundary; 
}

void ignore_line() {
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
  int n;
  std::cin >> n;
  ignore_line();
  int res = square_root(n);
  std::cout << res << '\n';
}
```

### Description
Given an integer, find its square root without using the built-in square root function. Only return the integer part (truncate the decimals).

Input: `16`

Output: `4`

Input: `8`

Output: `2`

Explanation: square root of 8 is 2.83..., return integer part 2

# Notes
- Same idea as all the other binary searches. We just algortimically reduce the search space until we find the index of the highest number that fits the requirement of (middle * middle <= n). Meaning that it is less than or equal to the target. Allowing the boundary to get updated during the such to ensure that we find the highest integer that returns true from the condition described above.

# Run Time / Space Time
Run time - O(logn), n gets divided each time and check to see if it fits within the sqare of half on n.
Space time - O(1), no additional memeory taken.