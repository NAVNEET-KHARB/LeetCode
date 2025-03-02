class Solution {
    public int[][] mergeArrays(int[][] nums1, int[][] nums2) {
        int n = nums1.length, m = nums2.length;
        ArrayList<int[]> arr = new ArrayList<>();
        int i = 0, j = 0;
        while(i<n && j<m){
            if(nums1[i][0] == nums2[j][0]){
                int[] num = new int[2];
                num[0] = nums1[i][0];
                num[1] = nums1[i][1] + nums2[j][1];
                arr.add(num);
                i++;
                j++;
            }else if(nums1[i][0]>nums2[j][0]){
                int[] num = new int[2];
                num[0] = nums2[j][0];
                num[1] = nums2[j][1];
                arr.add(num);
                j++;
            }else{
                int[] num = new int[2];
                num[0] = nums1[i][0];
                num[1] = nums1[i][1];
                arr.add(num);
                i++;
            }
        }
        while(i<n){
            int[] num = new int[2];
            num[0] = nums1[i][0];
            num[1] = nums1[i][1];
            arr.add(num);
            i++;
        }
        while(j<m){
            int[] num = new int[2];
            num[0] = nums2[j][0];
            num[1] = nums2[j][1];
            arr.add(num);
            j++;
        }
        int sz = arr.size();
        int[][] ans = new int[sz][2];
        int s = 0;
        for(int[] num : arr){
            ans[s] = num;
            s++;
        }
        return ans;
    }
}