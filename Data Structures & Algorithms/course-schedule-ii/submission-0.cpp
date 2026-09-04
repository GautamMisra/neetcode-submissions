class Solution {
public:
    bool dfs(int node,vector<vector<int>>& adj,int numCourses, vector<vector<int>>& prerequisites,vector<int>& color,vector<int>& ans){
        color[node]=1;
        for(int neighbour:adj[node]){
            if(color[neighbour]==1)
                return true;
            else if(color[neighbour]==0){
                if(dfs(neighbour,adj,numCourses,prerequisites,color,ans)){
                    return true;
                }
            }
        }
        color[node]=2;
        ans.push_back(node);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> ans;
        vector<int> color(numCourses, 0);
        for(auto& p:prerequisites){
            adj[p[1]].push_back(p[0]);
        }
        for(int i=0;i<numCourses;i++){
            if(color[i]==0){
                if(dfs(i,adj,numCourses,prerequisites,color,ans))
                    return{};
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
