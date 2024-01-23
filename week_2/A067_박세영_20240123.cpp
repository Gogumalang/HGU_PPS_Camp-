void swap(char &a,char &b) {
    char temp = a;
    a= b;
    b = temp;
}
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> rest; 
        string ans="";
        int i=0;
        int flag=0;

        while(i<s.length()) {
            if(s[i] != s[i+1]) {
                if(!rest.empty()) {
                    if(rest.top() == s[i]) rest.pop();
                    else rest.push(s[i]);
                }
                else rest.push(s[i]);
            }
            else {
                i++;
            }
            i++;
        }

        while(!rest.empty()){
            ans += rest.top();      
            rest.pop();  
        }

        for(int i =0;i<(ans.length())/2;i++) {
            swap(ans[i],ans[(ans.length()-1)-i]);
        }
        return ans;

    }
};

// Iteration Method 
// 문자열 현재 인덱스와 다음 인덱스의 문자들을 비교한다. 
// 같지 않으면 새로운 문자열에 넣는다. 
// 만약 중복이 일어났으면 flag 1 을 한다. 
// 만약 일어나지 않았으면 return 한다. 
// 새 문자열에 s를 다시 넣는다. 


// Stack Method 
// 다음 문자열과 중복되지 않는다면 
//     스택에 넣는다. 
//     스택의 top과 일치하지 않는다면 , push 하고 
//     일치하면 pop한다. 
// 중복되면 다음 문자열로 옮긴다. 

