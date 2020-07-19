#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        int need[128] = {0};
        int window[128] = {0};
        for (auto c : p)
            need[c]++;
        int left = 0, right = 0, valid = 0;
        vector<int> res;
        while (right < s.length())
        {
            char c = s[right];
            right++;
            if (need[c] != 0)
            {
                window[c]++;
            }

            while (right - left >= p.length())
            {
                bool check = true;
                for (int i = 0; i < 128; ++i)
                {
                    if (window[i] < need[i])
                    {
                        check = false;
                        break;
                    }
                }
                if (check)
                {
                    res.push_back(left);
                }
                char d = s[left];
                left++;
                if (need[d] != 0)
                {
                    window[d]--;
                }
            }
        }
        return res;
    }
};

int main()
{
    string s1 = "eidbaooo";
    string s2 = "ab";
   
    return 0;
}