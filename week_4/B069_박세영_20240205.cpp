class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max = INT_MIN;

        for(int i =1;i<nums.size();i++) {
           nums[i] = nums[i]> nums[i]+nums[i-1] ? nums[i]:nums[i]+nums[i-1];
        }
        for(int i =0;i<nums.size();i++) {
            if(max<nums[i]) max = nums[i];
        }
        return max;
    }
};