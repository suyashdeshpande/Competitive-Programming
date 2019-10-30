/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    int sumH(TreeNode* root, int sum) {
        if(!root)
            return 0;
        int sumTillNow = sum * 10 + root->val;
        if(!root->left && !root->right)
            return sumTillNow;
        return sumH(root->left, sumTillNow) + sumH(root->right, sumTillNow);
    }
    
    int sumNumbers(TreeNode* root) {
        return sumH(root, 0);
    }
};
