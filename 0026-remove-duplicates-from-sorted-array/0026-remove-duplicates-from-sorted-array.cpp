class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n= nums.size();
        int i=0,j=0;
        if(n==1)return n;
        while(i<n-1){
            if(nums[i]==nums[i+1]){
                i++;
            }else{
                i++;j++;
                nums[j]=nums[i];
            }
            
        }
        return j+1;
    }
};