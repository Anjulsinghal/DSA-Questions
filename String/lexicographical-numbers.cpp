// Leetcode 386 lexicographical-numbers
// https://leetcode.com/problems/lexicographical-numbers/


// Brute Force
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string> ans;
        for(int i=1;i<=n;i++){
            string temp = to_string(i);
            ans.push_back(temp);
        }
        sort(ans.begin(), ans.end());
        vector<int> ret;
        for(auto it:ans){
            int i = stoi(it);
            ret.push_back(i);
        }
        return ret;
    }
};


// Optimal
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        // vector<int> pointer(9,0);
        vector<int> ans;
        int curr = 1;
        for(int i=1;i<=n;i++){
            ans.push_back(curr);
            if(curr*10<=n)
            curr = curr*10;
            else
            {
                while(curr%10==9 || curr>=n)
                {
                curr = curr/10;   
                } 
                curr += 1;
            }
        } 
        return ans;
    }
};