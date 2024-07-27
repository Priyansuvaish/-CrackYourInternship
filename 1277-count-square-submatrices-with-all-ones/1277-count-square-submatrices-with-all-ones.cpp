class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        vector<vector<int>>dp(matrix);
        int n=matrix.size();        
        int m=matrix[0].size();
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][j])dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
                else dp[i][j]=0;
            }
        }
        int s=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                s+=dp[i][j];
            }
        }
        return s;
    }
};