class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int even_index = 0;
        int odd_index = 1;
        vector<int> ans(nums.size());
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2 == 0) {
                ans[even_index] = nums[i];
                even_index +=2;
            }
            else {
                ans[odd_index] = nums[i];
                odd_index +=2;
            }
        }

        return ans;

    }
};