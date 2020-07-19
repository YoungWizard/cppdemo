#include <iostream>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    string minWindow(string s, string t)
    {
        unordered_map<char, int> needs, window;
        for (auto c : t)
            needs[c]++;
        int left = 0, right = 0;
        int valid = 0;
        int start = 0, len = INT_MAX;
        while (right < s.length())
        {
            /* code */
            char c = s[right];
            right++;
            if (needs.count(c))
            {
                window[c]++;
                if (window[c] == needs[c])
                    valid++;
            }
            while (valid == needs.size())
            {
                if(right-left<len)
                {
                    start=left;
                    len=right-left;
                }
                char d = s[left];
                left++;
                if (needs.count(d))
                {
                    if (window[d] == needs[d])
                        valid--;
                    window[d]--;
                }
            }
        }
        return len == INT_MAX ? "" : s.substr(start, len);
    }
};
int main()
{
    return 0;
}