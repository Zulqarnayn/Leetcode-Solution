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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode newHead = ListNode(0), * head = &newHead;
        int remaining = 0;
        
        while(remaining || l1 || l2) {
            int sum = remaining;
            
            if(l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            
            if(l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            
            
            remaining = sum / 10;
            head->next = new ListNode(sum % 10);
            head = head->next;
        }
        
        return newHead.next;
    }
};