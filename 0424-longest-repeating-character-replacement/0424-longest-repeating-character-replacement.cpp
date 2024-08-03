class Solution {
public:
    int characterReplacement(string s, int k) {
        int n= s.size();
        int i=0,j=0;
        int le=0;
        int maxfre=0;
        unordered_map<char,int>mp;
        while(j<n){
            mp[s[j]]++;
            maxfre=max(maxfre,mp[s[j]]);
            if((j-i+1)-maxfre>k&& i<=j){
                mp[s[i]]--;
                i++;
            }
            le=max(le,j-i+1);
            j++;
        }
        return le;
    }
};