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
