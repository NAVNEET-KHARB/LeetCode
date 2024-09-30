class CustomStack {
    list<int> stackV;
    int maxSize;
public:
    CustomStack(int maxSize) {
        this->maxSize = maxSize;
    }
    
    void push(int x) {
        if(stackV.size()<maxSize){
            stackV.push_back(x);
        }
    }
    
    int pop() {
        if(stackV.size()>0){
            int ele = stackV.back();
            stackV.pop_back();
            return ele;
        }
        return -1;
    }
    
    void increment(int k, int val) {
        auto it = stackV.begin();
        for(int i = 0; i<k && it != stackV.end(); i++,it++){
            *it += val;
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