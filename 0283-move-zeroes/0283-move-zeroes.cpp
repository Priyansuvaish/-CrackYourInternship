class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int j=-1;
        int c=0;
        while(i<n){
            if(j==-1 && nums[i]==0){
                j=i;
            }
            if(nums[i]==0)c++;
            else if(j!=-1 && nums[i]!=0){
                nums[j]=nums[i];
                j++;
            }
            i++;
        }
        int k=n-1;
        while(c--){
            nums[k--]=0;
        }
        
    }
};