class Solution {
public:
    void fun(vector<string> &ans, string s,int open,int close,int n){
        if(open == n && close == n){
           ans.push_back(s);
           return;
        }
        if(open < n){
            fun(ans,s + '(',open + 1,close,n);
        }
        if(close < open){
            fun(ans,s + ')',open, close + 1,n);
        }

    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        fun(ans,"",0,0,n);
        return ans;
        
    }
};