class Solution {
public:

     unordered_set<string> result;

    void getRemovals(string s, int& leftRemove, int& rightRemove) {
        for (char c : s) {
            if (c == '(') {
                leftRemove++;
            }
            else if (c == ')') {
                if (leftRemove > 0) {
                    leftRemove--;
                }
                else {
                    rightRemove++;
                }
            }
        }
    }

    bool isValid(string s) {
        int balance = 0;

        for (char c : s) {
            if (c == '(') {
                balance++;
            }
            else if (c == ')') {
                balance--;

                if (balance < 0)
                    return false;
            }
        }

        return balance == 0;
    }

    void backtrack(string& s, int start,
                   int leftRemove, int rightRemove) {

        // No more removals required
        if (leftRemove == 0 && rightRemove == 0) {
            if (isValid(s)) {
                result.insert(s);
            }
            return;
        }

        for (int i = start; i < s.size(); i++) {

            // Avoid duplicate states
            if (i > start && s[i] == s[i - 1])
                continue;

            // Remove '('
            if (leftRemove > 0 && s[i] == '(') {

                string temp = s;
                temp.erase(i, 1);

                backtrack(temp, i,
                          leftRemove - 1,
                          rightRemove);
            }

            // Remove ')'
            if (rightRemove > 0 && s[i] == ')') {

                string temp = s;
                temp.erase(i, 1);

                backtrack(temp, i,
                          leftRemove,
                          rightRemove - 1);
            }
        }
    }
    vector<string> removeInvalidParentheses(string s) {

         int leftRemove = 0;
        int rightRemove = 0;

        getRemovals(s, leftRemove, rightRemove);

        backtrack(s, 0, leftRemove, rightRemove);

        return vector<string>(result.begin(), result.end());
        
    }
};