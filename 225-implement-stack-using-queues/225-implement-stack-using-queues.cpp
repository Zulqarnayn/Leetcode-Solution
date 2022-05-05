class MyStack {
    queue<int> qMain, qBackup;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        passToBackup(0);
        qMain.push(x);
    }
    
    int pop() {
        int frontElem = qMain.front();
        qMain.pop();
        rearrange();
        return frontElem;
    }
    
    int top() {
        int frontElem = qMain.front();
        return frontElem;
    }
    
    bool empty() {
        return qMain.empty() && qBackup.empty();
    }
    
    void rearrange() {
        //this method will do 1 thing
        //if main queue is empty
        //than swap backup with main and
        //keep only one number in main
        swap(qMain, qBackup);
        passToBackup(1);
    }
    
    void passToBackup(int limit) {
        while(qMain.size() > limit) {
            int frontElem = qMain.front();
            qBackup.push(frontElem);
            qMain.pop();
        }
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */