class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        vector<int> ans(2,0);
        for(int i=0;i<nums.size();i++){
            int fin= target-nums[i];
            if(!fin) ans[0]=i;
            else{
                if(mp.find(fin) == mp.end())mp[nums[i]]=i;
                else{
                    ans[0]=i;
                    ans[1]=mp[fin];
                    break;
                }
            }
        }
        return ans;
    }
};