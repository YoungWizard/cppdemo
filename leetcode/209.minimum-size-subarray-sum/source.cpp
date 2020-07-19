#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int minSubArrayLen(int s, vector<int> &nums)
    {
        int n = nums.size();
        int left = 0, right = 0;
        int sum=0;
        int res=INT_MAX;
        while (right < n)
        {
            int num=nums[right];
            right++;
            sum+=num;
            while (sum>=s)
            {
                res=min(res,right-left);
                int num2=nums[left];
                left++;
                sum-=num2;
            }         
        }
        return res==INT_MAX?0:res;
    }
};