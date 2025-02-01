class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int n1 = nums1.length, n2 = nums2.length;
        int i = 0, j = 0;
        int n = n1+n2;
        int ind = 0;
        int ind1 = (n/2)-1, ind2 = (n/2);
        int el1 = Integer.MIN_VALUE, el2 = Integer.MIN_VALUE;
        while(i<n1 && j<n2){
            if(nums1[i]<nums2[j]){
                if(ind == ind1) el1 = nums1[i];
                if(ind == ind2){
                    el2 = nums1[i];
                    break;
                }
                ind++;
                i++;
            }else{
                if(ind == ind1) el1 = nums2[j];
                if(ind == ind2){
                    el2 = nums2[j];
                    break;
                }
                ind++;
                j++;
            }
        }
        while(i<n1 && el2==Integer.MIN_VALUE){
            if(ind == ind1) el1 = nums1[i];
            if(ind == ind2){
                el2 = nums1[i];
                break;
            }
            ind++;
            i++;
        }
        while(j<n2 && el2==Integer.MIN_VALUE){
            if(ind == ind1) el1 = nums2[j];
            if(ind == ind2){
                el2 = nums2[j];
                break;
            }
            ind++;
            j++;
        }
        System.out.println(el1);
        System.out.println(el2);
        if(n%2 == 1) return el2;
        return (double)(el1+el2)/2.0;
    }
}