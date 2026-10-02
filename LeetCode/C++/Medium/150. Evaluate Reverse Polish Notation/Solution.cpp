class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i = 0; i < tokens.size(); i++){
            string token = tokens[i];

            if(token == "+" || token == "-" || token == "*" || token == "/"){
                int first = st.top();
                st.pop();

                int second = st.top();
                st.pop();

                int result;

                if(token == "+"){
                    result = second + first;
                }
                else if(token == "-"){
                    result = second - first;
                }
                else if(token == "*"){
                    result = second * first;
                }
               
                else{
                    result = second / first;

                }
                st.push(result);

            }
            else{
                st.push(stoi(token));
            }
        }
        
        return st.top();
    }
};