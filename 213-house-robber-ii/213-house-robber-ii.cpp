class Solution {
public:
    int maxMoney(vector<int> &nums, int n, vector<int> &money){
        if(n <= 0) return 0;
        if(n == 1) return nums[n-1];
        if(money[n] != -1) return money[n];
        return money[n] = max(nums[n-1] + maxMoney(nums, n-2, money), maxMoney(nums, n-1, money)); 
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> money1(n, -1);
        vector<int> money2(n, -1);
        vector<int> nums1;
        vector<int> nums2;
        for(int i = 0 ; i < n ; i++){
            if(i != 0) nums1.push_back(nums[i]);
            if(i != n-1) nums2.push_back(nums[i]);
        }
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        return max(maxMoney(nums1, n-1, money1), maxMoney(nums2, n-1, money2));
    }
};