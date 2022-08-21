#include <algorithm> // copy
#include <iostream> // cin, cout, streamsize
#include <iterator> // back_inserter, istream_iterator
#include <limits> // numeric_limits
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

//Vanilla Binary search

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
    std::cout << "For the BS to work we need to have the inputted array in sorted order(ascending)" << std::endl;
    std::vector<int> arr = get_words<int>();
    int target;
    std::cin >> target;
    ignore_line();
    int res = binary_search(arr, target, 0, arr.size()-1);
    std::cout << res << '\n';
}
