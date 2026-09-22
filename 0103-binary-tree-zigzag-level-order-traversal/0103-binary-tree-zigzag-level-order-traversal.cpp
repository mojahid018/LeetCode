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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

         vector<vector<int>> ans;

        if (root == NULL)
            return ans;

        queue<TreeNode*> q;
        q.push(root);

        bool leftToRight = true;

        while (!q.empty()) {

            int levSize = q.size();

            vector<int> temp(levSize);

            for (int i = 0; i < levSize; i++) {

                TreeNode* t = q.front();
                q.pop();

                int index;

                if (leftToRight)
                    index = i;
                else
                    index = levSize - 1 - i;

                temp[index] = t->val;

                if (t->left != NULL)
                    q.push(t->left);

                if (t->right != NULL)
                    q.push(t->right);
            }

            ans.push_back(temp);

            leftToRight = !leftToRight;
        }

        return ans;
        
    }
};