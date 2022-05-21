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
    
    ListNode* reverseLinkedList(ListNode* curr) {
        ListNode* prev = nullptr, *next;
        
        while(curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return true;
        
        ListNode* slow = head, *fast = slow->next;
        
        while(fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
            if(fast) fast = fast->next;
        }
        
        fast = reverseLinkedList(slow);
        
        while(fast != nullptr && head != nullptr) {
            if(fast->val != head->val) return false;
            fast = fast->next;
            head = head->next;
        }
        
        return true;
        
    }
};