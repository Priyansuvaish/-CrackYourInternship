class Solution {
public:
//     int solve(vector<int>& nums,unordered_map<int,int>mp,int i,int n){
//         if(mp.size()==0||i==n)return 0;
//         int nottaken=solve(nums,mp,i+1,n);
//         int take = nums[i]*mp[nums[i]];
//         mp.erase(nums[i]);
//         if (mp.find(nums[i] - 1) != mp.end()) mp.erase(nums[i] - 1);
//         if (mp.find(nums[i] + 1) != mp.end()) mp.erase(nums[i] + 1);
//         take+=solve(nums,mp,i+1,n);
//         return max(take,nottaken);
        
        
//     }
    int deleteAndEarn(vector<int>& nums) {
        // unordered_map<int,int>mp;
        // int ans=0;
        int n=nums.size();
        // for(int i=0;i<n;i++){
        //     mp[nums[i]]++;
        // }
        // return solve(nums,mp,0,n); 
        int me=20000;
        vector<int>v(me,0);
        for(int i=0;i<n;i++){
            v[nums[i]]+=nums[i];
        }
        for(int i=2;i<me;i++){
            v[i]=max(v[i-1],v[i]+v[i-2]);
        }
        return v[me-1];
    }
};