#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int left = left_bound(nums, target);
        int right = right_bound(nums, target);
        return vector<int>({left, right});
    }
    int left_bound(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size();
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] == target)
            {
                right = mid;
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else if (nums[mid] > target)
            {
                right = mid;
            }
        }
        return (left < nums.size() && nums[left] == target) ? left : -1;
    }
    int right_bound(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size();
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] == target)
            {
                left = mid + 1;
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else if (nums[mid] > target)
            {
                right = mid;
            }
        }
        return (left > 0 && nums[left - 1] == target) ? left - 1 : -1;
    }
};
