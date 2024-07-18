class Solution {
public:
    map<string,pair<int,int>>mp;
    int ans=0;
    void subset(vector<string>& strs,int i,int m,int n,int c){
        if(m<0||n<0)return;
        if(m==0 && n==0||i>=strs.size()){
            ans=max(ans,c);
            return;
        }
        int newm = mp[strs[i]].first;
        int newn = mp[strs[i]].second;
        
        if(m>=newm&&n>=newn)subset(strs,i+1,m-newm,n-newn,c+1);
        subset(strs,i+1,m,n,c);

    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        // Loop through each string in strs
        for (const string& str : strs) {
            int count0 = count(str.begin(), str.end(), '0');
            int count1 = str.size() - count0;
            
            // Update the DP array from bottom to top and right to left
            for (int i = m; i >= count0; --i) {
                for (int j = n; j >= count1; --j) {
                    dp[i][j] = max(dp[i][j], dp[i - count0][j - count1] + 1);
                }
            }
        }
        
        // The answer is the maximum number of strings that can be formed with m 0's and n 1's
        return dp[m][n];
    }
};