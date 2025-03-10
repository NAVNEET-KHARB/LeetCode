class Solution {
    public int trap(int[] height) {
        int n = height.length;
        int leftMax = 0, rightMax = 0;
        int left = 0, right = n-1, ans = 0;
        while(left<right){
            if(height[left]<=height[right]){
                if(leftMax>height[left]) ans += leftMax-height[left];
                else leftMax = height[left];
                left++;
            }else{
                if(rightMax>height[right]) ans += rightMax-height[right];
                else rightMax = height[right];
                right--;
            }
        }
        return ans;
    }
}