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
    bool res = false;
    void func(TreeNode* root, int sum, int target){
        if(root == NULL)
            return;

        sum += root->val;

        if(root->left == NULL and root->right == NULL){
            if(sum == target)
                res = true;

            return;
        }

        func(root->left, sum, target);
        func(root->right, sum, target);
        return;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {

        func(root, 0, targetSum);
        return res;
        
    }
};