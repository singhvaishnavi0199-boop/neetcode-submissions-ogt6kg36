class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size();
        stack <string> st;
        for(int i = 0; i<n ; i++){
            if (path[i] == '/'){
                continue;
            }
            string s = "";

            while(i<n && path[i] != '/'){
                s += path[i];
                i++;
            }

            if (s == ".." && !st.empty()){
                st.pop();
            }else if (s == ".." && st.empty()){
                continue;
            }
            else if (s == "."){
                continue;
            }
            else{
                st.push(s);
            }
        }

        if (st.empty()){
            return "/";
        }

        stack <string> reverseSt;
        while(!st.empty()){
            reverseSt.push(st.top());
            st.pop();
        }

        string result = "";
        while(!reverseSt.empty()){
            result += '/';
            result += reverseSt.top();
            reverseSt.pop();
        }

        return result;
    }
};