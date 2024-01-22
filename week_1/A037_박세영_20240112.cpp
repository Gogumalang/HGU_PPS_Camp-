class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> sdn ;
        int q, r;
        for(int num=left;num<=right;num++) {
            q= num;
            sdn.push_back(num);
            do {
                r=q%10; 
                q=q/10;
                if(r==0||num%r !=0) {
                    sdn.pop_back();
                    break;
                }
            }while(q!=0);
        }
        return sdn;
        
    }
};