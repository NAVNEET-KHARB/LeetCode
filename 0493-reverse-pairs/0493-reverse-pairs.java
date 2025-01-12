class Solution {
    int merge(int arr[], int left, int mid, int right){
        int size = right-left+1;
        int low = left;
        int high = mid+1;
        int[] temp = new int[size];
        int i = 0, cnt = 0;
        while(low <= mid && high <= right){
            if(arr[low] > 2 * (long)arr[high]){
                cnt += (mid - low + 1);
                high++;
            }
            else{
                low++;
            }
        }
        low = left;
        high = mid+1;
        while(low<=mid && high<=right){
            if(arr[low]<=arr[high]){
                temp[i++] = arr[low];
                low++;
            }else{
                temp[i++] = arr[high];
                high++;
            }
        }
        while(low<=mid){
            temp[i++] = arr[low];
            low++;
        }
        while(high<=right){
            temp[i++] = arr[high];
            high++;
        }
        for(int j = left; j<=right; j++){
            arr[j] = temp[j-left];
        }
        return cnt;
    }
    int mergeSort(int arr[], int left, int right){
        int cnt = 0;
        if(left>=right) return cnt;
        int mid = (left+right)/2;
        cnt += mergeSort(arr,left,mid);
        cnt += mergeSort(arr,mid+1,right);
        cnt += merge(arr,left,mid,right);
        return cnt;
    }
    public int reversePairs(int[] nums) {
        return mergeSort(nums,0,nums.length-1);
    }
}