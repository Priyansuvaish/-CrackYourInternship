class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,1e9));
        for(int i=1;i<n+1;i++){
            dp[i][0]=0;
            for(int j=1;j<amount+1;j++){
                int taken=1e9;
                if(coins[i-1]<=j)taken=1+dp[i][j-coins[i-1]];
                dp[i][j]=min(taken,dp[i-1][j]);
            }
        }
        if(dp[n][amount]==1e9)return -1;
        return dp[n][amount];
    }
};