class Solution {
    public int countLargestGroup(int n) {
        HashMap<Integer,Integer> mpp = new HashMap<>();
        int maxDigits = 0;
        for(int i = 1; i<=n; i++){
            int num = i, digitSum = 0;
            while(num>0){
                digitSum += num%10;
                num /= 10;
            }
            mpp.put(digitSum,mpp.getOrDefault(digitSum,0)+1);
            maxDigits = Math.max(maxDigits,mpp.get(digitSum));
        }
        int ans = 0;
        for(int val : mpp.values()){
            if(val == maxDigits) ans++;
        }
        return ans;
    }
}