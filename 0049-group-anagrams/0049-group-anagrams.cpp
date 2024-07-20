class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        map<int,vector<string>>mp;
        for(auto s:strs){
            vector<int>c(26);
            for(auto i:s){
                c[i-'a']++;
            }
            long long num=0;
            for(auto j:c)num=(num*10+j)%INT_MAX;
            cout<<num<<" ";
            mp[num].push_back(s);            
        }
        vector<vector<string>>ans;
        for(auto i:mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};