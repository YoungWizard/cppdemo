#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int n = obstacleGrid.size();
        if (n == 0)
            return 0;
        int m = obstacleGrid[0].size();
        if (m == 0)
            return 0;
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for(int i=0;i<n;++i)
        {
            if(obstacleGrid[i][0]==1)
            break;
            dp[i][0]=1;
        }
        for(int j=0;j<m;++j)
        {
            if(obstacleGrid[0][j]==1)
            break;
            dp[0][j]=1;
        }
        for(int i=1;i<n;++i)
        {
            for (int j = 1; j < m; j++)
            {
                if(obstacleGrid[i][j]!=1)
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
            
        }
        return dp[n-1][m-1];
    }
};