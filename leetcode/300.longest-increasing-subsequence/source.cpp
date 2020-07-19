#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> dp(nums.size(), 1);
        for (size_t i = 0; i < dp.size(); i++)
        {
            for (size_t j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        int res = 0;
        for (int i = 0; i < dp.size(); i++)
        {
            res = max(res, dp[i]);
        }
        return res;
    }
};