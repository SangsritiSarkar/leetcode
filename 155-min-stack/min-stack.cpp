class MinStack {
public:
    stack<long long> st;
    long long mini;
    
    void push(int v) {
        long long val= v;
        if(st.empty()) {
            mini=val;
            st.push(val);
        }
        else{
            if(val<mini){
                // int prev_min=mini;
                // int curr_min=val;
                // int push_ele=2*curr_min-prev_mini
                st.push(2*val*1LL-mini);
                mini=val;//original st.top()
            }
            else st.push(val);
        }
    }
    
    void pop() {
        if(st.empty()) return;
        long long x=st.top();
        st.pop();
        if(x<mini) { //modified i.e. original st.top()=mini and need prev_mini from the above formula           
            mini=2*mini-x; //prev_mini=2*curr_mini-push_ele
        }
    }
    
    int top() {
        if(st.empty()) return -1;
        long long x=st.top();
        if(x<mini) return mini;
        return x;
    }
    
    int getMin() {
        return mini;
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