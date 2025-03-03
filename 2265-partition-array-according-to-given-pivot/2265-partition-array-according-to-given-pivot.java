class Solution {
    public int[] pivotArray(int[] nums, int pivot) {
        int n = nums.length;
        int[] ans = new int[n];
        int i1 = 0, i2 = n-1;
        for(int i = 0, j = n-1; i<n; i++,j--){
            if(nums[i]<pivot) ans[i1++] = nums[i];
            if(nums[j]>pivot) ans[i2--] = nums[j];
        }
        while(i1<=i2) ans[i1++] = pivot;
        return ans;
    }
}