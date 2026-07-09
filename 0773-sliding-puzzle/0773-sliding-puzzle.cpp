class Solution {
public:
    inline static unordered_map<string, int> moves;
    inline static string states[360];
    inline static vector<vector<int>> adj = 
        { {1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4} };

    inline static bool init = []() {
        moves["123450"] = 0;
        states[0] = "123450";
        size_t n = 1;

        for (size_t i = 0; i < n; i++) {
            string s = states[i];
            size_t z = s.find('0');

            for (int a : adj[z]) {
                string S = s;
                swap(S[z], S[a]);

                if (!moves.count(S)) {
                    moves[S] = moves[s] + 1;
                    states[n++] = S;
                }
            }
        }
        return 0;
    }();

    int slidingPuzzle(vector<vector<int>>& board) {
        string s = "";
        for (auto& r : board)
            for (auto& c : r)
                s += to_string(c);

        return moves.count(s) ? moves[s] : -1;
    }
};