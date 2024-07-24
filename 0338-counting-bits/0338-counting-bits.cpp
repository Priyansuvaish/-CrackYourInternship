class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans;
        for(int i=0;i<n+1;i++){
            int c=0;
            int t=i;
            while(t>0){
                if(t&1)c++;
                t=t/2;
            }
            ans.push_back(c);
        }
        return ans;
    }
};