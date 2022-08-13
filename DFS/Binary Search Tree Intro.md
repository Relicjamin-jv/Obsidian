
Topic: Binary Search Tree Intro
Date: Aug 5, 2022

---

### Questions/Cues
- Item

### Notes
- A BST is a rooted binary tree with the value of each interanal node being greater than all the values in the respective node's left subtree and less than the ones in the right subtree.
	-![[Pasted image 20220812123621.png]]
- The primary purpose of a BST is to search, very similar to searching using a binary search ([[Vanilla Binary Search]]). We do this by looking at the current node and if the target is less than the target node then we search in the right subtree (where all the nodes get bigger). If the target is greater than the current node then we go down the left side of the subtree (where the nodes are getting smaller).
- The runtime to search is O(lgn) but only if the tree is balanced. (or O(h) where h is the height of the tree. It depends on how you want to think about it).
- Very useful for dynamically inputting data. Although is dynamically inputting data is not needed then you can just sort the array and do a [[Vanilla Binary Search]].
- Hash tables are also very useful for dynamically inputting data, and are usually perfered over BST. However there are some benefits over hash tables that BST have.
	- BST are sorted
	- Easy to lookup the first element that is bigger or smaller than the lookup value.
	- It easy to find the kth largest/smallest element
	- Dynamic hashtables use more memory then they need while BST only uses the memory it needs.
### Summary
BST is often used to search the existence of an element.
