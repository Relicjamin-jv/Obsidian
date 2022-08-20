
Topic: Iterators
Date: Aug 3, 2022

---

### Questions/Cues
- Item

### Notes
- A way to traverse a data structure.
- The vector class has an iterator that we can use.
- Not everything has a simple indexing system like vector. This leads us to write our own iterators

```c++
#include <vector>
#An example of how to use iterator on vector ::interator func
for(std::vector<int>::iterator it = values.begin());
	it != value.end(); it++){
		std::cout << *it << std::endl;
	}
```
- There are a ton of interators to use. Such as ostring_interator() that takes an object T and interates over it using a delimiter.

### Summary
Highlight ==what’s important!==
