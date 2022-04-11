class Solution {
public:
    string getDouble(string s) {
        int Double = 2 * stoi(s);
        return to_string(Double);
    }
    
    string add2String(string a, string b) {
        int sum = stoi(a) + stoi(b);
        return to_string(sum);
    }
    
    int calPoints(vector<string>& ops) {
        stack<string> points;
        int size = ops.size(), idx = 0;
        
        while(idx < size) {
            if(ops[idx] == "D") {
                string top = points.top();
                points.push(getDouble(top));
            } else if(ops[idx] == "+") {
                string first = points.top(); 
                points.pop();
                string second = points.top();
                points.pop();
                
                points.push(second);
                points.push(first);
                points.push(add2String(first, second));
            } else if(ops[idx] == "C") {
                points.pop();
            } else {
                points.push(ops[idx]);
            }
            
            idx++;
        }
        
        int sum = 0;
        
        while(points.size() > 0) {
            sum += stoi(points.top());
            points.pop();    
        }
        
        return sum;
    }
};