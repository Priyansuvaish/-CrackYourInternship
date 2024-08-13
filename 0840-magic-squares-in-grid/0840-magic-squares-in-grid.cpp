class Solution {
public:
    bool ismagic(vector<vector<int>>& grid,int r,int c){
        unordered_map<int,int>mp;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                int num=grid[r+i][c+j];
                if(num<1||num>9||mp.find(num)!=mp.end())
                    return false;
                else mp[num]++;
            }
        }
        int rsum=grid[r][c]+grid[r][c+1]+grid[r][c+2];
        for(int i=0;i<3;i++){
            if(grid[r+i][c]+grid[r+i][c+1]+grid[r+i][c+2]!=rsum)return false;
            if(grid[r][c+i]+grid[r+1][c+i]+grid[r+2][c+i]!=rsum)return false;
        }
        int dia=grid[r][c]+grid[r+1][c+1]+grid[r+2][c+2];
        if(dia!=rsum)return false;
        int adia=grid[r][c+2]+grid[r+1][c+1]+grid[r+2][c];
        if(adia!=rsum)return false;
        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int c=0;
        for(int i=0;i<n-2;i++){
            for(int j=0;j<m-2;j++){
                if(ismagic(grid,i,j))c++;
            }
        }
        return c++;
    }
};