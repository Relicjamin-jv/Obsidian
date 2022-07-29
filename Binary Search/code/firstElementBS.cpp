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
