#include <iostream>
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
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root == nullptr)
            return nullptr;
        if (root->val == key)
        {
            if (root->left == nullptr)
                return root->right;
            if (root->right == nullptr)
                return root->left;
            TreeNode *min = getMin(root->right);
            root->val=min->val;
            root->right=deleteNode(root->right,min->val);
        }
        else if (root->val > key)
        {
            root->left = deleteNode(root->left, key);
        }
        else if (root->val < key)
        {
            root->right = deleteNode(root->right, key);
        }
        return root;
    }
    TreeNode *getMin(TreeNode *node)
    {
        // BST 最左边的就是最小的
        while (node->left != nullptr)
            node = node->left;
        return node;
    }
};