
Topic: Hashmaps
Date: Jul 5, 2022

---

### Questions/Cues
- Item

### Notes
- Hash Function - converts data of arbitrary size to a value of fixed size.
	- Simple hash function would be taking an array, summing it and modding it by 100. This would return a value of arbitrary size from 1 ... 99
	- Must all ways return the same hash given the input. Although not all inputs are the same that may have the same hashmap function output. ([3, 7], [10 , 1] would return the same hash, this is also known as a hash collection)
	- A good hash function has
		- easy calculations
		- the chance for a collision is very low
		- all possible values are utilized approximately equal

- Hash Table(Hash Map)
	- Data is stored in a fixed sized array. When adding a new (key, value) pair to the array, we use the hash function to generate that hash that corresponds to the index of the array using the key. Then the key is the index where we store the value at. When ever we have the same key again we just hash it again and we get the correct output since the hash always returns the same output given the key.
	- A collision is when a two different keys return the same hash.
		- One method of dealing with this is called seperate chaining. When hashing the key we check the index in the array that the key goes to. If there is nothing there then we can just go ahead and start a new list that corresponds to that index. If there is something already there then we just add to the end of that list the value.
		- Another stategy is called Open Addressing. This is where the same table is used to store everything (no other data structure) but we use the next unused space in memory when adding a new key.

### Summary
The runtime of a hashmap is O(n/k), k being the the array size of the table. However if every value is stored inside the same index in the hash table then the runtime goes to O(n). That the runtime to search a singley linked list.
