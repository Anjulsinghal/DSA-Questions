// Leetcode 137. Single Number 2

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // unordered_map<int, int> ans;
        //Brute Force
        // for(int i=0;i<nums.size();i++){
        //     // if(ans.find(nums[i]) != ans.end()){
        //     //     ans[nums[i]]++;
        //     // }
        //     ans[nums[i]]++;
        // }
        // for(auto it:ans){
        //     if(it.second == 1){
        //         return it.first;
        //     }
        // }
        // return 0;

        // Better
        // sort(nums.begin(), nums.end());
        // for(int i=1;i<nums.size();i=i+3){
        //     if(nums[i] != nums[i-1]) return nums[i-1];
        // }
        // return nums[nums.size()-1];

        // Optimal
        int ones =0;
        int twos =0;
        for(int i=0;i<nums.size();i++){
            ones = (ones^nums[i])& ~twos;
            twos = (twos^nums[i]) & ~ones;
        }
        return ones;
    }
};