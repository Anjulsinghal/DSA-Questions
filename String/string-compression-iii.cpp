// Leetcode 3163 string comparison 3
// https://leetcode.com/problems/string-compression-iii/

class Solution {
public:
    string compressedString(string w) {
        string comp="";
        map<char,int>m;
        for(int i=0;i<w.size();i++){
            if(m[w[i]]==9){
               //w[i] is char
                
                comp += '9';
                comp += w[i];
                m.erase(w[i]);
            }
            m[w[i]]++;
            if(i<w.size() && w[i]!=w[i+1]){
                comp += '0'+m[w[i]];
                comp += w[i];
                m.erase(w[i]);
            }
        }
        
        return comp;
    }
};