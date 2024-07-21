class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        string ans=strs[0];
        for(int i=1;i<strs.size();i++){
            int ns=min(ans.size(),strs[i].size());
            int j=0;
            for(;j<ns;j++)
                if(strs[i][j]!=ans[j])break;
            ans=ans.substr(0,j);
        }
        return ans;
    }
};