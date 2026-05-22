// not going to explain anyu thing same fibonacci code same to same but insted of dp[0] try dp[2] = 2
//  just that base case change 

// leetcode - 70 


class Solution {
public:
    int climbStairs(int n) {

        if(n <= 2) return n;

        vector<int> dp(n + 1, 0);

        dp[1] = 1;
        dp[2] = 2;

        for(int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};