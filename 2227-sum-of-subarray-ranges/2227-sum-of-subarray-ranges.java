class Solution {
    public long sumSubMax(int[] nums){
        int n = nums.length;
        int[] pge = new int[n], nge = new int[n];
        Stack<Integer> st = new Stack<>();
        for(int i = 0; i<n; i++){
            while(!st.isEmpty() && nums[st.peek()]<nums[i]) st.pop();
            pge[i] = st.isEmpty()?-1:st.peek();
            st.push(i);
        }
        st = new Stack<>();
        for(int i = n-1; i>=0; i--){
            while(!st.isEmpty() && nums[st.peek()]<=nums[i]) st.pop();
            nge[i] = st.isEmpty()?n:st.peek();
            st.push(i);
        }
        long subMax = 0;
        for(int i = 0; i<n; i++){
            int left = i-pge[i];
            int right = nge[i]-i;
            subMax += (long)left*right*nums[i];
        }
        return subMax;
    }
    public long sumSubMin(int[] nums){
        int n = nums.length;
        int[] pse = new int[n], nse = new int[n];
        Stack<Integer> st = new Stack<>();
        for(int i = 0; i<n; i++){
            while(!st.isEmpty() && nums[st.peek()]>nums[i]) st.pop();
            pse[i] = st.isEmpty()?-1:st.peek();
            st.push(i);
        }
        st = new Stack<>();
        for(int i = n-1; i>=0; i--){
            while(!st.isEmpty() && nums[st.peek()]>=nums[i]) st.pop();
            nse[i] = st.isEmpty()?n:st.peek();
            st.push(i);
        }
        long subMin = 0;
        for(int i = 0; i<n; i++){
            int left = i-pse[i];
            int right = nse[i]-i;
            subMin += (long)left*right*nums[i];
        }
        return subMin;
    }
    public long subArrayRanges(int[] nums) {
        long subMax = sumSubMax(nums);
        long subMin = sumSubMin(nums);
        return subMax-subMin;
    }
}