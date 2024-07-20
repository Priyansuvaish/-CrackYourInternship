class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int mi=1e9,i=0;
        int ans=0;
        while(i<n){
            if(mi>prices[i]){
                mi=prices[i];
                i++;
            }
            while(i<n&&mi<prices[i]&&prices[i-1]<prices[i])i++;
            if(mi!=1e9)ans+=(prices[i-1]-mi);
            mi=1e9;
        }
        return ans;
    }
};