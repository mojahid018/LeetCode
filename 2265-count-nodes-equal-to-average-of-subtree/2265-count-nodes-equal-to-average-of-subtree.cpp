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

     pair<int, int> dfs(TreeNode* root, int& ans) {

        // Base case
        if (root == nullptr) {
            return {0, 0};
        }

        // Left subtree
        pair<int, int> left = dfs(root->left, ans);

        // Right subtree
        pair<int, int> right = dfs(root->right, ans);

        // Calculate sum
        int sum = left.first + right.first + root->val;

        // Calculate number of nodes
        int count = left.second + right.second + 1;

        // Check average
        if (sum / count == root->val) {
            ans++;
        }

        // Return sum and count
        return {sum, count};
    }
    int averageOfSubtree(TreeNode* root) {
        
        int ans = 0;

        dfs(root, ans);

        return ans;

        
    }
};