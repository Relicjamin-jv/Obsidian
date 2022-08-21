```C++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* current = head;
        ListNode* sortedList = NULL;
        
        
        while(current != NULL){
            //grab the next node
            ListNode* nextNode = current->next;
            
            //insertion logic
            //special case for when head of node need to be changed
            if(sortedList == NULL || sortedList->val >= current->val){
                current->next = sortedList; //adding it to the sorted list and removing it from the unsorted list
                sortedList = current; //point to the new head
            }else{ //inserting the node somewhere else
                //need to find the node we are going to be inserting too
                ListNode* fNode = sortedList; 
                while(fNode->next != NULL && fNode->next->val < current->val){
                    fNode = fNode->next;
                }
                //need to rearrage the points to insert
                current->next = fNode->next;
                fNode->next = current;
            }
            current = nextNode;
        }
        return sortedList;
    }
};
```
Given the `head` of a singly linked list, sort the list using **insertion sort**, and return _the sorted list's head_.

The steps of the **insertion sort** algorithm:

1.  Insertion sort iterates, consuming one input element each repetition and growing a sorted output list.
2.  At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list and inserts it there.
3.  It repeats until no input elements remain.

The following is a graphical example of the insertion sort algorithm. The partially sorted list (black) initially contains only the first element in the list. One element (red) is removed from the input data and inserted in-place into the sorted list with each iteration.

# Solved
- Since it's a singly linked list the programmer is limitted by the sinle link between the nodes and forces for nodes to be inserted starting from the left to the right. Meaning that it requires a new singly linked list to put the nodes into for the correct order. Think normal insertion sort, however left to right instead of right to left (how a programmer would implement it in an array)

# Run Time/Space Time
Run Time - O(n^2) 
Space Time - O(n)

# Features
- Stable (Element do not switch with each other unless the element that we are currently looking at is larger - larger because we are working from left to right for an ascneding list in SLL)
- Not in place (Needed another SLL to put the sorted values) 