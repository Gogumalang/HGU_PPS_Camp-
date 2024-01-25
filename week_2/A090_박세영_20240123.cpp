class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int duple = nums[0];
        int k = 1;
        for(int i =0;i<nums.size();i++) {
            if(duple != nums[i]) {
                duple = nums[i];
                nums[k] = duple;
                k++;
            }
        }
        return k;
    }
};
