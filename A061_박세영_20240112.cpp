class Solution {
public:
    string convertToTitle(int columnNumber) {
        stack<int> title; 
        string ans=""; 
        int q=columnNumber;
        int r; 
        while(1) {
            q--;
            r = q%26;
            q /=26;
            title.push(r);
            if(q <=0) break;

        }
        do{
            int number = title.top();
            ans.push_back(number+'A');
            title.pop();
        }while(!title.empty());
        return ans;
    }
};