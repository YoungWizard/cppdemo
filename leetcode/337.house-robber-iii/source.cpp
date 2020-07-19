#include <iostream>
#include <unordered_map>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    unordered_map<TreeNode *, int> memo;
    int rob(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        if(memo.count(root))
        return memo[root];
        int do_it=root->val+
        (root->left==nullptr?0:rob(root->left->left)+rob(root->left->right))+
        (root->right==nullptr?0:rob(root->right->left)+rob(root->right->right));
        int not_do=rob(root->left)+rob(root->right);
        int ans= max(do_it,not_do);
        memo[root]=ans;
        return ans;
    }
};