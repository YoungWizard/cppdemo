#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int>dp(nums.size());
        dp[0]=nums[0];
        for (size_t i = 1; i < dp.size(); i++)
        {
            dp[i]=max(nums[i],nums[i]+dp[i-1]);
        }
        
        int res=INT_MIN;
        for (auto n:dp)
        {
            res=max(res,n);
        }
        return res;
    }
};