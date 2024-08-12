class MinStack {
private:
    stack<int> mainStack;
    stack<int> minInfoStack;
public:
    MinStack() {
    }
    
    void push(int val) {
        if(!mainStack.empty()){
            mainStack.push(val);
            if(val < minInfoStack.top())
                minInfoStack.push(val);
            else
                minInfoStack.push(minInfoStack.top());
        }else{
            mainStack.push(val);
            minInfoStack.push(val);
        }
    }
    
    void pop() {
        mainStack.pop();
        minInfoStack.pop();
    }
    
    int top() {
        return mainStack.top();
    }
    
    int getMin() {
        return minInfoStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */