class MinStack {
    Stack<Long> st;
    long minVal;
    public MinStack() {
        st = new Stack<>();
    }
    
    public void push(int val) {
        long value = val;
        if(st.isEmpty()){
            minVal = value;
            st.push(value);
        }else{
            if(value<minVal){
                st.push((2*value-minVal));
                minVal = value;
            }else st.push(value);
        }
    }
    
    public void pop() {
        long el = st.pop();
        if(el<minVal){
            minVal = 2*minVal-el;
        }
    }
    
    public int top() {
        long el = st.peek();
        if(el<minVal) return (int)minVal;
        return (int)el;
    }
    
    public int getMin() {
        return (int)minVal;
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(val);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */