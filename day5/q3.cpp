#include <bits/stdc++.h>
using namespace std;
class Solution
{
    int f(int ind, vector<int> &freq, vector<int> &dp)
    {
        if (ind == 1)
            return freq[ind];
        if (ind == 0)
            return 0;
        if (dp[ind] != -1)
            return dp[ind];
        int notTake = 0 + f(ind - 1, freq, dp);
        int take = ind * freq[ind] + f(ind - 2, freq, dp);
        return dp[ind] = max(notTake, take);
    }

public:
    int deleteAndEarn(vector<int> &nums)
    {
        int maxElement = *max_element(nums.begin(), nums.end());
        vector<int> freq(maxElement + 1, 0);
        for (auto val : nums)
        {
            freq[val]++;
        }
        int n = freq.size();
        vector<int> dp(n, -1);
        return f(n - 1, freq, dp);
    }
};