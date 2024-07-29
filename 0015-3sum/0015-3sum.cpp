class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i>0&& nums[i]==nums[i-1])continue;
            int p=i+1,q=n-1;
            while(p<q){vector<int>t;
                if(nums[i]+nums[p]+nums[q]==0){
                    t.push_back(nums[i]);
                    t.push_back(nums[p]);
                    t.push_back(nums[q]);
                    ans.push_back(t);
                    
                    while(p<q&&nums[p]==nums[p+1])p++;
                    while(p<q&&nums[q]==nums[q-1])q--;
                    p++;q--;
                }
                else if(nums[i]+nums[p]+nums[q]>0){
                    q--;
                }
                else p++;
            }
        }
        return ans;
    }
};