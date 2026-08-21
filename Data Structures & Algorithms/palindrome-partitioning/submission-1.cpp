class Solution {
public:
bool isPalindrome(string& s, int start, int end) {
    while(start < end) {
        if(s[start] != s[end])
            return false;

        start++;
        end--;
    }

    return true;
}
    void parti(int start,string s,vector<string>&cur,vector<vector<string>>&ans){
        if(start==s.size()){
            ans.push_back(cur);
            return;
        }
        for(int end = start; end < s.size(); end++) {
            string part = s.substr(start, end - start + 1);
            if(isPalindrome(s,start,end)) {
                cur.push_back(part);    //make the choice
                parti(end+1,s,cur,ans);  //explore the choice till the end
                cur.pop_back();         //undo the choice(backtrack)
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string>cur;
        vector<vector<string>>ans;
        parti(0,s,cur,ans);
        return ans;
    }
};
