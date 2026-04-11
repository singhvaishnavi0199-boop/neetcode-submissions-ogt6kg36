class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack <int> st;
        int result = 0;
        for (const string operation: operations){
            if (operation == "+"){
                int top = st.top();
                st.pop();
                int newTop = st.top();
                st.push(top);
                st.push(top+newTop);
                result += st.top();
            }else if (operation == "C"){
                result -= st.top();
                st.pop();
            }else if (operation == "D"){
                st.push(2*st.top());
                result += st.top();
            }else{
                st.push(stoi(operation));
                result += st.top();
            }
        }
        return result;

    }
};