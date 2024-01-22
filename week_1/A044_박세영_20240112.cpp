class Solution {
public:
    bool checkRecord(string s) {
        int absent_count =0;
        int late_count = 0;

        for(int i =0;i<s.length();i++){
            if(s[i] == 'A') absent_count++;
            if(s[i] == 'L') late_count++;
            else late_count =0;
            if(absent_count>=2) return false;
            if(late_count>=3) return false;
        }
        return true;
    }
};