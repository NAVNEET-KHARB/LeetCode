#include <bits/stdc++.h>
using namespace std;

// Runtime - 10ms || Memory - 26.21 MB
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int sumPath(TreeNode *root, int &path)
    {
        if (!root)
            return 0;
        int lh = max(0, sumPath(root->left, path));
        int rh = max(0, sumPath(root->right, path));
        path = max(path, root->val + lh + rh);
        return root->val + max(lh, rh);
    }
    int maxPathSum(TreeNode *root)
    {
        int path = INT_MIN;
        sumPath(root, path);
        return path;
    }
};

int main()
{
    return 0;
}