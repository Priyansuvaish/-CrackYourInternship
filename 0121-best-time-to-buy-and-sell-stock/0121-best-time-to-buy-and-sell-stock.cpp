class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i=0;
        int n=prices.size();
        int ma=0;
        int mi=1e9;
        while(i<n){
            if(mi>prices[i]){
                mi=prices[i];
            }
            ma=max(ma,prices[i]-mi);
            i++;
        }
        return ma;
    }
};