class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        int n = temperatures.length;
        Stack<Integer> st = new Stack<>();
        int[] ans = new int[n];
        for(int i = n-1; i>=0; i--){
            while(!st.isEmpty() && temperatures[st.peek()]<=temperatures[i]) st.pop();
            ans[i] = st.isEmpty()?0:st.peek()-i;
            st.push(i);
        }
        return ans;
    }
}