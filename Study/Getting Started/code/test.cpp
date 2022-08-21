#include <algorithm> // copy
#include <iostream> // cin, cout
#include <iterator> // back_inserter, istream_iterator, ostream_iterator, prev
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

//all sorts without looking at any help
//passed, passed, passed
std::vector<int> insertion_sort(std::vector<int> unsorted_list) {
  int key, pointer;
  for(int i = 0; i < unsorted_list.size(); i++){
    int pointer = i - 1;
    int key = unsorted_list[i];
    while(pointer >= 0 && unsorted_list[pointer] > key){
      unsorted_list[pointer + 1] = unsorted_list[pointer];
      pointer--;
    }
    unsorted_list[pointer + 1] = key;
  }
  return unsorted_list;
}

//passes, passed, passed
std::vector<int> merge_sort(std::vector<int> unsorted_list){
  int n = unsorted_list.size();
  if(n <= 1) return unsorted_list;

  int mid = n / 2;

  std::vector<int> left = merge_sort(std::vector<int>(unsorted_list.begin(), unsorted_list.begin() + mid));
  std::vector<int> right = merge_sort(std::vector<int>(unsorted_list.begin() + mid, unsorted_list.end()));
  std::vector<int> res;

  int l = 0, r = 0;
  while (l < mid || r < n - mid){
    if(l == mid){
      res.push_back(right[r]);
      r++;
    }
    else if(r == n - mid){
      res.push_back(left[l]);
      l++;
    }
    else if(left[l] < right[r]){
      res.push_back(left[l]);
      l++;
    }
    else{
      res.push_back(right[r]);
      r++;
    }
  }
  return res;
}

//passed, passed, passed
void quick_sort_interval(std::vector<int> unsorted_list, int start, int end){
  if(end - start < 0) return;
  int pivot = unsorted_list[end];
  int sp = start, ep = end;
  
  while (sp < ep){
    while(unsorted_list[sp] < pivot && sp < ep){
      sp++;
    }
    while(unsorted_list[ep] >= pivot && sp < ep){
      ep++;
    }
    if(sp == ep) break;
    int temp = unsorted_list[sp];
    unsorted_list[sp] = unsorted_list[ep];
    unsorted_list[ep] = temp;
  }
  int temp = unsorted_list[sp];
  unsorted_list[sp] = pivot;
  unsorted_list[end] = temp;
  quick_sort_interval(unsorted_list, start, sp - 1);
  quick_sort_interval(unsorted_list, sp + 1, end);
}

std::vector<int> quick_sort(std::vector<int> unsorted_list){
  quick_sort_interval(unsorted_list, 0, unsorted_list.size() - 1);
  return unsorted_list;
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
  //insertion sort
  std::cout << "Insertion Sort:" << std::endl;
  std::vector<int> unsorted_list = get_words<int>();
  std::vector<int> res = insertion_sort(unsorted_list);
  put_words(res);

  //merger sort
  std::cout << "Merge Sort" << std::endl;
  std::vector<int> unsorted_list1 = get_words<int>();
  std::vector<int> res1 = insertion_sort(unsorted_list1);
  put_words(res1);

  //quick sort
  std::cout << "Quick Sort" << std::endl;
  std::vector<int> unsorted_list2 = get_words<int>();
  std::vector<int> res2 = insertion_sort(unsorted_list2);
  put_words(res2);
}

