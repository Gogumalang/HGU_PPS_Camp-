class Solution {
public:
    bool isHappy(int n) {
        vector<int> num; 
        int loop=0;
        while(1) {
            num.push_back(n);
            int sum = 0;
            while(n>0) {
                sum += pow(n%10,2);
                n /= 10;
            }
            if(sum == 1) return true;
            else {
                n = sum;
                for(auto l : num) {
                    if(l == n)
                    {
                        loop =1; 
                        break;
                    } 
                }
                if(loop ==1) break;
            }
        }
        return false; 
    }
};