class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n=tokens.size();
        int ans=0;
        stack<int> st;
        for(int i=0;i<n;i++){
            int x=0,y=0;
            if(tokens[i] != "+" &&
            tokens[i] != "-" &&
            tokens[i] != "*" &&
            tokens[i] != "/")
            {
                st.push(stoi(tokens[i]));
            }
            else
            {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();

                if(tokens[i] == "+") st.push(a + b);
                else if(tokens[i] == "-") st.push(a - b);
                else if(tokens[i] == "*") st.push(a * b);
                else st.push(a / b);
            }
        }
        return st.top(); 
    }
};
