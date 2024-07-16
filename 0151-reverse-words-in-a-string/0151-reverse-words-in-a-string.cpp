class Solution {
public:
    string reverseWords(string s) {
        int n= s.size();
        string t="";
        string ans="";
        int i=0;
        for(int j=0;j<n;j++){
            if(s[j]==' ')i++;
            else break;
        }
        for(int j=n-1;j>=0;j--){
            if(s[j]==' ')n--;
            else break;
        }
        for(;i<n;i++){
            if(s[i]!=' '){
                t+=s[i];
            }
            else{
                ans=' '+t+ans;
                t="";
                while(s[i]==' ')i++;
                i--;
            }
        }
        cout<<"a"+ans;
        ans=t+ans;
        return ans;
    }
};