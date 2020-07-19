#include <iostream>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        int need[128] = {0};
        int window[128] = {0};
        for (auto c : s2)
            need[c]++;
        int left = 0, right = 0, valid = 0;
        while (right < s1.length())
        {
            char c = s1[right];
            right++;
            if (need[c] != 0)
            {
                window[c]++;
            }

            while (right - left >= s2.length())
            {
                int check = true;
                for (int i = 0; i < 128; ++i)
                {
                    if (window[i] < need[i])
                    {
                        check = false;
                        break;
                    }
                }
                if (check)
                    return check;
                char d = s1[left];
                left++;
                if (need[d] != 0)
                {
                    window[d]--;
                }
            }
        }
        return false;
    }
};

int main()
{
    string s1 = "eidbaooo";
    string s2 = "ab";
    Solution *sol = new Solution();
    cout << sol->checkInclusion(s1, s2) << endl;
    return 0;
}