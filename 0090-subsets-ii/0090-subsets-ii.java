class Solution {
    public void func(int ind, int n, int[] nums, List<Integer> curr, List<List<Integer>> ans){
        ans.add(new ArrayList<>(curr));
        for(int i = ind; i<n; i++){
            if(i>ind && nums[i] == nums[i-1]) continue;
            curr.add(nums[i]);
            func(i+1,n,nums,curr,ans);
            curr.remove(curr.size()-1);
        }
    }
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        int n = nums.length;
        Arrays.sort(nums);
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> curr = new ArrayList<>();
        func(0,n,nums,curr,ans);
        return ans;
    }
}