#include <vector>
#include <iostream>
#include <algorithm>

int main(){
  std::vector<int> unsorted{100, 2 , 4, 63, 82, 71};

  std::sort(unsorted.begin(), unsorted.end());

  for (int i : unsorted){
    std::cout << i << " " << std::endl;
  }
}
