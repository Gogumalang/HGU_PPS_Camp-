class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string commonP = strs[0];
        int length = commonP.length();
        for(int i =1; i<strs.size();i++) {
            for(int j =0;j<length;j++) {
                if(commonP[j] != strs[i][j]) {
                    length = j;
                    break;
                }
            }
            if(length == 0) return "";
        }
        
        return commonP.substr(0,length);
    }
};