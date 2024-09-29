// Leetcode 155. min-stack
// https://leetcode.com/problems/min-stack/

class MinStack {
public:
    stack<long long> st;
    long long mini;
    MinStack() {}

    void push(int val) {
        long long val2 = (long long)val;
        if(st.empty()){
            mini=val2;
            st.push(val2);
        }
        else{
            if(val2>mini){
                st.push(val2);
            }
            else{
                st.push(long(2*val2*1LL)-mini);
                mini=val2;
            }
        }
    }

    void pop() {
        if(st.empty()){
            return;
        }

        long long x=st.top();
        st.pop();
        if(x<mini){
            mini=(2*mini)-x;
        }
    }

    int top() {
        if(st.empty()){
            return -1;
        }
        long long x=st.top();
        if(mini<x){
            return x;
        }
        return mini;
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