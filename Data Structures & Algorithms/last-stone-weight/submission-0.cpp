class Solution {
public:
int x,y;
    pair<int, int> maximum(vector<int>& arr){
        sort(arr.begin(),arr.end());
        int n=arr.size();
        return {arr[n-2],arr[n-1]};
    }
    int lastStoneWeight(vector<int>& stones) {
        while(stones.size()>1){
        pair<int, int> p = maximum(stones);
        x=p.first;
        y=p.second;
            if(x==y){
                stones.pop_back();
                stones.pop_back();
            }
            else{
                y=y-x;
                stones.pop_back();
                stones.pop_back();
                stones.push_back(y);
            }
        }
        if(stones.empty())
            return 0;
        return stones[0];
    }
};
