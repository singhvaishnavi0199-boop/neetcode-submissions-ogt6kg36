class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = INT_MIN;
        stack<pair<int,int>> st;
        for(int i=0; i<heights.size(); i++){
            if (st.empty()){
                st.push({i,heights[i]});
                cout<<"pushed "<<i << " "<<heights[i]<<endl;
                continue;
            }

            int lastPopIndex = -1;
            while(!st.empty() && heights[i] < st.top().second){
                auto [index, height] = st.top();
                st.pop();
                cout<<"popped "<<index << " "<<height<<endl;
                int currArea = (i-index) * height;
                maxArea = max (maxArea, currArea);
                lastPopIndex = index;
            }

            if (lastPopIndex == -1){
                st.push({i,heights[i]});
                cout<<"pushed "<<i << " "<<heights[i]<<endl;
            }else{
                st.push({lastPopIndex, heights[i]});
                cout<<"lastPopIndex "<<i << " "<<heights[i]<<endl;
            }
        }
        int n = heights.size();
        while(!st.empty()){
            auto[index, height] = st.top();
            int currArea = (n-index) * height;
            maxArea = max (maxArea, currArea);
            st.pop();
        }

        return maxArea;
    }
};
