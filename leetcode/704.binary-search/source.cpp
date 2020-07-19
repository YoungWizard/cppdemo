#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size();
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] == target)
            {
                return mid;
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
};
int main()
{
    vector<int> vec({1, 3, 5, 8, 10, 13});
    Solution *sol = new Solution();
    cout << sol->search(vec, 0) << endl;
    cout << sol->search(vec, 5) << endl;
    cout << sol->search(vec, 19) << endl;
    return 0;
}