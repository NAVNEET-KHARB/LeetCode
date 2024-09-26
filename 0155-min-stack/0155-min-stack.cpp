class MinStack {
    stack<long> st;
    long mini;
public:
    MinStack() {
        mini = INT_MAX;
    }

    void push(int val) {
        long value = val;
        if (st.empty()) {
            mini = value;
            st.push(value);
        } else {
            if(val<mini){
                st.push(2*value-mini);
                mini = value;
            }
            else{
                st.push(value);
            }
        }
    }

    void pop() {
        if (st.empty()) return;
        long el = st.top();
        st.pop();
        if(el<mini){
            mini = 2*mini-el;
        }
    }

    int top() {
        if (st.empty()) return -1;
        long el = st.top();
        if(el<mini) return mini;
        return el;
    }

    int getMin() {
        if (!st.empty()) {
            return mini;
        }
        return -1;
    }
};
