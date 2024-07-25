class Solution {
public:
    int c = 0;
    void revPairs(vector<int>&nums, int i,int m,int n,int j){
        int mid=n;
        while(i<=m){
            long long int bru=nums[n];
            while(n<=j&&nums[i]>2*bru){
                n++;
                bru=nums[n];
            }
            c+=n-mid;
            i++;
        }
    }
    void merge(vector<int>&nums, int i,int m,int n,int j){
        vector<int>t;
        int s=i,mid=m,e=j;
        while(s<=mid&& n<=e){
            if(nums[s]<nums[n]){t.push_back(nums[s]);s++;}
            else{ t.push_back(nums[n]);n++;}
        }
        while(s<=mid){t.push_back(nums[s]);s++;}
        while(n<=j){t.push_back(nums[n]);n++;}
        for(int st=i;st<=j;st++){
            nums[st]=t[st-i];
        }
    }
    void mergesort(vector<int>& nums,int i,int j){
        if(i==j)return;
        int m =(i+j)/2;
        mergesort(nums,i,m);
        mergesort(nums,m+1,j);
        revPairs(nums,i,m,m+1,j);        
        merge(nums,i,m,m+1,j);

    }
    int reversePairs(vector<int>& nums) {
        mergesort(nums,0,nums.size()-1);
        return c;
    }
};