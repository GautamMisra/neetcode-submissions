class Solution {
public:
    void combinations(int idx,string digits,string&cur,vector<string>&ans){     
        vector<string> mapping = {
            "",      // 0
            "",      // 1
            "abc",   // 2
            "def",   // 3
            "ghi",   // 4
            "jkl",   // 5
            "mno",   // 6
            "pqrs",  // 7
            "tuv",   // 8
            "wxyz"   // 9
        };  
        if(idx==digits.size()){
            ans.push_back(cur);
            return;
        }
        string letters = mapping[digits[idx] - '0'];
        for(char letter:letters){
            cur.push_back(letter);
            combinations(idx+1,digits,cur,ans);
            cur.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) {
            return {};
        }
        string cur;
        vector<string>ans;
        combinations(0,digits,cur,ans);
        return ans;
    }
};
