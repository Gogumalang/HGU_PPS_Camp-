// class Solution {
// public:
//     int maxSubarraySumCircular(vector<int>& nums) {
//         int max = nums[0];
//         int n = nums.size();
//         for(int i=0;i<n;i++) {
//             int sum = nums[i];
//             if(sum >max) max = sum;
//             for(int j=1;j<n;j++) {
//                 sum += nums[(j+i)%n];
//                 if(sum >max) max = sum;
//             }
//         }
//         return max;
//     }
// };

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        const int n = nums.size();
        vector<int> rightMax(n);
        rightMax[n - 1] = nums[n - 1];
        int suffixSum = nums[n - 1];

        for (int i = n - 2; i >= 0; --i) {
            suffixSum += nums[i];
            rightMax[i] = max(rightMax[i + 1], suffixSum);
        }

        int maxSum = nums[0];
        int specialSum = nums[0];
        int curMax = 0;
        int prefixSum = 0;
        for (int i = 0; i < n; ++i) {
            // This is Kadane's algorithm.
            curMax = max(curMax, 0) + nums[i];
            maxSum = max(maxSum, curMax);

            prefixSum += nums[i];
            if (i + 1 < n) {
                specialSum = max(specialSum, prefixSum + rightMax[i + 1]);
            }
        }

        return max(maxSum, specialSum);
    }
};

// class Solution {
// public:
//     int maxSubarraySumCircular(vector<int>& A) {
//         int total_sum=0,curr_sum1=0,curr_sum2=0,mxsum_subary=INT_MIN,minsum_subary=INT_MAX;   
//         for(auto i:A)
//         {
//             total_sum+=i; curr_sum1+=i; curr_sum2+=i;
//             mxsum_subary=max(mxsum_subary,curr_sum1);
//             if(curr_sum1<0) curr_sum1=0;
//            minsum_subary=min(curr_sum2,minsum_subary);
//             if(curr_sum2>0) curr_sum2=0;
//         }
//         return (total_sum==minsum_subary)?mxsum_subary:max(mxsum_subary,total_sum-minsum_subary);  
//     }
// };