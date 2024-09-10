// Leetcode 260. Single Number 3
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long num = 0;
        int n = nums.size();
        for(int n:nums){
            num ^= n;
        }

        int mrOne = num & -num;

        int b1 =0;
        int b2 =0;

        for(int n:nums){
            if(n&mrOne){
                b1 ^= n;
            }else b2 ^= n;
        }

        return {b1, b2};
    }
};