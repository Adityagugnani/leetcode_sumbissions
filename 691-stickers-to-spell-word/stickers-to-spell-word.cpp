class Solution {
public:
    int minStickers(vector<string>& stickers, string& target) {
        int n = size(stickers);

        unordered_set<string> visited;

        // Reorganize stickers argument in frequencies
        vector<vector<int>> s_frequencies(n, vector<int>(26, 0));
        for (int i = 0; i < n; ++i)
            for (auto& c : stickers[i])
                ++s_frequencies[i][c - 'a'];
        
        // Reorganize target argument in frequency
        vector<int> t_frequency(26, 0);
        for (auto& c : target)
            ++t_frequency[c - 'a'];

        queue<vector<int>> q;
        q.push(t_frequency);

        for (int res = 0; size(q); ++res) {
            for (int k = size(q); k > 0; --k) {
                auto t_freq = q.front(); q.pop();

                // Reconstruct string based on frequency
                string t_str;
                for (int i = 0; i < 26; ++i)
                    if (t_freq[i] > 0)
                        t_str += string(t_freq[i], i);

                if (t_str == "") return res;

                if (visited.count(t_str)) continue;
                visited.insert(t_str);

                char seeking = t_str[0];
                for (auto& v : s_frequencies) {
                    // Optimize by checking for first letter
                    if (v[seeking] > 0) {
                        q.push(t_freq); // Push first to copy t_freq
                        for (int i = 0; i < 26; ++i)
                            q.back()[i] -= v[i];
                    }
                }
            }
        }

        return -1;
    }
};