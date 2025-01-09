class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        HashSet<List<Integer>> ansSet = new HashSet<>();
        int n = nums.length;
        for(int i = 0; i<n; i++){
            HashSet<Integer> hash = new HashSet<>();
            for(int j = i+1; j<n; j++){
                int third = -(nums[i]+nums[j]);
                if(hash.contains(third)){
                    List<Integer> temp = new ArrayList<>(Arrays.asList(nums[i],nums[j],third));
                    Collections.sort(temp);
                    ansSet.add(temp);
                }
                hash.add(nums[j]);
            }
        }
        List<List<Integer>> ans = new ArrayList<>();
        for(List<Integer> set : ansSet){
            ans.add(set);
        }
        return ans;
    }
}