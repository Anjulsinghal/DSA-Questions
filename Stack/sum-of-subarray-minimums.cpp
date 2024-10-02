// Leetcode 907. sum-of-subarray-minimums
// https://leetcode.com/problems/sum-of-subarray-minimums/

class Solution {
    vector<int> findNSE(vector<int>& arr){
        int n = arr.size();
        vector<int> nse(n, -1);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            nse[i] = st.empty() ? n :st.top();
            st.push(i);
        }
        return nse;
    }
    vector<int> findPSEE(vector<int>& arr){
        int n = arr.size();
        vector<int> psee(n, -1);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()] > arr[i])
                st.pop();
            psee[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return psee;
    }
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse = findNSE(arr);
        vector<int> pse = findPSEE(arr);
        int total = 0;
        int mod = (int)(1e9 + 7);
        for(int i=0;i<n;i++){
            int left = i - pse[i];
            int right = nse[i] -i;
            total = (total + (right * left * 1ll * arr[i]) % mod) % mod;
        }
        return total;
    }
};