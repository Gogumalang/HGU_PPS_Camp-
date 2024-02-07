class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> sum(2);

        for(int i =0;i<nums.size();i++){
            sum[0] = i;
            for(int j = i+1;j<nums.size();j++) {
                if(target == nums[i] + nums[j]) {
                    sum[1] = j;
                    return sum;
                }
            }
        }
        return sum;
    }
};