class Solution {
public:
    int maxArea(vector<int>& height) {
        int n= height.size();
        int i=0,j=n-1;
        int m=0;
        while(i<j){
            int h=min(height[i],height[j]);
            m= max(m,(j-i)*h);
            if(height[i] < height[j])
            i++;
            else j--;
        }
        return m;
    }
};