//1310. XOR Queries of a Subarray
#include <bits/stdc++.h>
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        // vector<int> ans;

        // for(int i=0;i<queries.size();i++){
        //     int start = queries[i][0];
        //     int end = queries[i][1];
        //     int xorr = 0;
        //     for(int j=start;j<= end;j++){
        //         xorr ^= arr[j];
        //     }
        //     ans.push_back(xorr);
        // }

        // return ans;


        //Optimal
        int n = arr.size();
        vector<int> pre(n);
        pre[0] = arr[0];

        for(int i=1;i<n;++i){
            pre[i] = pre[i-1] ^ arr[i];
        }

        vector<int> ans(queries.size());

        for(int i=0;i<queries.size();i++){
            int start = queries[i][0];
            int end = queries[i][1];
            if(start == 0){
                ans[i] = pre[end];
            }else{
                ans[i] = pre[end] ^ pre[start-1];
            }
        }

        return ans;
         
    }
};