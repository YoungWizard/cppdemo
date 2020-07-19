#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.length();
        string ans;
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for (int i = n-1; i>=0; i--)
        {
            for (int j = i; j < n; j++)
            {
                if(j-i==0)
                dp[i][j]=true;
                if(j-i==1)
                dp[i][j] = (s[i]==s[j]);
                if(j-i>=2)
                dp[i][j]=(s[i]==s[j]&&dp[i+1][j-1]);
                
                if(dp[i][j]&&j-i+1>ans.length())
                ans=s.substr(i,j-i+1);                             
            }
        }        
        
        return ans;
    }
};
int main()
{
    Solution* sol=new Solution();
    string s="babad";
    string res=sol->longestPalindrome(s);
    cout<<res<<endl;
    return 0;
}