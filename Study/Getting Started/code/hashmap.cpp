#include <algorithm> // copy
#include <iostream> // cin, cout
#include <iterator> // back_inserter, istream_iterator
#include <map> // map
#include <sstream> // istringstream
#include <string> // getline, string
#include <unordered_map> // unordered_map
#include <vector> // vector
            


using namespace std;

unordered_map<int, int> get_counter(vector<int> arr){
  unordered_map<int, int> counter; //init the hashmap to store each number and its count
  for (int num : arr){
    //check if the num is a key in the hashmap
    if(counter.count(num)){
      counter[num] += 1; //updates the count of how many times this index in the hashmap was hit
    }else{
      counter[num] = 1; //set the counter to one other wise. It was first time that this counter was hit.
    }
  }
  return counter;
}

//Template are a cool feature that allow the ability for the compiler to generate code at compiler time depending on the context -> if int then generates a int variation of the function
template<typename T>
std::vector<T> get_words() {
    std::string line; //creates the var line 
    std::getline(std::cin, line); //getting the input from the terminal and setting line to be that input
    std::istringstream ss{line}; //creating an istringstream and passing line in
    std::vector<T> v; //creating an new array
    std::copy(std::istream_iterator<T>{ss}, std::istream_iterator<T>{}, std::back_inserter(v)); //copy funciton that iterates of a stream of data, first two inputs are the range, and the output is the last input params starting range
                                                                                                //back_inserter https://en.cppreference.com/w/cpp/iterator/back_inserter -> returns a std::back_inserter_iterator which can be used to add the end of the vector
    return v;
}


int main(){
  vector<int> arr = get_words<int>(); // creating an array that is inputted from the terminal
  unordered_map<int, int> counter = get_counter(arr); // Get the counter for each indexed hit, hashing
  map<int, int> ordered_counter(counter.begin(), counter.end()); //red black tree, key and value ordered in sorted order. Range constructor starting from the start of counter to the end of counter

  for(auto const& [key, val] : ordered_counter){ //iterates through all the key, val pairs in ordered_counter 
    cout << key << ' ' << val << endl; 
  }
}
