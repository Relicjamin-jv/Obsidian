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
```

### Description
There are `n` packages that needs to be transported from one city to another, and you need to transport them there within `d` days. For the `i`th package, the weight of the package is `weights[i]`. You are required to deliver them in order with a rental truck. The rental trucks come in different sizes. The bigger trucks have greater weight capacity but cost more to rent. To minimize cost, you want to deliver the packages in one truck once per day, with a weight capacity as small as possible to save on rental cost. What is the minimum weight capacity of the truck that is required to deliver all packages within `d` days?

### Input

-   `weights`: A list of packages and their weights.
-   `d`: The number of days to deliver all packages.

### Output

The minimum weight capacity of the truck.

### Examples

#### Example 1:

**Input**:

```
weights = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
```

```
d = 5
```

**Output**: `15`

**Explanation**:

The first day we deliver the first `5` package. The second day we deliver the next `2`, and for each following days, we deliver `1`. The maximum weight delivered on each day is `15`, so we can have a truck with a capacity of `15`. This value is the minimum.

# Notes
- Must be taken in order, so whatever is first is whatever is taken next.
- This works by making the truth table a range from the heaviest package (since we would at least have to take the truck with at least the min cap for this package) to the accumulation of all the packages weights. Meaning for (1, 2, 3) we would have the a left min of 3 and the right max of 6.
- The helper functioin determines if the number of days with the tested weight will work. It does this by iterating over the weights and subtrating them from the cap. if the weight ever becomes more than the capacity then we reset the capacity and add an required day.

# Run Time / Space Time
Run time - O(nlgn) Linear time for the helper function, and O(lgn) for the BS
Space time - O(1), no additional space is required.