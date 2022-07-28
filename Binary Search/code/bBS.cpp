#include <algorithm> // copy
#include <iostream> // cin, cout, streamsize
#include <iterator> // back_inserter, istream_iterator
#include <limits> // numeric_limits
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

//Boundary Binary search

int find_boundary(std::vector<bool> arr){
  int left = 0;
  int right = arr.size();
  int leftMostBoundary = -1;
  while(left <= right){
    int mid = left + (right - left) / 2;
    if(arr[mid] == true){
      leftMostBoundary = mid;
      right = mid - 1;
    }
    else{
      left = mid + 1;
    }
  }
  return leftMostBoundary;
}

int main() {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream ss{line};
    std::vector<bool> arr;
    bool b;
    while (ss >> std::boolalpha >> b) {
        arr.push_back(b);
    }
    int res = find_boundary(arr);
    std::cout << res << '\n';
}


