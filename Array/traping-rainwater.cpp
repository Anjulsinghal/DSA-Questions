// Leetcode 42 Traping Rain Water
// https://leetcode.com/problems/trapping-rain-water/

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n-1;
        int leftMax = 0;
        int rightMax = 0;
        int res = 0;

        while(left <= right){
            if(height[left] <= height[right]){
                if(height[left] >= leftMax) leftMax = height[left];
                else res += (leftMax - height[left]);
                left++;
            }
            else{
                if(height[right] >= rightMax) rightMax = height[right];
                else res += (rightMax - height[right]);
                right--;
            }
        }
        return res;
    }
};