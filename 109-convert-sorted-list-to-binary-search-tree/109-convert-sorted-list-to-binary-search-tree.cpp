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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return convertToBST(head, nullptr);
    }
    
    TreeNode* convertToBST(ListNode* head, ListNode* tail) {
        if(head == tail) return nullptr;
        
        ListNode* fast = head;
        ListNode* slow = head;
        
        while(fast != tail && fast->next != tail) { // secret sauce is here | not nullptr but tail
            fast = fast->next->next;
            slow = slow->next;
        }
        
        TreeNode* result = new TreeNode(slow->val);
        result->left = convertToBST(head, slow);
        result->right = convertToBST(slow->next, tail);
        
        return result;
    }
};