class Solution {
public:
    void genpara(string&cur,vector<string>&ans,int n,int ocount,int ccount){
        if(ocount==n && ccount==n){
            ans.push_back(cur);
            return;
        }
        if(ocount<n){
            cur.push_back('(');
            ocount++;
            genpara(cur,ans,n,ocount,ccount);
            cur.pop_back();
            ocount--;
    }
        if(ccount<ocount){
            cur.push_back(')');
            ccount++;
            genpara(cur,ans,n,ocount,ccount);
            cur.pop_back();
            ccount--;
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string cur;
        genpara(cur,ans,n,0,0);
        return ans;
    }
};
