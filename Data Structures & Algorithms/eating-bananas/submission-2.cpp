class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=*max_element(piles.begin(),piles.end());
        int m=piles.size();
        int i;
        float hour;
        for(i=1;i<=n;i++){
            int j=0;
            long long s=0;
            while(j<m){
                hour=(float)piles[j]/i;
                s += (piles[j] + i - 1) / i;
                j++;
            }
            if(s>h)
                continue;
            else
                break;
        }
        return i;
    }
};
