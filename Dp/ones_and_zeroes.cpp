#include<bits/stdc++.h>
using namespace std;
class Solution {
    int f(int ind, pair<int,int> &W,  vector<pair<int,int>> &vp, vector<vector<vector<int>>> &dp){
         int zero=vp[ind].first;
         int one=vp[ind].second;
        if(ind==0){
            if(zero<=W.first && one<=W.second) return 1;
            return 0;
        }

        if(dp[ind][W.first][W.second] !=-1) return  dp[ind][W.first][W.second];

        int notTake=0+f(ind-1, W, vp, dp);
        int Take=INT_MIN;
        if(zero<=W.first && one<=W.second){
            pair<int,int> temp;
            temp={W.first-zero, W.second-one};
            Take=1+f(ind-1, temp, vp, dp);
        }

        return dp[ind][W.first][W.second]=max(Take, notTake);
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int N=strs.size();
        vector<pair<int,int>> vp;
        for(int i=0; i<N; i++){
            int cnt0=0, cnt1=0;
            for(int j=0; j<strs[i].size(); j++){
                if(strs[i][j]=='0') cnt0++;
                else cnt1++;
            }
            vp.push_back({cnt0,cnt1});
        }
       
       pair<int,int> W={m,n};
       vector<vector<vector<int>>>dp(N,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
       return f(N-1, W, vp, dp);
    }
};