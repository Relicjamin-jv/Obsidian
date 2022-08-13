# Code
```C++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr) return nullptr;
        
        if(root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p ,q);
        if(left && right) return root;
        if(left) return left;
        if(right) return right;
        return nullptr;
    }
};
```

### Description
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the [definition of LCA on Wikipedia](https://en.wikipedia.org/wiki/Lowest_common_ancestor): “The lowest common ancestor is defined between two nodes `p` and `q` as the lowest node in `T` that has both `p` and `q` as descendants (where we allow **a node to be a descendant of itself**).”

**Example 1:**

![](https://assets.leetcode.com/uploads/2018/12/14/binarytree.png)

**Input:** root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
**Output:** 3
**Explanation:** The LCA of nodes 5 and 1 is 3.

**Example 2:**

![](https://assets.leetcode.com/uploads/2018/12/14/binarytree.png)

**Input:** root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
**Output:** 5
**Explanation:** The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.

**Example 3:**

**Input:** root = [1,2], p = 1, q = 2
**Output:** 1

**Constraints:**

-   The number of nodes in the tree is in the range `[2, 105]`.
-   `-109 <= Node.val <= 109`
-   All `Node.val` are **unique**.
-   `p != q`
-   `p` and `q` will exist in the tree.

# Notes
- There are five cases to look at here
	- 1.![[Pasted image 20220811164833.png]]
		- The nodes we are looking for are in the left and right subtree of the respective LCA![[Pasted image 20220811164927.png]]
	- 2.![[Pasted image 20220811164950.png]]
		- The Current node is one of the target and the other node is in a subtree
			 ![[Pasted image 20220811165056.png]]
	- 3.Current node is not target node and the subtree has no target nodes
		- ![[Pasted image 20220811165157.png]]
		- Finishes with nullptr
	- 4. Current node is in the path between the LCA and target node 
		- ![[Pasted image 20220811165239.png]]
		- ![[Pasted image 20220811165342.png]]
	- LCA is in the subtree of the current node
		- ![[Pasted image 20220811165306.png]]
		- ![[Pasted image 20220811165345.png]]
	- Each case has its respective things to do, if case 1 does not happen then we are not in the LCA then it will continue down the left and right subtrees until it finds the either target node in which it will return the target node to the parent. In which if left and right have the target node then case 1, if we get to a target node then we just return that target, case 2. The other cases 4 is if we found one target node but not the other. We return a nullptr when target node are both not found for that subtree.
# Run Time / Space Time
Run time - O(n)
Space time - O