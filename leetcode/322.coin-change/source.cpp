#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++)
        {
            for (int coin : coins)
            {
                if (coin <= i)
                {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};
int main()
{
    Solution *sol = new Solution();
    vector<int> vec({1, 2, 5});
    int res = sol->coinChange(vec, 11);
    cout << res << endl;
    return 0;
}