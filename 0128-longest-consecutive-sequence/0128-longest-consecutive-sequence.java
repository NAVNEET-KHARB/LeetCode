class Solution {
    public int longestConsecutive(int[] nums) {
        HashSet<Integer> uniEl = new HashSet<>();
        int longest = 0;
        for(int num : nums){
            uniEl.add(num);
        }
        for(Integer it : uniEl){
            if(!uniEl.contains(it-1)){
                int num = it;
                int cnt = 1;
                while(uniEl.contains(num+1)){
                    num++;
                    cnt++;
                }
                longest = Math.max(cnt,longest);
            }
        }
        return longest;
    }
}