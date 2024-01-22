class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums1.size(),-1); 
        for(int i =0;i< nums1.size();i++) {
            for(int j=0;j<nums2.size();j++) {
                if(nums1[i] == nums2[j]) {
                    for(int z=j+1;z<nums2.size();z++) {
                        if(nums2[j]< nums2[z]) {
                            ans[i] = nums2[z];
                            break;
                        }
                    }
                    break;
                }
            }
        }
        return ans;
    }
};