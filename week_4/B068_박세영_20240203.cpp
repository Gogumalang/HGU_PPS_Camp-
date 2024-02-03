class Solution {
public:
    bool isSubsequence(string s, string t) {
        int find_start =0;
        bool find=false;
        for(char c : s) {
            for(int i =find_start ; i<t.size();i++) {
                if(c == t[i]) {
                    find = true;
                    find_start = i+1;
                    break;
                }
            }
            if(find == false) return false;
            find = false;
        }
        return true; 
    }
};