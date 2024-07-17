#include<bits/stdc++.h>
using namespace std;
class Solution {
//    int  f(int idx,  vector<int> &dp){
//         if(idx==0) return 1;
//         if(idx <0) return 0;
//         if(dp[idx]!=-1) return dp[idx];
//         return dp[idx]=f(idx-1, dp)+f(idx-2, dp);
//     }
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);

        dp[0]=1;
        dp[1]=1;
        for(int idx=2; idx<=n; idx++){
            dp[idx]=dp[idx-1]+dp[idx-2];
        }
        return dp[n];
    }
};