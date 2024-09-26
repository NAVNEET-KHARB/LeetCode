class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (words.empty() || s.empty())
            return result;
        int word_len = words[0].length();
        int num_words = words.size();
        int total_len = word_len * num_words;
        if (s.length() < total_len)
            return result;
        unordered_map<string, int> word_count;
        for (const string& word : words) {
            word_count[word]++;
        }
        for (int i = 0; i < word_len; i++) {
            int left = i;
            int count = 0;
            unordered_map<string, int> seen;
            for (int j = i; j <= s.length() - word_len; j += word_len) {
                string word = s.substr(j, word_len);
                if (word_count.find(word) != word_count.end()) {
                    seen[word]++;
                    count++;
                    while (seen[word] > word_count[word]) {
                        string left_word = s.substr(left, word_len);
                        seen[left_word]--;
                        count--;
                        left += word_len;
                    }
                    if (count == num_words) {
                        result.push_back(left);
                        string left_word = s.substr(left, word_len);
                        seen[left_word]--;
                        count--;
                        left += word_len;
                    }
                } else {
                    seen.clear();
                    count = 0;
                    left = j + word_len;
                }
            }
        }

        return result;
    }
};