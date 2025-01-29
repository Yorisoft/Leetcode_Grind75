/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 // if pos <= linkedList.size()
 // linkedList.tail points to an element in my list, thus there is a loop


class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* myNode = head;
        int counter = 0;


        std::multimap<ListNode*, int> nodeIndexMap;
        while(myNode){
            auto it = nodeIndexMap.find(myNode->next);
            if(it != nodeIndexMap.end() && it->second < counter )
                return true;
            
            nodeIndexMap.insert({myNode, counter});
            myNode = myNode->next;
            counter++;
        }
        return false;
    }
};


/*
Approach 1: Two-Pointer Technique (Slow and Fast Pointers with Head Start)
This approach utilizes two pointers, slow and fast.
Initially, slow starts at the head, and fast starts at the second node (head->next).
The slow pointer moves one step at a time, while the fast pointer moves two steps.
If there is a cycle, the fast pointer will eventually meet the slow pointer within the cycle.
If fast reaches the end of the list (NULL), it means there is no cycle.
Complexity
Time complexity: O(N)
Space complexity: O(1)
*/

class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return false;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast != slow) {
            if (fast->next == NULL || fast->next->next == NULL) {
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};



/*
Approach 2: Two-Pointer Technique (Slow and Fast Pointers without Head Start)
This is a variation of the first approach. Both slow and fast pointers start at the head.
slow moves one step at a time, and fast moves two steps.
If there is a cycle, they will meet at some point within the cycle.
If fast reaches the end (NULL), the list does not contain a cycle.
Complexity
Time complexity: O(N)
Space complexity: O(1)
*/

class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return true;
            }
        }
        return false;
    }
};