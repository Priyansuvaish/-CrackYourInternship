class Solution {
public:
    
    bool dfs(vector<vector<int>>& graph,int i,vector<int>&vis,int n,vector<bool>&iscyc){
        iscyc[i]=true;
        vis[i]=1;
        for(auto it:graph[i]){
            if(!vis[it] && dfs(graph,it,vis,n,iscyc))return true;
            else{
                if(iscyc[it])return true;
            }
        }
        iscyc[i]=false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        int m=graph[0].size();
        vector<int>ter;
        vector<int>vis(n);
        vector<bool>iscyc(n);
        
        for(int i=0;i<n;i++){
            if(!vis[i])dfs(graph,i,vis,n,iscyc);   
        }
        for(int i=0;i<n;i++)if(!iscyc[i])ter.push_back(i);
        return ter;
    }
};