class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int low = 0, high = n - 1;
        int amount = INT_MIN;
        while(low < high){
            amount = max(amount, min(height[low], height[high]) * (high - low));
            
            if(height[high] < height[low]) high--;
            else low++;
        }
        return amount;
    }
};