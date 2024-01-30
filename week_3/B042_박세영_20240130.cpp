class Solution {
public:
    int balancedStringSplit(string s) {
        int count = 0;
        int L_count =0;
        int R_count =0;
        for(int i =0;i<s.length();i++) {
            if(s[i] == 'R') R_count ++;
            else if (s[i] == 'L') L_count ++;
            if(R_count == L_count) {
                count ++;       
            }
        }
        return count ;
    }
};