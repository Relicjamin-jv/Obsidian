#include <iostream> // cin, cout


struct ListNode{
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
}; 

class Solution{
  public:
    ListNode* insertionSortLinkedList(ListNode* head){
      ListNode* current = head; //setting a pointer to the head of the unsorted memory
      ListNode* sortedList = NULL; //nothing in the array

      while(current != NULL){
        ListNode* nextNode = current->next;
        
        //special case when the current node needs to be inputted into the head of the node
        if(sortedList == NULL || sortedList->val >= current->val){
          current->next = sortedList; //removing the node from being connected to the unsorted list and inserting it to the new sortedList
          sortedList = current; //setting the head of sortedList
        }else{ //otherwise the new node needs to inserted somewhere else withing the SLL
          //need the node that is before the place that we need to insert it too
          ListNode* findNode = sortedList;
          while(findNode->next != NULL && findNode->next->val < current->val){ //this will give us the node that is right before where the node should be placed
            findNode = findNode->next;      
          }
          //rearraging the pointers in order to insert the new node
          current->next = findNode->next;
          findNode->next = current;
        }
        current= nextNode;
      }
      return sortedList;
    }
};


int main(){
  Solution solution;
  
  struct ListNode* head = NULL;

  for(int i = 0; i < 10; i++){
    struct ListNode* new_node = (struct ListNode*) std::malloc(sizeof(struct ListNode));
    new_node->val = rand() % 100;
    new_node->next = head;
    head = new_node;
  }

  ListNode* headSoln = solution.insertionSortLinkedList(head);

  while(headSoln != NULL){
    std::cout << headSoln->val << " " << std::endl;
    headSoln = headSoln->next;
  }
}
