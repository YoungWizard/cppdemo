#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        int heapSize = nums.size();
        for (int i = (heapSize - 1) / 2; i >= 0; i--)
        {
            sink(nums, i, heapSize);
        }
        for (int i = 0; i < k - 1; i++)
        {
            int temp = nums[0];
            nums[0] = nums[heapSize - 1];
            nums[heapSize - 1] = temp;
            heapSize--;
            sink(nums, 0, heapSize);
        }
        return nums[0];
    }
    void sink(vector<int> &nums, int k, int heapSize)
    {
        while (2 * k + 1 <= heapSize - 1)
        {
            int j = 2 * k + 1;
            if ((j + 1 <= heapSize - 1) && (nums[j] < nums[j + 1]))
            {
                j++;
            }

            if (nums[j] <= nums[k])
                break;
            int temp = nums[j];
            nums[j] = nums[k];
            nums[k] = temp;
            k = j;
        }
    }
};

int main()
{
    Solution *sol = new Solution();
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int res = sol->findKthLargest(nums, 2);
    cout << res << endl;
}