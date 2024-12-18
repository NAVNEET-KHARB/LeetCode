class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> st;
        for (int i = prices.size() - 1; i >= 0; i--) {
            while (!st.empty() && st.top() > prices[i]) {
                st.pop();
            }
            int ele = prices[i];
            if (!st.empty()) prices[i] = prices[i]-st.top();
            st.push(ele);
        }
        return prices;
    }
};