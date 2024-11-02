// Leetcode 84 largest-rectangle-in-histogram
// https://leetcode.com/problems/largest-rectangle-in-histogram/

class Solution {
    
public:
    int largestRectangleArea(vector<int>& hi) {
        stack<int> st;
        int maxArea = 0;

        for(int i=0;i<hi.size();i++){
            while(!st.empty() && hi[st.top()] > hi[i]){
                int element = st.top();
                st.pop();
                int nse = i;
                int pse = st.empty() ? -1 : st.top();
                maxArea = max(maxArea, hi[element] * (nse - pse - 1));
            }
            st.push(i);
        }

        while(!st.empty()){
            int nse = hi.size();
            int element = st.top();
            st.pop();
            int pse = st.empty() ? -1 : st.top();
            maxArea = max(maxArea, (nse-pse-1)*hi[element]);
        }
        return maxArea;
    }
};