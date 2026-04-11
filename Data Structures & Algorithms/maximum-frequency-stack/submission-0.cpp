class FreqStack {
private:
    unordered_map <int,int> valToCount;
    unordered_map <int, stack<int>> countToVal;
    int maxCount;
public:
    FreqStack() {
        maxCount = 0;
        valToCount.clear();
        countToVal.clear();
    }
    
    void push(int val) {
       valToCount[val]++;
       int cnt = valToCount[val];
       countToVal[cnt].push(val);
       maxCount = max(maxCount, cnt);
    }
    
    int pop() {
        int ele = countToVal[maxCount].top();
        countToVal[maxCount].pop();
        valToCount[ele]--;
        if (countToVal[maxCount].empty()){
            maxCount--;
        }
        return ele;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */