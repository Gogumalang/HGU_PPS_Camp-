class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> all_nums(nums.size());
        vector<int> ans;
        for(int i = 0; i< all_nums.size(); i++) {
            all_nums[nums[i]-1] = -1;
            if(all_nums[i] != -1) all_nums[i] = i+1;
        }

        for(auto num : all_nums) {
            if(num!= -1) ans.push_back(num);
        }
        return ans;
    }
};