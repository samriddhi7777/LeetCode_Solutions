class Solution {
public:
    void fun(string &digits, vector<string> &ans, string temp,int i){
        if(i == digits.size()){
           ans.push_back(temp);
           return;
        }
    string letters[10] = {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };
    string str = letters[digits[i] - '0'];
    for(int j = 0; j < str.size(); j++){
        temp.push_back(str[j]);
        fun(digits,ans,temp,i+1);
        temp.pop_back();
    }
    }
             
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        fun(digits,ans,"",0);
        return ans;
        
        
    }
};