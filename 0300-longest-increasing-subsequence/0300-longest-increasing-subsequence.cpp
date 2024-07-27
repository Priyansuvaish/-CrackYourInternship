class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            auto index=lower_bound(ans.begin(),ans.end(),nums[i]);
            if(index==ans.end())ans.push_back(nums[i]);
            else{
                ans[index-ans.begin()]=nums[i];
            }
        }
        return ans.size();
    }
};