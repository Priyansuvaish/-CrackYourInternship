class Solution {
public:
    int maxfreq(unordered_map<char,int>mp){
        int ma=0;
        for(auto it:mp){
            ma=max(ma,it.second);
        }
        return ma;
    }
    int characterReplacement(string s, int k) {
        int n= s.size();
        int i=0,j=0;
        int le=0;
        int maxfre=0;
        unordered_map<char,int>mp;
        while(j<n){
            mp[s[j]]++;
            maxfre=maxfreq(mp);
            if((j-i+1-maxfre)<=k){
                le=max(le,j-i+1);
                j++;
            }else{
                while((j-i+1-maxfre)>k&& i<=j){
                    mp[s[i]]--;
                    maxfre=maxfreq(mp);
                    i++;
                }
                j++;
            }
        }
        return le;
    }
};