class MinStack {
public:
    stack<int> stk;
    stack<int> minStk;

    MinStack() {
        
    }
    
    void push(int val) {
        if (stk.empty()) {
            stk.push(val);
            minStk.push(val);
        }
        else {
            int currMin = minStk.top();
            if (val < currMin) {
                minStk.push(val);
            }
            else {
                minStk.push(currMin);
            }
            stk.push(val);
        }
    }
    
    void pop() {
        stk.pop();
        minStk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return minStk.top();
    }
};
