class Solution {
public:
    int trap(vector<int>& height) {
        int lo = 0, hi = height.size()-1;
        int left_max = 0, right_max = 0, ans = 0;
        while(lo <= hi){
            if(height[lo] <= height[hi]){
                if(height[lo] >= left_max) left_max = height[lo];
                else ans+=left_max-height[lo];
                lo++;
            }
            else{
                if(height[hi] >= right_max) right_max = height[hi];
                else ans+=right_max-height[hi];
                hi--;
            }
        }
        return ans;
    }
};