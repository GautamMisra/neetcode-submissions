/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int count = 0;
    void dfs(TreeNode* node, int maxSoFar) {
        if (node == nullptr)
            return;
        if (node->val >= maxSoFar)
            count++;
        maxSoFar = max(maxSoFar, node->val);
        dfs(node->left, maxSoFar);
        dfs(node->right, maxSoFar);
    }
    int goodNodes(TreeNode* root) {
        if (root == nullptr)
            return 0;
        dfs(root, root->val);
        return count;
    }
};
