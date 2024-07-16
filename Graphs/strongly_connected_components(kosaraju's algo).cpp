//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	void dfs(int node, vector<vector<int>>& adj, vector<int> &vis, stack<int> &st){
	    vis[node]=1;
	    for(auto adjNode: adj[node]){
	        if(!vis[adjNode]){
	            dfs(adjNode, adj, vis, st);
	        }
	    }
	    st.push(node);
	}
	
	void newDfs(int node, vector<int> revadj[], vector<int> &vis){
	    vis[node]=1;
	    for(auto adjNode: revadj[node]){
	        if(!vis[adjNode]){
	            newDfs(adjNode, revadj, vis);
	        }
	    }
	}

	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
         int n=adj.size();
         vector<int> vis(V,0);
         stack<int> st;
         for(int i=0; i<n; i++){
             if(!vis[i]){
                 dfs(i, adj, vis, st);
             }
         }
         
         vector<int> revadj[n];
         
         for(int i=0; i<n; i++){
             vis[i]=0;
             for(auto Node: adj[i]){
                 revadj[Node].push_back(i);
             }
         }
         
         int ans=0;
         while(!st.empty()){
             int node=st.top();
             st.pop();
             if(!vis[node]){
                 ans++;
                 newDfs(node, revadj, vis);
             }
         }
         return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends