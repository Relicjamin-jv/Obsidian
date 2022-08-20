#include <algorithm> // copy
#include <iostream> // cin, cout
#include <iterator> // back_inserter, istream_iterator, ostream_iterator, prev
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

/*O(nlgn) average ture worst case is O(n^2)
 *Space Time - lg(n) -> recurusion layers 
 * */

void sort_list_interval(std::vector<int> &unsorted_list, int start, int end) {
  //base case
  if(end - start < 1) return;
  int start_ptr = start, end_ptr = end;
  int pivot = unsorted_list[end]; //the end is always going to be the pivot

  while(start_ptr < end_ptr){
    //finding the swap postions
    while(unsorted_list[start_ptr] < pivot && start_ptr < end_ptr){
      start_ptr++;
    }
    while(unsorted_list[end_ptr] >= pivot && start_ptr < end_ptr){
      end_ptr--;
    }
    if(start_ptr == end_ptr) break; //we've traversed all we can now we want to swap the pivot
    //otherwise we want to swap the pointers values
    int temp = unsorted_list[start_ptr];
    unsorted_list[start_ptr] = unsorted_list[end_ptr];
    unsorted_list[end_ptr] = temp;
  }
  int temp = unsorted_list[end]; //grabbing the pivot
  unsorted_list[end] = unsorted_list[start_ptr]; //putting the pivot in the correct spot
  unsorted_list[start_ptr] = temp; //putting the value that was inbetween to the end spot. Should be grater
  //time to cut it up and send it
  sort_list_interval(unsorted_list, start, start_ptr - 1);
  sort_list_interval(unsorted_list, start_ptr + 1, end);
}


std::vector<int> sort_list(std::vector<int> unsorted_list) {

    sort_list_interval(unsorted_list, 0, unsorted_list.size() - 1);

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
    std::vector<int> unsorted_list = get_words<int>();
    std::vector<int> res = sort_list(unsorted_list);
    put_words(res);
}
