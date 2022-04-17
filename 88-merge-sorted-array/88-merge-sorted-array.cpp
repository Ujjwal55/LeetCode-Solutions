class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // int i = 0, j = 0, k = 0;
        // if(n != 0){
        //     while(i != m){
        //         if(nums1[i] <= nums2[j]){
        //             nums1[k++] = nums1[i++];
        //         }
        //         else{
        //             swap(nums1[k], nums2[j]);
        //             k++;
        //             i++;
        //         }
        //     }
        //     while(j<n){
        //         nums1[k++] = nums2[j++];
        //     }
        // }
        
        int i = m - 1, j = n - 1, k = m + n - 1;
        while(i >= 0 && j >= 0){
            if(nums1[i] > nums2[j]){
                nums1[k--] = nums1[i--];
            }
            else{
                nums1[k--] = nums2[j--];
            }
        }
        while(j >= 0){
            nums1[k--] = nums2[j--];
        }
    }
};