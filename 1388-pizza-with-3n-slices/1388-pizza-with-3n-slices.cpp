class Solution {
public:
    int solve(vector<int>& a, int k) {
        int m = a.size();

        vector<vector<int>> dp(m + 1, vector<int>(k + 1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= k; j++) {

                dp[i][j] = dp[i - 1][j];

                int take = a[i - 1];

                if (i >= 2)
                    take += dp[i - 2][j - 1];

                if (i == 1 && j > 1)
                    take = 0;

                dp[i][j] = max(dp[i][j], take);
            }
        }

        return dp[m][k];
    }

    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size() / 3;

        vector<int> a(slices.begin(), slices.end() - 1);

        vector<int> b(slices.begin() + 1, slices.end());

        return max(solve(a, n), solve(b, n));
    }
};