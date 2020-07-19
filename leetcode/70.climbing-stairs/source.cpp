#include <iostream>
using namespace std;
class Solution
{
public:
    int climbStairs(int n)
    {
        int p = 0, q = 0, r = 1;
        for (int i = 1; i <= n; i++)
        {
            p = q;
            q = r;
            r = p + q;
        }
        return r;
    }
};
int main()
{
    Solution *sol = new Solution();

    cout << sol->climbStairs(1) << endl;
    cout << sol->climbStairs(2) << endl;
    cout << sol->climbStairs(3) << endl;
    cout << sol->climbStairs(4) << endl;
    cout << sol->climbStairs(5) << endl;
    return 0;
}