#include <algorithm> // copy, max_element
#include <iostream> // cin, cout, streamsize
#include <iterator> // back_inserter, istream_iterator
#include <limits> // numeric_limits
#include <numeric> // accumulate
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector
                  
//checking whether or not this weight fits
bool feasible(int n, int test_time, std::vector<int> times){
  int totalTime = test_time;
  int i = 0;
  int req_num = 1;
  while(i < times.size()){
    if(times[i] <= totalTime){
      totalTime -= times[i];
      i++;
    }
    else{
      req_num++;
      totalTime = test_time;
    }
  }
  return req_num <= n;
}



int newspapers_split(std::vector<int> newspapers_read_times, int num_coworkers) {
  int min = *std::max_element(newspapers_read_times.begin(), newspapers_read_times.end()); //get the least amount of time we would have to spend reading the largest newspaper
  int max = std::accumulate(newspapers_read_times.begin(), newspapers_read_times.end(), 0);//get the total sum of the array
  int boundary = min;
  while(min <= max){
    int middle = min + (max - min) / 2; //get the middle time
    if(feasible(num_coworkers, middle, newspapers_read_times)){
      max = middle - 1;
      boundary = middle;
    }
    else{
      min = middle + 1;
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
    std::vector<int> newspapers_read_times = get_words<int>();
    int num_coworkers;
    std::cin >> num_coworkers;
    ignore_line();
    int res = newspapers_split(newspapers_read_times, num_coworkers);
    std::cout << res << '\n';
}
