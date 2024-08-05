class Solution {
public:
    vector<vector<int>>v={{0,1},{0,-1},{1,0},{-1,0},{-1,-1},{-1,1},{1,-1},{1,1}};
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>next(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int c=0;
                for(auto it:v){
                    int x=i+it[0];
                    int y=j+it[1];
                    if(x>=0 && y>=0 && x<n && y<m && board[x][y])c++;
                }
                if(board[i][j]&&(c<2||c>3))next[i][j]=0;
                else if(board[i][j]&&(c==2||c==3))next[i][j]=1;
                else if(!board[i][j]&&c==3)next[i][j]=1;
            }
        }
        board=next;
    }
};