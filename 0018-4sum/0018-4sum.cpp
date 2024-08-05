class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            if(i>0&&nums[i-1]==nums[i])continue;
            for(int j=i+1;j<n;j++){
                
                    int p=j+1;
                    int q=n-1; 
                    while(p<q){
                        double sum=(double)nums[i]+(double)nums[j]+(double)nums[p]+(double)nums[q];
                        if(sum==target){
                            vector<int>t;
                            t.push_back(nums[i]);                                                                         t.push_back(nums[j]);
                            t.push_back(nums[p]);
                            t.push_back(nums[q]);
                            ans.push_back(t);
                            
                            while(p<q&&nums[p]==nums[p+1])p++;                                                             while(p<q&&nums[q]==nums[q-1])q--;
                            p++;q--;

                        }else if(sum<target)p++;
                        else q--;
                    }
                    while(j<n-1&&nums[j]==nums[j+1])j++;
                
            }
        }
        return ans;
    }
};