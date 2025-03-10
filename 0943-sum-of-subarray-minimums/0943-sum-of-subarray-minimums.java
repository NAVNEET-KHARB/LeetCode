class Solution {
    public int sumSubarrayMins(int[] arr) {
        int n = arr.length;
        int[] nse = new int[n], pse = new int[n];
        int mod = 1000000007;
        long ans = 0;
        Stack<Integer> st = new Stack<>();
        for(int i = 0; i<n; i++){
            while(!st.isEmpty() && arr[st.peek()]>arr[i]) st.pop();
            if(st.isEmpty()) pse[i] = -1;
            else pse[i] = st.peek();
            st.push(i);
        }
        st = new Stack<>();
        for(int i = n-1; i>=0; i--){
            while(!st.isEmpty() && arr[st.peek()]>=arr[i]) st.pop();
            if(st.isEmpty()) nse[i] = n;
            else nse[i] = st.peek();
            st.push(i);
        }
        for(int i = 0; i<n; i++){
            int left = i-pse[i];
            int right = nse[i]-i;
            ans = (ans + ((long) left * right * arr[i]) % mod) % mod;
        }
        return (int)ans;
    }
}