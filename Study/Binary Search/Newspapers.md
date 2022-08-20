# Code
```C++
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
```

### Description
You've begun working in the one and only Umbristan, and it is part of your job duty to organize newspapers. Every morning, your fellow coworkers will dilligently read through the newspapers to examine its contents. It is your job to organize the newspapers into piles and hand them out to your coworkers to read through.

Each newspaper is marked with the time it would take to read through its contents. The newspapers are carefully laid out in a line in a particular order that must not be broken when assigning the newspapers. You cannot pick and choose newspapers randomly from the line to assign to a co-worker. Instead, you must take newspapers from a particular subsection of the line, make a pile and give that to a co-worker.

What is the minimum amount of time it would take to have your coworkers go through all the newspapers?

### Constraints

`1 <= newspapers_read_times.length <= 10^5`

`1 <= newspapers_read_times[i] <= 10^5`

`1 <= num_coworkers <= 10^5`

### Examples

#### Example 1:

#### Input: `newspapers_read_times = [7,2,5,10,8], num_coworkers = 2`

#### Output: `18`

#### Explanation:

Assign first `3` newspapers to one coworker then assign the rest to another. The time it takes for the first `3` newspapers is `7 + 2 + 5 = 14` and for the last `2` is `10 + 8 = 18`.

#### Example 2:

#### Input: `newspapers_read_times = [2,3,5,7], num_coworkers = 3`

#### Output: `7`

#### Explanation:

Assign `[2, 3]`, `[5]`, and `[7]` separately to workers. The minimum time is `7`.

# Notes
[[Capacity to Ship Packages Within D Days]] <- The same idea, but instead of days we have people who read the book. 

# Run Time / Space Time
Run time - O(nlgn) -> n to get the cummulative time
Space time - O(1) -> no extra space needed