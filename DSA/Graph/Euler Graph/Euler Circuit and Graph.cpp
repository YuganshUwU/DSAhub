// this is a classic template to check for euler circuit and euler graph

class Solution {
public:

    void dfs(vector<int> adj[], int u, vector<bool>& visited) {
        visited[u] = true;
        
        for(auto curr : adj[u]) {
            if(!visited[curr])
                dfs(adj, curr, visited);
        }
    }

    bool isConnected(int n, vector<int> adj[]) {
        int start = -1;
        
        for(int i = 0; i < n; i++) {
            if(adj[i].size()) {
                start = i;
                break;
            }
        }
        
        vector<bool> visited(n, false);
        dfs(adj, start, visited);
        
        for(int i = 0; i < n; i++) {
            if(!visited[i] && adj[i].size() > 0)
                return false;
        }
        
        return true;
    }

	int isEulerCircuit(int V, vector<int>adj[]){
	    if(!isConnected(V, adj))
	        return 0;
	       
	    int odd = 0;
	    for(int i = 0; i < V; i++) {
	        if(adj[i].size() % 2)
	            odd++;
	    }
	    
	    return odd > 2 ? 0 : odd == 2 ? 1 : 2;
        
	}
};
