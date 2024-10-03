// Leetcode 735. asteroid-collision
// https://leetcode.com/problems/asteroid-collision/

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        int n = ast.size();
        vector<int> st;

        for(int i=0;i<n;i++){
            if(ast[i] > 0){
                st.push_back(ast[i]);
            }
            else{
                while(!st.empty() && (st.back() > 0) && (abs(ast[i]) > st.back()) ){
                    st.pop_back();
                }
                if(!st.empty() && (st.back() == abs(ast[i])) ) st.pop_back();
                else if(st.empty() || st.back() < 0) st.push_back(ast[i]);
            }
        }
        return st;
    }
};