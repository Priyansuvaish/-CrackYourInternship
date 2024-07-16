class Solution {
public:
    int strStr(string h, string n) {
        int n1=h.size();
        int n2=n.size();
        int i=0;
        int c=-1;
        while(i<n1){
            string st=h.substr(i,n2);

            if(st==n){
                c=i;
                break;
            }
            i++;
        }

        return c;
    }
};