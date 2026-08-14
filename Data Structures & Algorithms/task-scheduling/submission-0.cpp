class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>freq;
        for(char task:tasks){
            freq[task]++;
        }
        priority_queue<int>qp;
        for(auto it:freq)
            qp.push(it.second);
        queue<pair<int,int>>q;
        int time=0;
        while(!q.empty() || !qp.empty()){
            time++;
            if(!qp.empty()){
                int cnt=qp.top();
                qp.pop();
             cnt--;
             if (cnt>0)
                q.push( {cnt,time+n});
            }
            if(!q.empty() && q.front().second == time){
                qp.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};
