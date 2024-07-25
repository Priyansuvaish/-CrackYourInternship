class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans;
        int d=2;
        int i=0;
        if(n==0){ans.push_back(0);return ans;}
        if(n==1){
            ans.push_back(0);ans.push_back(1);return ans;}
        while(i<2)ans.push_back(i++);

        for(;i<n+1;i++){
            int b=ans[i/2];
            if(i%d==0){
                b=1;
                d*=2;
            }else{
                if(i%2)b+=1;
            }
            ans.push_back(b);
        }
        return ans;
    }
};