class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ns=nums.size();
        int n=nums[0];
        int c=1;
        for(int i=1;i<ns;i++){
            if(c==0){
                n=nums[i];
                c=1;
            }
            else if(n==nums[i])c++;
            else{
                c--;
            }
        }
        return n;
    }
};