/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root) return {};
        
        queue<Node*> orderQ;
        orderQ.push(root);
        
        vector<vector<int>> result;
        
        while(!orderQ.empty()) {
            int size = orderQ.size();
            vector<int> currentLevel;
            
            for(int idx = 0; idx < size; idx++) {
                Node* top = orderQ.front();
                orderQ.pop();
                currentLevel.push_back(top->val);
                
                for(int i = 0; i < top->children.size(); i++) {
                    orderQ.push(top->children[i]);
                }
            }
            
            result.push_back(currentLevel);
        }
        
        return result;
    }
};