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

    bool func(TreeNode* p, TreeNode* q){
        if(p == NULL and q == NULL)
            return true;

        if(p == NULL or q == NULL)
            return false;

        if(p->val != q->val)
            return false;

        bool r1 = func(p->left,q->right);
        bool r2 = func(p->right,q->left);
        if(r1 == true and r2 == true)
            return true;
        return false;
    }
    
    bool isSymmetric(TreeNode* root) {

        bool ans = func(root->left, root->right);

        return ans;
        
    }
};