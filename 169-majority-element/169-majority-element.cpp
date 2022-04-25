class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int num = nums[0], cnt = 1;
        
        for(int i = 0 ; i < n ; i++){
            if(num == nums[i]) cnt++;
            else cnt--;
            if(cnt == 0){
                num = nums[i];
                cnt++;
            }
        }
        
//         cnt = 0;
//         for(int i = 0 ; i < n ; i++){
//             if(nums[i] == num) cnt++;
//         }
        
        return num;
        
    }
};