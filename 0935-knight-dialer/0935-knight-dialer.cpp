class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<vector<int>> dp;
    vector<vector<int>> moves = {
        {4, 6}, {6, 8}, {7, 9}, {4, 8}, {0, 3, 9},
        {}, {0, 1, 7}, {2, 6}, {1, 3}, {2, 4}
    };

    int solve(int n, int i) {
        if (n == 0) return 1;
        if (dp[n][i] != -1) return dp[n][i];

        int res = 0;
        for (int next : moves[i]) {
            res = (res + solve(n - 1, next)) % MOD;
        }
        return dp[n][i] = res;
    }

    int knightDialer(int n) {
        dp.resize(n + 1, vector<int>(10, -1));
        int result = 0;
        for (int i = 0; i <= 9; ++i) {
            result = (result + solve(n - 1, i)) % MOD;
        }
        return result;
    }
};
