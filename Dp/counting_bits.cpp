#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i=0; i<=n; i++){
            int a=i;
            int cnt=0;
            while(a){
                if(a & 1) cnt++;
                a=a>>1;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};