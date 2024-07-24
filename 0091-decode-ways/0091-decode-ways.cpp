class Solution {
public:
    vector<int>dp;
    int count(string s,int i,int n){
        if(i>=n)return 0;
        if(s[i]=='0')return 0;
        if(i==n-1)return 1;
        string two=s.substr(i,2); 
        if(i+1==n-1){
            if(stoi(two)==10||stoi(two)==20)return 1;
            if(stoi(two)<=26)return 2;
        }
        if(dp[i]!=-1)return dp[i];
        int one=count(s,i+1,n);
        int tw=0;
        if(stoi(two)<=26)tw=count(s,i+2,n);
        return dp[i]=one+tw;
    }
    int numDecodings(string s) {
        dp.resize(s.size(),-1);
        return count(s,0,s.size());
    }
};