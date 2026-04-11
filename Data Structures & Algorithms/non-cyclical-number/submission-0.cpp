class Solution {
unordered_set <int> visited;
public:
    bool isHappy(int n) {
        int val = 0;
        int multiplier = 1;
        int temp = n;
        while(temp > 0){
            int digit = temp % 10;
            temp = temp /10;
            val += digit * digit;
        }

        if (val == 1){
            return true;
        }else{
            if (visited.find(val) != visited.end()){
                return false;
            }
            visited.insert(val);
            return isHappy(val);
        }
    }
};
