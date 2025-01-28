class Solution {
    public List<List<Integer>> findDifference(int[] nums1, int[] nums2) {
        List<List<Integer>> ans = new ArrayList<>();
        for(int i = 0; i<2; i++) ans.add(new ArrayList<>());
        HashSet<Integer> set1 = new HashSet<>();
        HashSet<Integer> set2 = new HashSet<>();
        for(int num : nums1) set1.add(num);
        for(int num : nums2) set2.add(num);
        for(int it : set1){
            if(!set2.contains(it)) ans.get(0).add(it);
        }
        for(int it : set2){
            if(!set1.contains(it)) ans.get(1).add(it);
        }
        return ans;
    }
}