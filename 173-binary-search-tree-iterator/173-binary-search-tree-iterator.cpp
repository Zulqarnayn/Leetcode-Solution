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
class BSTIterator {
    //queue<int> sortedQueue;
    
    stack<TreeNode*> currStack;
public:
    BSTIterator(TreeNode* root) {
        // TC: O(1) , SC: O(H) 
        // we just iterate to current height H, not whole tree initially
        updateStack(root);
        
        /*
        //This approach is takes O(1) time and O(N) memory
        
        TreeNode* curr = root;
        stack<TreeNode*> nodes;
        
        while(curr != nullptr || nodes.size() > 0) {
            while(curr != nullptr) {
                nodes.push(curr);
                curr = curr->left;
            }
            
            curr = nodes.top();
            nodes.pop();
            sortedQueue.push(curr->val);
            
            curr = curr->right;
        }
        */
    }
    
    void updateStack(TreeNode* node) {
        while(node != nullptr) {
            currStack.push(node);
            node = node->left;
        }
    }
    
    int next() {
        TreeNode* top = currStack.top();
        currStack.pop();
        updateStack(top->right);
        return top->val;
        
        /*
        int res = sortedQueue.front();
        sortedQueue.pop();
        return res;
        */
    }
    
    bool hasNext() {
        return !currStack.empty();
        // return !sortedQueue.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */