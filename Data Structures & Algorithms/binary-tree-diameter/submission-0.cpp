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
    int diameter = 0;
    int height(TreeNode* root) {
        if(root==nullptr)
            return 0;
        int leftCount = height(root->left);
        int rightCount = height(root->right);
        diameter = max(diameter, leftCount + rightCount);
        return 1+max(leftCount,rightCount);
    }
    int diameterOfBinaryTree(TreeNode* root){
        height(root);
        return diameter;
    }
};
