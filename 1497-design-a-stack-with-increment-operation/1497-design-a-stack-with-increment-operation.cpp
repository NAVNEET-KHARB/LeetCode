class CustomStack {
    vector<int> stackV;
    int top;
public:
    CustomStack(int maxSize) {
        stackV.resize(maxSize);
        top = -1;
    }
    
    void push(int x) {
        if(top < (int)(stackV.size())-1){
            top++;
            stackV[top] = x;
        }
    }
    
    int pop() {
        if(top>=0){
            return stackV[top--];
        }
        return -1;
    }
    
    void increment(int k, int val) {
        int lim = min(k,top+1);
        for(int i = 0; i<lim; i++){
            stackV[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */