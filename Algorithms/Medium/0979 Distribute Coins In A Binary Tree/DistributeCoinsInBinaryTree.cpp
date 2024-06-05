#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Runtime - 4ms || Memory - 15.63 MB
class Solution
{
public:
    int distributeCoins(TreeNode *root, TreeNode *parent = NULL)
    {
        if (!root)
            return 0;
        int moves = distributeCoins(root->left, root) + distributeCoins(root->right, root);
        int x = root->val - 1;
        if (parent)
            parent->val += x;
        moves += abs(x);
        return moves;
    }
};

int main()
{
    return 0;
}