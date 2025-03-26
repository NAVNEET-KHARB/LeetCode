class Solution {
    public void generate(int ind, int[] nums, List<Integer> subSet, List<List<Integer>> powerSet){
        if(ind == nums.length){
            powerSet.add(new ArrayList<>(subSet));
            return;
        }
        subSet.add(nums[ind]);
        generate(ind+1,nums,subSet,powerSet);
        subSet.remove(subSet.size()-1);
        generate(ind+1,nums,subSet,powerSet);
    }
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> powerSet = new ArrayList<>();
        List<Integer> subSet = new ArrayList<>();
        generate(0,nums,subSet,powerSet);
        return powerSet;
    }
}