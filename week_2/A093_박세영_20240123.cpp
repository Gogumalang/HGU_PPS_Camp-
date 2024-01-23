class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ans(m+n);
        int i =0;
        int j=0;
        int z=0;
        while(1) {
            if(i>=m) {
                for(int z=j;z<n;z++ ) {
                    ans[z+m] = nums2[z];
                }
                break;
            }
            else if(j>=n) {
                for(int z=i;z<m;z++ ) {
                    ans[z+n] = nums1[z];
                }
                break;
            }
            if(nums1[i]<=nums2[j]) {
                ans[z] = nums1[i];
                z++;
                i++;
            }
            else {
                ans[z] = nums2[j];
                z++;
                j++;
            }
        }
        nums1 = ans;
    }
};