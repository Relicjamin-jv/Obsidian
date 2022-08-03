
Topic: Trees
Date: Aug 2, 2022

---

### Questions/Cues
- Item
### Notes
- *Internal Nodes* - Every node in the tree that has at least one child.
- *Leaf Nodes* - Every node that has no children nodes.
- *Ancestor* - All the nodes that are between the path from the root to the current node. Aka every node that came before getting to the current node.
- *Descendent* - All the nodes that are reachable from the current node.
- *Level* - the level of the node is the number of ancestors from the node to the root node. The root node has a level of 0.
- *Depth* - The depth of a node is the number of edges on the path from the root of that node.
- *Height* - The height of the node is the numnber of edges on the longest path from that node to a leaf. The height of a tree is the height of its root node.
![[Pasted image 20220802143638.png]]

##### Binary Tree:
- An n-ary tree in which case each node can only have two children.
- Know in shorthand as a BST.
- BST follow this property. All left decscendents < node < all right descendents.
- The tree is consider balanced if the height difference of the left and right subtree is not more than one. This makes adding to a binary tree take O(logn) instead of O(n). Examples of this are red-black trees and AVL trees.

##### Traversing Trees:
- In-order
	- Visit the left branch first, then the current node, and then the right branch.
	- Done via recursion.
	- ![[Pasted image 20220802144714.png]]
- Pre-order
	- Visit the current node, then the left branch then the right brach.
	- Done via recursion
	- ![[Pasted image 20220802144727.png]]
- Post-order Traversal
	- Visits the left subtree, then the right subtree and then the current node.
	- Done via recursion 
	- ![[Pasted image 20220802144839.png]]

##### How Algo Monster Encodes Binary Trees
- Algo Monster encodes binary trees as strings in pre order traversal. Meaning "5 4 3 x x 8 x x 6 x x" ->
![[Pasted image 20220802145402.png]]

##### How Algo Monster Encodes n-ary Trees
- Still encoded into a string, however, each node value will have a number of children value right after. "7 3" -> meaning node 7 has three children.
- Example: "7 3 2 1 5 0 3 0 4 0" -> 7 has 3 children. 2 has 1, 5 has 0, 3 has 0, and 4 has 0.
![[Pasted image 20220802145810.png]]
### Summary
#### When to use DFS
- To traverse and find/create/modify/delete nodes
- To traverse and get a return value (finding max subtreem detect balanced tree)
- How many ways there are to arrange something
- Find all possible combinations
- Find all solutions to a puzzle
- Find a path from A to B
- Find connected nodes
- Detect Cycles