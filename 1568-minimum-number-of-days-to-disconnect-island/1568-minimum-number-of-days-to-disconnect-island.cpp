class Solution {
public:
    vector<vector<int>>d={{1,0},{0,1},{-1,0},{0,-1}};
    void dfs(vector<vector<int>>&grid,int i,int j){
        if(i<0||j<0||i>=grid.size()||j>=grid[0].size()||!grid[i][j])return;
        grid[i][j]=0;
        for(auto it:d){
            int x=it[0]+i;
            int y=it[1]+j;
            dfs(grid,x,y);
        }
    }
    int island(vector<vector<int>>grid){
        int n=grid.size();
        int m=grid[0].size();
        int c=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    c++;
                    dfs(grid,i,j);
                }
            }
        }
        return c;
    }
    int minDays(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ci=0;
        ci=island(grid);
        if(ci>1||ci==0)return 0;
        cout<<ci;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    grid[i][j]=0;
                    int c=island(grid);
                    if(c>1||!c)return 1;
                    grid[i][j]=1;
                    
                }
            }
        }

        return 2;
    }
};