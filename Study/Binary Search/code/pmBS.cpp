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
