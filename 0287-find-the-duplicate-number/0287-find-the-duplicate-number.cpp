class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        int i=nums[nums[0]],j=nums[nums[nums[0]]];
        while(i!=j){
            i=nums[i];
            j=nums[nums[j]];
        }
        i = nums[0];
        while (i != j) {
            i = nums[i];
            j = nums[j];
        }

        return i;
    }
};