#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n=nums.size();
        if(n==1)return nums[0];
        return max(dp(nums,0,n-1),dp(nums,1,n));
    }
    int dp(vector<int>& nums,int start,int end)
    {
        vector<int>dp(end+2,0);
        for(int i=end-1;i>=start;--i)
        {
            dp[i]=max(dp[i+1],dp[i+2]+nums[i]);
        }
        return dp[start];
    }
};