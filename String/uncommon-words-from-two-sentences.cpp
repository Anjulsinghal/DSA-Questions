// Leetcode 884 uncommon-words-from-two-sentences
// https://leetcode.com/problems/uncommon-words-from-two-sentences/

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        string s = s1 + " " + s2;
        unordered_map<string,int> mpp;
        string temp="";
        for(auto& val : s){ 
            if(val == ' '){
                mpp[temp]++;
                temp = "";
            }
            else{
                temp += val;
            }
        }
        
        if(temp != ""){
            mpp[temp]++;
            temp = "";
        }
        vector<string> ans;
        for(auto& val:mpp){ 

            if(val.second==1){
                ans.emplace_back(val.first); // can use push_back also                
            }

        }

        return ans;
    }
};