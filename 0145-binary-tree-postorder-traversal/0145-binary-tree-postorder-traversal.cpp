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

    void postorder(TreeNode* root, vector<int>& ans) {

        // Base Case
        if (root == NULL) {
            return;
        }

        // Step 1: Traverse Left
        postorder(root->left, ans);

        // Step 2: Traverse Right
        postorder(root->right, ans);

        // Step 3: Store Root
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {

        vector<int> ans;

        postorder(root, ans);

        return ans;
        
    }
};