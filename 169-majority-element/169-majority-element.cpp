class Solution {
public:
//     int majorityElement(vector<int>& nums) {
//         int n = nums.size();
//         int num = nums[0], cnt = 1;
        
//         for(int i = 0 ; i < n ; i++){
//             if(num == nums[i]) cnt++;
//             else cnt--;
//             if(cnt == 0){
//                 num = nums[i];
//                 cnt++;
//             }
//         }
        
// //         cnt = 0;
// //         for(int i = 0 ; i < n ; i++){
// //             if(nums[i] == num) cnt++;
// //         }
        
//         return num;
        
//     }
    
    int majorityElement(vector<int> &nums){
        int n = nums.size();
        int candidate = 0;
        
        for(int i = 0 ; i < 32 ; i++){
            int ones = 0;
            for(int j = 0 ; j < n ; j++){
                if(nums[j] & (1 << i)) ones++;
            }
            if(ones > n/2) candidate += (1 << i);
        }
        
        return candidate;
    }
};