class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        int n1 = nums1.length;
        int n2 = nums2.length;
        int i = 0,j = 0, last = -1;
        ArrayList<Integer> temp = new ArrayList<>();
        Arrays.sort(nums1);
        Arrays.sort(nums2);
        while(i<n1 && j<n2){
            if(nums1[i]<nums2[j]) i++;
            else if(nums1[i]>nums2[j]) j++;
            else{
                if(temp.size() == 0 || last!=nums1[i]) temp.add(nums1[i]);
                last = nums1[i];
                i++;
                j++;
            }
        }
        int[] ans = new int[temp.size()];
        for(int a = 0; a<temp.size(); a++){
            ans[a] = temp.get(a);
        }
        return ans;
    }
}