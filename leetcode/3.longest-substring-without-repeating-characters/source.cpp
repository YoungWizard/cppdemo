#include<iostream>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int window[128]={0};
        int left=0,right=0;
        int res=0;
        while (right<s.length())
        {
            char c=s[right];
            right++;
            window[c]++;
            while (window[c]>1)
            {
                char d=s[left];
                left++;
                window[d]--;
            }
            res=max(res,right-left);
        }
        return res;
    }
};

int main()
{
    return 0;
}