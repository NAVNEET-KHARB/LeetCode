class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        Stack<Integer> st = new Stack<>();
        HashMap<Integer,Integer> mpp = new HashMap<>();
        for(int i = nums2.length-1; i>=0; i--){
            while(!st.isEmpty() && st.peek()<=nums2[i]) st.pop();
            if(st.isEmpty()) mpp.put(nums2[i],-1);
            else mpp.put(nums2[i],st.peek());
            st.push(nums2[i]);
        }
        int len = nums1.length;
        int[] ans = new int[len];
        for(int i = 0; i<len; i++){
            ans[i] = mpp.get(nums1[i]);
        }
        return ans;
    }
}