class Solution {
    public int[] finalPrices(int[] prices) {
        int n = prices.length;
        int[] discPrices = new int[n];
        Stack<Integer> st = new Stack<>();
        for(int i = n-1; i>=0; i--){
            while(!st.isEmpty() && prices[i]<st.peek()) st.pop();
            if(st.isEmpty()) discPrices[i] = prices[i];
            else discPrices[i] = prices[i] - st.peek();
            st.push(prices[i]);
        }
        return discPrices;
    }
}