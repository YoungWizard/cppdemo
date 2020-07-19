#include <iostream>
#include <vector>
#include <stack>
#include <map>
using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        vector<int> ans(n);
        stack<int> s;
        map<int, int> m;
        for (int i = nums2.size() - 1; i >= 0; i--)
        {

            while (!s.empty() && s.top() <= nums2[i])
            {
                s.pop();
            }
            int num = s.empty() ? -1 : s.top();
            m[nums2[i]]=num;
            s.push(nums2[i]);
        }
        for (int i = 0; i < n; i++)
        {
            ans[i]=m[nums1[i]];
        }
        
        return ans;
    }
};