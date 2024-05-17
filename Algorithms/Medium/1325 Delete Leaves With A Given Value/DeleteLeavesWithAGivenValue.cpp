#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
right(right) {}
};

// Runtime - 8ms || Memory - 21.24 MB
class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        stack<TreeNode*> stack;
        TreeNode *node = root, *prevNode = nullptr;
        while (!stack.empty() || node != nullptr) {
            while (node != nullptr) {
                stack.push(node);
                node = node->left;
            }
            node = stack.top();
            if (node->right != prevNode && node->right) {
                node = node->right;
                continue;
            }
            stack.pop();
            if (node->right == nullptr && node->left == nullptr &&
                node->val == target) {
                if (stack.empty()) {
                    return nullptr;
                }
                TreeNode* parent = stack.top();
                if (parent->left == node) {
                    parent->left = nullptr;
                } else {
                    parent->right = nullptr;
                }
            }
            prevNode = node;
            node = nullptr;
        }
        return root;
    }
};

int main()
{
    return 0;
}