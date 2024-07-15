class Solution {
public:
    bool isValid(string st) {
        stack<char>s;
        for(auto a:st){
            if(!s.empty()&& a==')'&& s.top()=='(')s.pop();
            else if(!s.empty()&& a==']'&& s.top()=='[')s.pop();
            else if(!s.empty()&& a=='}'&& s.top()=='{')s.pop();
            else if(a=='['|| a=='('|| a=='{')s.push(a);
            else return false;
        }
        if(s.empty())return true;
        return false;
    }
};