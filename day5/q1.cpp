//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    // int f(int ind, int target, int arr[], vector<vector<int>> &dp){
    //     if(target==0) return 1;
    //     if(ind==0){
    //         if(arr[0]==target) return 1;
    //         return 0;
    //     }
        
    //     if(dp[ind][target]!=-1) return dp[ind][target];
    //     int notTake=f(ind-1, target, arr, dp);
    //     int take=0;
    //     if(target >= arr[ind]){
    //         take=f(ind-1, target-arr[ind], arr, dp);
    //     }
        
    //     return dp[ind][target]=take |notTake;
    // }
public:
    int equalPartition(int N, int arr[])
    {
        // code here 
        int sum=0;
        for(int i=0; i<N; i++){
            sum+=arr[i];
        }
        if(sum%2!=0) return 0;
        
        vector<vector<int>> dp(N, vector<int> (sum/2+1,0));
        if(arr[0]==sum/2) dp[0][sum/2]=1;
        for(int ind=0; ind<N; ind++){
            dp[ind][0]=1;
        }
        
        for(int ind=1; ind<N; ind++){
            for(int target=1; target<=sum/2; target++){
                int notTake=dp[ind-1][target];
                int take=0;
                if(target >= arr[ind]){
                    take=dp[ind-1][target-arr[ind]];
                }
               dp[ind][target]=take |notTake;
            }
        }

        return dp[N-1][sum/2];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends