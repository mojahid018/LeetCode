class Solution {
public:

    void func(int open, int close, int n,
              string temp, vector<string>& ans) {

        // Base Case
        if (open == n && close == n) {
            ans.push_back(temp);
            return;
        }

        // Add opening bracket
        if (open < n) {
            temp.push_back('(');

            func(open + 1, close, n, temp, ans);

            temp.pop_back();
        }

        // Add closing bracket
        if (close < open) {
            temp.push_back(')');

            func(open, close + 1, n, temp, ans);

            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {

        vector<string> ans;
        string temp = "";

        func(0, 0, n, temp, ans);

        return ans;
        
    }
};