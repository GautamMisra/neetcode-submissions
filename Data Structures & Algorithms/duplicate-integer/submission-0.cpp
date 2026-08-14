class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int i;
        int n=nums.size();
        for(i=0;i<n;i++){
            int v=nums[i];
            for(int j=i+1;j<n;j++){
                int b= nums[j];
                if(v==b)
                    return true;
                else
                    continue;
            }
        }
        return false;
    }
};
