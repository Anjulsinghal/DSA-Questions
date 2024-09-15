// Leetcode 1. Two Sum
//https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            int more = target - nums[i];
            if(mpp.find(more) != mpp.end()){
                return {mpp[more], i};
            }
            mpp[nums[i]] = i;
        }
        return {-1, -1};
    }
};