class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;
        for (char currChar : expression) {
            if (currChar == ')') {
                vector<char> values;
                while (st.top() != '(') {
                    values.push_back(st.top());
                    st.pop();
                }
                st.pop();
                char op = st.top();
                st.pop();
                char result = evaluateSubExpr(op, values);
                st.push(result);
            } else if (currChar != ',') {
                st.push(currChar);
            }
        }
        return st.top() == 't';
    }

private:
    char evaluateSubExpr(char op, vector<char>& values) {
        if (op == '!') return values[0] == 't' ? 'f' : 't';
        if (op == '&') {
            for (char value : values) {
                if (value == 'f') return 'f';
            }
            return 't';
        }
        if (op == '|') {
            for (char value : values) {
                if (value == 't') return 't';
            }
            return 'f';
        }
        return 'f';
    }
};