class Solution {
public:
    int findLength(vector<int>& n1, vector<int>& n2) {
        int n=n1.size();
        int m=n2.size();
        int ma=0;
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(n1[i-1]==n2[j-1])dp[i][j]=1+dp[i-1][j-1];
                ma=max(ma,dp[i][j]);
            }
        }
        return ma;
    }
};