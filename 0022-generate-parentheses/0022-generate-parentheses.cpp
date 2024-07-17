class Solution {
public:
    vector<string>ans;
    void par(string a,int n,int o,int c){
        if(a.size()==2*n){
            ans.push_back(a);
            return;
        }
        if(o<n){
            a.push_back('(');
            par(a,n,o+1,c);
            a.pop_back();
        }
        if(c<o){
            a.push_back(')');
            par(a,n,o,c+1);
            a.pop_back();
        }
        
    }
    vector<string> generateParenthesis(int n) {
        int o=0;
        int c=0;
        par("",n,o,c);
        return ans;
    }
};