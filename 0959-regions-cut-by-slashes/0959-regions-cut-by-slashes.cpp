class Solution {
public:
    vector<vector<int>>d={{0,1},{0,-1},{-1,0},{1,0}};
    void dfs(vector<vector<int>>&matrix,int i,int j){
        if(i<0||j<0||i>=matrix.size()||j>=matrix[0].size()||matrix[i][j]==1)return;
        matrix[i][j]=1;
        for(auto it:d){
            int x=it[0]+i;
            int y=it[1]+j;
            dfs(matrix,x,y);
        }
    }
    int regionsBySlashes(vector<string>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>matrix(n*3,vector<int>(m*3,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='\\'){
                    matrix[i*3][j*3]=1;
                    matrix[i*3+1][j*3+1]=1;
                    matrix[i*3+2][j*3+2]=1;
                }
                else if(grid[i][j]=='/'){
                    matrix[i*3][j*3+2]=1;
                    matrix[i*3+1][j*3+1]=1;
                    matrix[i*3+2][j*3]=1;
                }
            }
        }
        int c=0;
        for(int i=0;i<n*3;i++){
            for(int j=0;j<m*3;j++){
                if(!matrix[i][j]){
                    c++;
                    dfs(matrix,i,j);
                }
            }
        }
        return c;
    }
};