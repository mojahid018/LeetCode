class Solution {
public:
    struct Cmp {
        bool operator()(pair<int, string>& a, pair<int, string>& b) {

            if (a.first != b.first)
                return a.first > b.first;

            return a.second < b.second;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {

        vector<string> res;

        unordered_map<string, int> f;

        for (int i = 0; i < words.size(); i++)
            f[words[i]]++;

        priority_queue<
            pair<int, string>,
            vector<pair<int, string>>,
            Cmp
        > pq;

        for (auto i : f) {

            int freq = i.second;
            string word = i.first;

            pair<int, string> curr = {freq, word};

            if (pq.size() < k) {
                pq.push(curr);
                continue;
            }

            // Current word is worse
            if (curr.first < pq.top().first)
                continue;

            if (curr.first == pq.top().first &&
                curr.second > pq.top().second)
                continue;

            // Current word is better
            pq.pop();
            pq.push(curr);
        }

        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        reverse(res.begin(), res.end());

        return res;
        
    }
};