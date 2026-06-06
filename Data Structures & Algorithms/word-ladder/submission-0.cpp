class Solution {
public:
    bool visitable(string word1, string word2)
    {
        int diff = 0;
        for (int i = 0; i<word1.size(); i++) {
            if (word1[i] != word2[i]) { diff++; }
        }
        if (diff > 1) { return false; }
        return true;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);

        vector<bool> visited(wordList.size(), false);
        vector<int> levels(wordList.size(), 0);
        
        queue<int> q;
        q.push(wordList.size()-1);
        visited[wordList.size()-1] = true;
        levels[wordList.size()-1] = 1;
        while (!q.empty()) {
            int front_idx = q.front();
            q.pop();
            string cword = wordList[front_idx];
            for (int i = 0; i<wordList.size(); i++) {
                if (!visited[i] && visitable(wordList[i], cword)) {
                    q.push(i);
                    visited[i] = true;
                    levels[i] = levels[front_idx]+1;
                }
            }
        }
        for (int i = 0; i<wordList.size(); i++) {
            if (wordList[i] == endWord) { return levels[i]; }
        }
        return 0;
    }
};
