class MinStack {
private:
    stack<int> st;
    stack<int> minSt;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(minSt.empty()){
            minSt.push(val);
        }else{
            if (val <= minSt.top()){
                minSt.push(val);
            }
        }
    }
    
    void pop() {
        if (!st.empty()){
            int ele = st.top();
            st.pop();
            if(!minSt.empty() && minSt.top() == ele){
                minSt.pop();
            }
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};
