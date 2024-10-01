// Leetcode 496 next-greater-element-i
// https://leetcode.com/problems/next-greater-element-i/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>res(nums1.size() , -1); // result array
        stack<int>stk; // stack
        map<int,int>mp; // hash map
        for(int num : nums2){

            // stack.top < num
            while(!stk.empty() and stk.top() < num){
                mp[stk.top()] = num;
                stk.pop();
            }
            // push into stack
            stk.push(num);
        }
        for(int i = 0 ; i < nums1.size() ; i++){
            if(mp[nums1[i]]) 
                res[i] = mp[nums1[i]];
        }
        return res;
    }
};