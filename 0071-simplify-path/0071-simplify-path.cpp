class Solution {
public:
    string simplifyPath(string path) {
        int n= path.size();
        int i=0;
        stack<string>s;
        if(path[0]!='/')return "";
        string tmp="";
        while(i<n){
            if((s.empty()||s.top()!="/")&&path[i]=='/'){
                string tmp="";
                s.push(tmp+'/');
                i++;
            }
            if(path[i]=='/'&&s.top()=="/"){
                i++;
            }
            string t="";
            int dc=0;
            while(i<n&&path[i]!='/'){
                if(path[i]=='.')dc++;
                t+=path[i];
                i++;
            }
            if(dc==t.size()){
                if(t.size()==2&&s.size()>2){
                    s.pop();
                    s.pop();
                    s.pop();
                }
                if(t.size()>=3)s.push(t);
            }else{
                s.push(t);
            }
        }
        if(s.empty())return "/";

        while(s.size()>1&&s.top()=="/")s.pop();
        string ans="";
        while(!s.empty()){
            ans=s.top()+ans;
            s.pop();
        }
        return ans;
    }
};