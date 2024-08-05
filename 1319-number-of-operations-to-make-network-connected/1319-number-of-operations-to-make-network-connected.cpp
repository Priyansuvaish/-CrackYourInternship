class Solution {
public:
    void unionset(vector<int>&parent,vector<int>&size,int u,int v){
        int pu=find(u,parent);
        int pv=find(v,parent);
        if(size[pu]<size[pv]){
            parent[pu]=pv;
            size[pv]+=size[pu];
        }else{
            parent[pv]=pu;
            size[pu]+=size[pv];

        }

    }
    int find(int v,vector<int>&parent){
        if(v==parent[v])return v;
        return parent[v]=find(parent[v],parent);
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(n-1>connections.size())return -1;
        vector<int>parent(n);
        vector<int>size(n,1);
        int c=0;
        for(int i=0;i<n;i++)parent[i]=i;
        for(int i=0;i<connections.size();i++){
            int pu=find(connections[i][0],parent);
            int pv=find(connections[i][1],parent);
            if(pu==pv)c++;
            else unionset(parent,size,connections[i][0],connections[i][1]);
        }
        int nc=0;
        for(int i=0;i<n;i++){
            cout<<parent[i]<<" ";
            if(parent[i]==i)nc++;
        }
        nc--;
        if(c>=nc)return nc;
        return -1;

    }
};