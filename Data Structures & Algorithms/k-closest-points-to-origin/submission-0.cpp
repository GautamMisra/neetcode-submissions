class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> temp;
        for (int i = 0; i < points.size(); i++) {
            int x = points[i][0];
            int y = points[i][1];
            int dist = x * x + y * y;
            temp.push_back({dist, x, y});
        }
        sort(temp.begin(), temp.end());
        vector<vector<int>> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back({temp[i][1], temp[i][2]});
        }
        return ans;
    }
};
