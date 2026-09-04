class Solution {
public:
    bool dfs(int node,int parent,vector<vector<int>>& adj,int n, vector<bool>& visited){
        visited[node]=true;
        for(int neighbour:adj[node]){
            if(!visited[neighbour]){
                if(dfs(neighbour,node,adj,n,visited))
                    return true;
            }
            else if(neighbour!=parent){
                return true;
            }
        }
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto& e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<bool> visited(n, false);
        if(dfs(0,-1,adj,n,visited))
            return false;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                    return false;
            }
        }
        return true;
    }
};
