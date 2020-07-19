#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> res;
        vector<int> track;
        backtrack(nums, track, res);
        return res;
    }
    void backtrack(vector<int> &nums, vector<int> &track, vector<vector<int>> &res)
    {
        if (track.size() == nums.size())
        {
            res.push_back(track);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (find(track.begin(), track.end(), nums[i]) != track.end())
                continue;
            track.push_back(nums[i]);
            backtrack(nums,track,res);
            track.pop_back();
        }
    }
};

int main()
{
    vector<int> nums({1, 3, 4});
    Solution *sol = new Solution();
    vector<vector<int>> res = sol->permute(nums);

    for (auto vec : res)
    {
        for (auto a : vec)
        {
            cout << a << "  " << endl;
        }
        cout << endl;
    }
    return 0;
}