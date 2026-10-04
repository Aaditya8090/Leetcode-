// class MinStack {
// public:
//     stack<pair<int, int>>st;
//     MinStack() {
        
//     }
    
//     void push(int value) {
//         if(st.empty())
//             st.push({value, value});
//         else{
//             st.push({value, min(value, st.top().second)});
//         }
//     }
    
//     void pop() {
//         if(!st.empty())
//             st.pop();
//     }
    
//     int top() {
//         if(!st.empty())
//             return st.top().first;
//         return -1;
//     }
    
//     int getMin() {
//         if(!st.empty())
//             return st.top().second;
//         return -1;
//     }
// };

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */



// Approach 2
// Maintain two stack
class MinStack {
    private:
        stack<int>main;
        stack<int>min;
public:
    MinStack() {
        
    }
    
    void push(int value) {
        main.push(value);
        if(min.empty() || value <= min.top()){
            min.push(value);
        }
    }
    
    void pop() {
        if(!main.empty()){
            if(main.top() == min.top())
                min.pop();
            main.pop();
        }
    }
    
    int top() {
        if(!main.empty())
            return main.top();
        return -1;
    }
    
    int getMin() {
        if(!min.empty())
            return min.top();
        return -1;
    }
};

// /**
//  * Your MinStack object will be instantiated and called as such:
//  * MinStack* obj = new MinStack();
//  * obj->push(value);
//  * obj->pop();
//  * int param_3 = obj->top();
//  * int param_4 = obj->getMin();
//  */