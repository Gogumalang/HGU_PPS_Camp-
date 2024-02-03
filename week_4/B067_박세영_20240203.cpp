class Solution {
public:
    string reverseWords(string s) {
        stack<char> reverse;
        string ans;
        for(char c : s) {
            if(c!= ' ') reverse.push(c);
            else {
                while(!reverse.empty()){
                    ans.push_back(reverse.top());
                    reverse.pop();
                }
                ans += ' ';
            }
        }
        while(!reverse.empty()){
            ans.push_back(reverse.top());
            reverse.pop();
        }
        return ans;
    }
};