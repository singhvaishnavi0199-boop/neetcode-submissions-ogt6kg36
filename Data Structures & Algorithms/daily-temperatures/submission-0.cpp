class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n,0);
        stack <pair<int,int>> st; // position, value
        st.push({0,temperatures[0]});

        for(int i =1; i<n; i++){
            while(!st.empty() && st.top().second < temperatures[i]){
                res[st.top().first] = i - st.top().first;
                st.pop();
            }
            st.push({i,temperatures[i]});  
        }

        return res;
    }
};
