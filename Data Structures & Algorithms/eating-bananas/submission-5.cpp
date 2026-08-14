class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1,r=*max_element(piles.begin(),piles.end());
        int m=piles.size(),k;
        int ans=r;
        while(l<=r){
            int j=0;
            long long s=0;
            k=(l+r)/2;
            while(j<m){
                s += (piles[j] + k - 1) / k;
                j++;
            }
            if(s<=h){
                ans=k;
                r=k-1;
            }
            else
                l=k+1;
        }
        return ans;
    }
};
