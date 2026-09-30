class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {

        vector<int> ans;
        int depth = 0;

        for (char c : seq) {
            if (c == '(') {
                depth++;

                // Odd depth -> B, Even depth -> A
                ans.push_back(depth % 2);
            } 
            else {
                // Closing bracket belongs to the same group
                ans.push_back(depth % 2);

                depth--;
            }
        }

        return ans;
        
    }
};