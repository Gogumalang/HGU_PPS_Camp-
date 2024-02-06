class Solution {
public:
    int max_b(int a, int b) {
            if(a>b) return a;
            return b;
    }
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 1) return 0;

        vector<int> dif(prices.size()-1,0);
        for(int i =0;i<dif.size();i++) {
            dif[i] = prices[i+1] - prices[i];
        }
        int max = dif[0];
        
        for(int i = 1;i<dif.size();i++){
            dif[i] = max_b(dif[i],dif[i]+dif[i-1]);
            if(dif[i]>max) max = dif[i];
        }
        if(max <0) return 0;
        return max; 
    }

    
};