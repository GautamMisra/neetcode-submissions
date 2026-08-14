class MinStack {
public:
    int st[10000];
    int topindex;
    int minst[10000];
    int mintopindex;
    MinStack() {
        topindex=-1;
        mintopindex=-1;
    }
    
    void push(int val) {
        topindex++;
        st[topindex]=val;
        if(mintopindex==-1){
            mintopindex++;
            minst[mintopindex]=val;
        }
        else{
            mintopindex++;
            minst[mintopindex]=min(val,minst[mintopindex-1]);
        }
    }
    
    void pop() {
        topindex--;
        mintopindex--;
    }
    
    int top() {
        return st[topindex];
    }
    
    int getMin() {
        return minst[mintopindex];
    }
};
