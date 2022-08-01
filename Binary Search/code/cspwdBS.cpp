#include <algorithm> // copy, max_element
#include <iostream> // cin, cout, streamsize
#include <iterator> // back_inserter, istream_iterator
#include <limits> // numeric_limits
#include <numeric> // accumulate
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector
                  
//checking whether or not this weight fits
bool feasible(int d, int test_weight, std::vector<int> weights){
  int req_days = 1;
  int capacity = test_weight;
  int i = 0;
  
  while(i < weights.size()){
    if(weights[i] <= capacity){
      capacity -= weights[i];
      i++;
    }
    else{
      capacity = test_weight;
      req_days++;
    }
  }

  return req_days <= d;
}


int min_max_weight(std::vector<int> weights, int d) {
  int left = *std::max_element(weights.begin(), weights.end()); //creating the range 
  int right = std::accumulate(weights.begin(), weights.end(), 0); 
  int boundary = right; //at most we need to carry our heaviest package
  while(left <= right){ //finding the bs
    int mid = left + (right - left) / 2;
    if(feasible(d, mid, weights)){
      boundary = mid;
      right = mid - 1;
    }
    else{
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

void ignore_line() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    std::vector<int> weights = get_words<int>();
    int d;
    std::cin >> d;
    ignore_line();
    int res = min_max_weight(weights, d);
    std::cout << res << '\n';
}
