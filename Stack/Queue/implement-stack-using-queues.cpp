// Leetcode 225. implement-stack-using-queues
//https://leetcode.com/problems/implement-stack-using-queues/

/*
Author :: Sonali🌹
*/
class MyStack {
public:
    queue<int>son,sona;
    MyStack() {}
    void push(int x) {
        sona.push(x);
        while(!son.empty()){
            sona.push(son.front());
            son.pop();}
        swap(son, sona);}
    int pop() {
        int res= son.front();
        son.pop();
        return res;}
    int top() {return son.front();}  
    bool empty() {return son.empty();}}; 