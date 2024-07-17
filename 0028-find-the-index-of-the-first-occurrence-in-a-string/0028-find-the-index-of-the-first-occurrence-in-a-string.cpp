class Solution {
public:
    int strStr(string h, string n) {
        int n1=h.size();
        int n2=n.size();
        int q=INT_MAX;
        int d=26;
        long long hn=0;
        long long hh=0;
        long long p=1;
        for(int i=0;i<n2;i++){
            hn=(hn*d+n[i])%q;
            hh=(hh*d+h[i])%q;

        }
        if(hh==hn)return 0;
        for (int l = 0; l < n2 - 1; l++)p = (p * d) % q;

        int i=0;
        int j=0;
        while(i<=n1-n2){
            if(hh==hn){
                int k;
                for(k=0;k<n2;k++){
                    if(h[i+k]!=n[k])break;
                }
                if(k==n2)return i;
            }
            else{
                hh=((hh-(h[i]*p))*d+h[i+n2])%q;
                if (hh < 0)
                hh = (hh + q);
            }
            i++;
        }
        if(hh==hn)return i;

        return -1;
    }
};