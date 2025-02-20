class Solution {
    void func(int size, int n, String curr, String[] ans, HashSet<String> set){
        if(size == n){
            if(!set.contains(curr)) ans[0] = curr;
            return;
        }
        for(char c = '0'; c<='1'; c++){
            func(size+1,n,curr+c,ans,set);
            if(ans[0]!=null) return;
        }
    }
    public String findDifferentBinaryString(String[] nums) {
        HashSet<String> set = new HashSet<>();
        for(String num : nums) set.add(num);
        String curr = "";
        String[] ans = new String[1];
        int n = nums[0].length(), size = 0;
        func(size,n,curr,ans,set);
        return ans[0];
    }
}