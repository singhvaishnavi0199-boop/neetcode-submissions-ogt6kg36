// recursion = 2^n

// class Solution {
// public:
//     int climbStairs(int n) {
//         return dfs(0,n);
//     }

//     int dfs(int step, int n){
//         //if reached nth stair, then it is 1 path
//         if(step==n){
//             return 1;
//         }

//         //if going out of bounds for the nth step, then there is no path
//         if(step > n){
//             return 0;
//         }

//         // for ith step, it is all no of ways from i+1th + i+2th step
//         return dfs(step+1, n) + dfs(step+2, n);
//     }
// };


// top down approach - memoization

class Solution {
public:
    int climbStairs(int n) {
        vector<int> steps(n+1, -1);
        steps[n] = 1;
        steps[n-1] = 1;

        for(int i = n-2 ; i >= 0 ; i--){
            steps[i] = steps[i+1] + steps[i+2];
        }

        return steps[0];
    }
};

