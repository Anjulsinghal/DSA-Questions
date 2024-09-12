// 1684. https://leetcode.com/problems/count-the-number-of-consistent-strings/

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int cnt = 0;

        for(string str:words){
            bool isCons = true;
            for(char c:str){
                if(allowed.find(c) == string::npos){
                    isCons = false;
                }   
            }
            if(isCons){
                cnt++;
            }
        }
        return cnt++;
    }
};