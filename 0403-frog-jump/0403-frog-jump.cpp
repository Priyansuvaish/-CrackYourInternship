class Solution {
public:
    bool res=false;
    unordered_map<int,int>mp;
    vector<vector<int>>dp;

    bool solve(vector<int>& stones,int cs,int pre){
        if(cs==mp.size()-1)return true;
        if(dp[cs][pre]!=-1)return dp[cs][pre];
        for(int next=pre-1;next<=pre+1;next++){
            if(next>0 && mp.find(stones[cs]+next)!=mp.end()){
                res=res||solve(stones,mp[stones[cs]+next],next);
            }
        }
        return dp[cs][pre]=res;
    }
    bool canCross(vector<int>& stones) {
        dp.resize(stones.size(),vector<int>(stones.size(),-1));
        for(int i=0;i<stones.size();i++){
            mp[stones[i]]=i;
        }
        solve(stones,mp[0],0);
        return res;
    }
};