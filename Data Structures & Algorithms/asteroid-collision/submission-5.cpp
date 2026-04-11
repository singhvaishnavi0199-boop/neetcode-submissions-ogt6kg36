class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int i = 0;
        while(i<asteroids.size()){
            if(st.empty()){
                st.push(asteroids[i]);
                i++;
            }else{
                if (asteroids[i] > 0){
                    st.push(asteroids[i]);
                    i++;
                }else{
                    if (st.top() < 0){
                        st.push(asteroids[i]);
                        i++;
                    }else{
                        while(!st.empty()){
                            if (st.top() > 0 && st.top()== abs(asteroids[i])){
                                st.pop();
                                i++;
                                break;
                            }else if (st.top() > 0 && st.top() > abs(asteroids[i])){
                                i++;
                                break;
                            }else if (st.top() > 0 && st.top() < abs(asteroids[i])){
                                st.pop();
                            }else{
                                st.push(asteroids[i]);
                                i++;
                                break;
                            }
                        }
                    }
                }
            }
        }

        vector<int> res;
        while(!st.empty()){
           res.push_back(st.top());
           st.pop(); 
        }

        reverse(res.begin(), res.end());
        return res;
    }
};