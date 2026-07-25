class Solution {
public:
    int m, n;
    vector<pair<int, int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int idx) {
        if (idx == word.size())
            return true;

        if (i < 0 || i >= m || j < 0 || j >= n)
            return false;

        if (board[i][j] != word[idx])
            return false;

        char temp = board[i][j];
        board[i][j] = '#';      // đánh dấu đã dùng

        for (auto [dx, dy] : dir) {
            if (dfs(board, word, i + dx, j + dy, idx + 1))
                return true;
        }

        board[i][j] = temp;     // backtracking
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(board, word, i, j, 0))
                    return true;
            }
        }

        return false;
    }
};