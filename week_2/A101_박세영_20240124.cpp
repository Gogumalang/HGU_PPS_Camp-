class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        sort(aliceSizes.begin(),aliceSizes.end());
        sort(bobSizes.begin(),bobSizes.end());

        int alice_sum = 0;
        int bob_sum = 0;

        for(int i =0;i<aliceSizes.size();i++) {
            alice_sum += aliceSizes[i];
        }
        for(int i =0;i<bobSizes.size();i++) {
            bob_sum += bobSizes[i];
        }
        vector<int> ans(2);
        if(alice_sum < bob_sum) {
            for(int i =0;i<aliceSizes.size();i++) {
                for(int j=bobSizes.size()-1;j>=0;j--) {
                    int x = alice_sum -aliceSizes[i] + bobSizes[j];
                    int y =  bob_sum + aliceSizes[i] - bobSizes[j];
                    if(x == y ) {
                        ans[0] = aliceSizes[i];
                        ans[1] = bobSizes[j];
                        return ans;
                    }
                    else if(x < y) break;
                }
            }
        }
        else {
            for(int i =0;i<bobSizes.size();i++) {
                for(int j=aliceSizes.size()-1;j>=0;j--) {
                    int x = bob_sum -bobSizes[i] + aliceSizes[j];
                    int y =  alice_sum + bobSizes[i] - aliceSizes[j];
                    if(x == y ) {
                        ans[0] = aliceSizes[j];
                        ans[1] = bobSizes[i];
                        return ans;
                    }
                    else if(x < y) break;
                }
            }

        }

        return ans;
    }
};