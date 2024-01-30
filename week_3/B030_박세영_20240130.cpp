class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int sum =0;  
        int min_index = nums.size()-1;
        for(int j =0;j<k;j++) {
            int i = j % nums.size();
            if(nums[i]<0) {
                nums[i] *= -1;
                if(nums[min_index] > nums[i]) min_index = i;
            }
            else {
                if(nums[min_index] > nums[i]) min_index = i;
                if((k-j)%2 == 0) break; 
                else {
                    nums[min_index] *= -1;
                    break; 
                }
                
            }   
        }

        for(int i =0; i<nums.size();i++) {
            sum += nums[i];
        }


        return sum;

        
    }
};