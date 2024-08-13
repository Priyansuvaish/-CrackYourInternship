class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rS, int cS) {
        vector<vector<int>>dir={{0,1},{1,0},{0,-1},{-1,0}};
        int step=0,di=0;
        vector<vector<int>>ans;
        ans.push_back({rS,cS});
        while(ans.size()!=rows*cols){
            if(di==0||di==2)step++;
            for(int c=0;c<step;c++){
                rS+=dir[di][0];
                cS+=dir[di][1];
                if(rS>=0&&cS>=0&&rS<rows&&cS<cols)ans.push_back({rS,cS});
            }
            di=(di+1)%4;
        }
        return ans;
    }
};