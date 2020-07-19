#include <iostream>
#include<cmath>
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
    int countNodes(TreeNode *root)
    {
        TreeNode *l = root;
        TreeNode *r = root;
        int lh = 0, rh = 0;
        while (l != nullptr)
        {
            l = l->left;
            lh++;
        }
        while (r != nullptr)
        {
            r = r->right;
            rh++;
        }
        if(lh==rh)
        return (int)(pow(2,rh))-1;

        return 1+countNodes(root->left)+countNodes(root->right);
    }
};