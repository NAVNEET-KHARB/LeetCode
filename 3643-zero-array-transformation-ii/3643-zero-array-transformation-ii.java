class Solution {
    public boolean solve(int[] nums, int[][] queries, int k){
        int n = nums.length, sum = 0;
        int[] diffArr = new int[n+1];
        for(int ind = 0; ind<k; ind++){
            int left = queries[ind][0], right = queries[ind][1], val = queries[ind][2];
            diffArr[left] += val;
            diffArr[right+1] -= val;
        }
        for(int i = 0; i<n; i++){
            sum += diffArr[i];
            if(sum<nums[i]) return false;
        }
        return true;
    }
    public int minZeroArray(int[] nums, int[][] queries) {
        int n = queries.length, left = 0, right = queries.length;
        if(!solve(nums,queries,right)) return -1;
        while(left<=right){
            int mid = (left+right)/2;
            if(solve(nums,queries,mid)) right = mid-1;
            else left = mid+1;
        }
        return left;
    }
}