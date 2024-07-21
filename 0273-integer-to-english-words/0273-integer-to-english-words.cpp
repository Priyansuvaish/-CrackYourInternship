class Solution {
public:
    vector<string>ten={"","Ten ","Twenty ","Thirty ","Forty ","Fifty ","Sixty ","Seventy ","Eighty ","Ninety "};
    vector<string>one={"","One ","Two ","Three ","Four ","Five ","Six ","Seven ","Eight ","Nine ","Ten ","Eleven ","Twelve ","Thirteen ","Fourteen ","Fifteen ","Sixteen ","Seventeen ","Eighteen ","Nineteen "};
    string helper(int n,string s){
        string st="";
        if(n>19){
            st+=ten[n/10]+one[n%10];
        }
        else
            st+= one[n];
        if(n)st+=s;
        return st;
    }
    string numberToWords(int n) {
        if(n==0)return "Zero";
        int t=n;
        string res="";
        t=n/1000000000;
        if(t>0&&t<=999){
            res+=helper(t/100,"Hundred ");        
            res+=helper(t%100,"");
            res+="Billion ";
        }
        t=(n/1000000)%1000;
        if(t>0&&t<=999){
            res+=helper(t/100,"Hundred ");        
            res+=helper(t%100,"");
            res+="Million ";
        }
        t=(n/1000)%1000;
        if(t>0&&t<=999){
            res+=helper(t/100,"Hundred ");        
            res+=helper(t%100,"");
            res+="Thousand ";
        }
        t=n%1000;
        if(t>0&&t<=999){
            res+=helper(t/100,"Hundred ");        
            res+=helper(t%100,"");
        }res.pop_back();
        return res;
        
    }
};