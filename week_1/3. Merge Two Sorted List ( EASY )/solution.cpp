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
 // create a new listnode pointer ( list3 )
 //for each node in  list1 and list2, compare the values
 // add the lower value to list3 first then grater value. 
 // if nodes are the same value, just add
 // to add ex: 
 // listNode* list3
 // for each each element in the largest list( 1 or 2 )
 // compare values of list1 and list2. add them in order of accending order
 // listnode3+i.value = listnode1+i.val
 // listnode3+i.next = listnode2+i
 // listnode1 = listnode1.next
 //
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* list3 = new ListNode();
        ListNode* currentNode = list3;

        while(list1 && list2){
            if( list1->val < list2->val ){
                currentNode->next = list1;
                list1 = list1->next;
            } else {
                currentNode->next = list2;
                list2 = list2->next;
            }

            currentNode = currentNode->next;
        }
        currentNode->next = list1 ? list1 : list2;
        list3 = list3->next;
        return list3;
    }
};