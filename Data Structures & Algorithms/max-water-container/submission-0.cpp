class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n=heights.size();
        int i,j,area=0,ans=0;
        for(i = 0; i < n; i++){
            for(j = i + 1; j < n; j++){
                area = min(heights[i], heights[j]) * (j - i);
                ans=max(ans,area);
            }
        }
        return ans;
    }
};
