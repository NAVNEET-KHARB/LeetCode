class Solution {
    public int[] sortedSquares(int[] nums) {
        int n = nums.length;
        int[] ans = new int[n];
        int left = 0, right = n-1, ind = n-1;
        while(left<=right){
            if(Math.abs(nums[left])<Math.abs(nums[right])){
                ans[ind--] = (nums[right]*nums[right]);
                right--;
            }else{
                ans[ind--] = (nums[left]*nums[left]);
                left++;
            }
        }
        return ans;
    }
}