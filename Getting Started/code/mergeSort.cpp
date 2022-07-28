#include <algorithm> // copy
#include <iostream> // cin, cout
#include <iterator> // back_inserter, istream_iterator, ostream_iterator, prev
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

/*
 *Runtime is O(nlogn) -> Gets cut in half every recusrsive call, then to recombine it into a sorted array takes n time
 * */

std::vector<int> sort_list(std::vector<int> unsorted_list){
  int n = unsorted_list.size();
  if(n <= 1) return unsorted_list; //if the element gets down to one element then we return
  int middle = n / 2; //interger division, will grab the floor of what it divides
  std::vector<int> left_list = sort_list(std::vector<int>(unsorted_list.begin(), unsorted_list.begin() + middle));//seperate into two new arrays left and right, then take the result from recusion and continue
  std::vector<int> right_list = sort_list(std::vector<int>(unsorted_list.begin() + middle, unsorted_list.end())); 
  std::vector<int> result; //where the values will be sorted into for each recursion layer
  int left = 0, right = 0;
  while(left < middle || right < n-middle){ //while there is still something to be sorted
    if(left == middle){ //if the left is empty then the right list has values (already in sorted order, just need to push them onto the new sorted list)
      result.push_back(right_list[right]);
      right++;
    }else if (right == n - middle){ //if there is nothing in the right list
      result.push_back(left_list[left]);
      left++;
    }else if (left_list[left] <= right_list[right]){ //if the right is less than the right
      result.push_back(left_list[left]);
      left++;
    }else{ //if right is less than the left
      result.push_back(right_list[right]);
      right++;
    }
  }
  return result;
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


template<typename T>
void put_words(const std::vector<T>& v) {
    if (!v.empty()) {
        std::copy(v.begin(), std::prev(v.end()), std::ostream_iterator<T>{std::cout, " "});
        std::cout << v.back();
    }
    std::cout << '\n';
}


int main() {
    std::vector<int> unsorted_list = get_words<int>();
    std::vector<int> res = sort_list(unsorted_list);
    put_words(res);
}
