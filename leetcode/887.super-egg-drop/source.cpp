#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int superEggDrop(int K, int N)
    {
        vector<vector<int>> dp(K+1, vector<int>(N+1, N + 1));
        for (int i = 0; i <= K; ++i)
            dp[i][0] = 0;
        for (int j = 0; j <= N; ++j)
            dp[0][j] = 0;
        for (int j = 0; j <= N; ++j)
            dp[1][j] = j;
        for (int i = 2; i <=K; i++)
        {
            for (int j = 1; j <= N; ++j)
            {
                
                int lo=1,hi=j;
                while (lo<=hi)
                {
                    int mid = (lo + hi)/2;
                    int broken=dp[i-1][mid-1];
                    int not_broken=dp[i][j-mid];
                    if(broken>not_broken)
                    {
                        hi=mid-1;
                        dp[i][j]=min(dp[i][j],broken+1);
                    }
                    else
                    {
                        lo=mid+1;
                        dp[i][j]=min(dp[i][j],not_broken+1);
                    }
                    
                }
                
            }
        }
        return dp[K][N];
    }
};