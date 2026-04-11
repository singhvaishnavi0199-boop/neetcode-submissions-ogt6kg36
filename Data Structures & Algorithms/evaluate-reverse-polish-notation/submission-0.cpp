class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i =0; i<tokens.size(); i++){
            if (tokens[i] == "+" ||
                tokens[i] == "-" ||
                tokens[i] == "*" ||
                tokens[i] == "/"){
                
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();

                int res = 0;
                if (tokens[i] == "+"){
                    res = a+b;
                }else if (tokens[i] == "-"){
                    res = a-b;
                }else if (tokens[i] == "*"){
                    res = a*b;
                }else {
                    res = a/b;
                }
                st.push(res);

            }else{
                int ele = stoi(tokens[i]);
                st.push(ele);
            }
        }
        return st.top();
    }
};
