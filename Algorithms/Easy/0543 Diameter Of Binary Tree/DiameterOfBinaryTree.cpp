#include <bits/stdc++.h>
using namespace std;

// Runtime - 12ms || Memory - 22.20 MB
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {}
};

class Solution
{
public:
    int calcHeight(TreeNode *root, int &diameter)
    {
        if (!root)
            return 0;
        int lh = calcHeight(root->left, diameter);
        int rh = calcHeight(root->right, diameter);
        diameter = max(diameter, lh + rh);
        return 1 + max(lh, rh);
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        int diameter = 0;
        calcHeight(root, diameter);
        return diameter;
    }
};

int main()
{
    return 0;
}