
![[Pasted image 20220726190736.png]]

Sorting an array in ascending order using mergesort

# Solved
Takes an array and cut it in half and then send those two seperate arrays into an recursive call, until it reaches the base case where the new array that is passed in is of size 1. Then it combines each of the new arrays by taking whatever value at the start of each respective array is less (giving it ascending order). Each array that is being passed up from each recursive call is already sorted.

# Run Time/Space Time
Run time - O(nlogn) -> logn beacause the n size array gets cut in half everytime, n to recombine the n elements.

Space time - O(n) -> Need to store the data somewhere and the new arrays dont cause an exponetial growth but a linear one. (Stackoverflow states that it only cost at most 3n memory)

# Features
- Stable -> Values stay where they are unless they need to be moved in order to sort the list.