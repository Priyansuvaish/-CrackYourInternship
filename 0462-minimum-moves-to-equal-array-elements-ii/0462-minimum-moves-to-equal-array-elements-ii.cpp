class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n= nums.size();
        sort(nums.begin(),nums.end());
        int m=n/2;
        int ans=0;
        for(auto a:nums)ans+=abs(a-nums[m]);
        return ans;
    }
};