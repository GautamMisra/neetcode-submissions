class Solution {
public:
    bool dfs(int node,vector<vector<int>>& adj,int numCourses, vector<vector<int>>& prerequisites,vector<int>& color){
        color[node]=1;
        for(int neighbour : adj[node]){
            if(color[neighbour]==0){
                if(dfs(neighbour,adj,numCourses,prerequisites,color))
                    return true;    //if dfs encounters cycle well return true
            }
            else if(color[neighbour]==1){
                return true;
            }
        }
        color[node]=2;
        return false;   //if no cycle found return false
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> color(numCourses, 0);
        for(auto& p : prerequisites) {
            adj[p[1]].push_back(p[0]);
        }
        for(int i=0;i<numCourses;i++){
            if(color[i]==0){
                if(dfs(i,adj,numCourses,prerequisites,color))
                    return false; //cond true ie dfs return true so found cycle
            }
        }
        return true;
    }
};
