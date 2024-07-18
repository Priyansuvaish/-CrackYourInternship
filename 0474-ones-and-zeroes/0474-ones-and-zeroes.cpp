class Solution {
public:
    map<string,pair<int,int>>mp;
    vector<vector<vector<int>>>dp;
    int subset(vector<string>& strs,int i,int m,int n){
        if(m<0||n<0||i>=strs.size())return 0;
        if(dp[m][n][i]!=-1){
            return dp[m][n][i];
        }
        int newm = mp[strs[i]].first;
        int newn = mp[strs[i]].second;
        
        if(m>=newm&&n>=newn)return dp[m][n][i]= max(1+subset(strs,i+1,m-newm,n-newn),subset(strs,i+1,m,n));

        return dp[m][n][i]=subset(strs,i+1,m,n);

    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int ns = strs.size();
        dp.resize(m+1,vector<vector<int>>(n+1,vector<int>(ns+1,-1)));
        for(int i=0;i<ns;i++){
            int oo=0,oe=0;
            for(auto j:strs[i]){
                if(j=='0')oo++;
                else oe++;
            }
            mp[strs[i]]={oo,oe};

        }
        return subset(strs,0,m,n);
    }
};