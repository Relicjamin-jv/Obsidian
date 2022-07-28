#include <algorithm> // copy
#include <iostream> // cin, cout
#include <iterator> // back_inserter, istream_iterator, ostream_iterator, prev
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

//all sorts without looking at any help

//failed, failed, passed
std::vector<int> insertion_sort(std::vector<int> unsorted_list) {
  int pointer, key;
  for(int i = 0; i < unsorted_list.size(); i++){
    key = unsorted_list[i];
    pointer = i - 1;
    while(pointer >= 0 && unsorted_list[pointer] > key){
      unsorted_list[pointer + 1] = unsorted_list[pointer];
      pointer--;
    }
    unsorted_list[pointer + 1] = key;
  }
  return unsorted_list;
}

//failed, failed, passed
std::vector<int> merge_sort(std::vector<int> unsorted_list){
  int n = unsorted_list.size();
  if(n <= 1) return unsorted_list;
  int mid = n / 2;
  std::vector<int> leftList = merge_sort(std::vector<int>(unsorted_list.begin(), unsorted_list.begin() + mid));
  std::vector<int> rightList = merge_sort(std::vector<int>(unsorted_list.begin() + mid, unsorted_list.end()));
  std::vector<int> res;
  int right = 0, left = 0;
  while(left < mid || right < n - mid){
    if(left == mid){
      res.push_back(rightList[right]);
      right++;
    }
    else if(right == n - mid){
      res.push_back(leftList[left]);
      left++;
    }
    else if (leftList[left] <= rightList[right]){
      res.push_back(leftList[left]);
      left++;
    }
    else{
      res.push_back(rightList[right]);
      right++;
    }
  }
  return res;
}

//passed, passed, passed
void quick_sort_interval(std::vector<int> unsorted_list, int start, int end){
  if(end-start < 1) return;
  int pivot = unsorted_list[end];
  int end_prt = end, start_prt = start;
  while(start_prt < end_prt){
    //find pos to swap
    while(unsorted_list[start_prt] < pivot && start_prt < end_prt){
      start_prt++;
    }
    while(unsorted_list[end_prt] >= pivot && start_prt < end_prt){
      end_prt--;
    }
    if(start_prt == end_prt) break;
    int temp = unsorted_list[start_prt];
    unsorted_list[start_prt] = unsorted_list[end_prt];
    unsorted_list[end_prt] = temp;
  }
  int temp = unsorted_list[start_prt];
  unsorted_list[start_prt] = unsorted_list[end];
  unsorted_list[end] = temp;
  quick_sort_interval(unsorted_list, 0, start_prt - 1);
  quick_sort_interval(unsorted_list, start_prt + 1, end);
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

