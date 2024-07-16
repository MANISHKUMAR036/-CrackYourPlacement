//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    bool bfs(int node, vector<int> adj[], vector<int> &vis){
        queue<pair<int,int>> q;
        q.push({node,-1});
        vis[node]=1;
        while(!q.empty()){
            int currNode= q.front().first;
            int parentNode =q.front().second;
            q.pop();
            for(auto adjNode: adj[currNode]){
                if(!vis[adjNode]){
                    vis[adjNode]=1;
                    q.push({adjNode, currNode});
                }
                else if(parentNode != adjNode) return true;
            }
        }
        return  false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V,0);
        for(int i=0; i<V; i++){
            if(!vis[i]){
                if((bfs(i, adj, vis)) == true){
                    return true;
                }
            }
        }
        return false;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends