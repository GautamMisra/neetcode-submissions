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
    vector<int> trav;
    int count=0;
    void inorder(TreeNode* node){
        if(node==nullptr)
            return;
        inorder(node->left);
        trav.push_back(node->val);
        inorder(node->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        inorder(root);
        int size=trav.size();
        int ans;
        for(int i=0;i<size;i++){
            count++;
            if(count==k)
                ans=trav[i];
            else
                continue;
        }
        return ans;
    }
};
