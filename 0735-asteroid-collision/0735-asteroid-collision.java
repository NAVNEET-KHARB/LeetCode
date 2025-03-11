class Solution {
    public int[] asteroidCollision(int[] asteroids) {
        int n = asteroids.length;
        Stack<Integer> st = new Stack<>();
        for(int i = 0; i<n; i++){
            if(asteroids[i]>0) st.push(asteroids[i]);
            else{
                while(!st.isEmpty() && st.peek()>0 && st.peek()<-asteroids[i]) st.pop();
                if(st.isEmpty() || st.peek()<0) st.push(asteroids[i]);
                if(!st.isEmpty() && st.peek() == -asteroids[i]) st.pop();
            }
        }
        int m = st.size();
        int[] ans = new int[m];
        for(int i = m-1; i>=0; i--){
            ans[i] = st.pop();
        }
        return ans;
    }
}