class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<double> ans;
        multiset<long long, greater<long long>> max_heap;
        multiset<long long> min_heap;
        for(int i = 0 ; i < n ; i ++){
            if(i >= k){
                if(max_heap.find(nums[i-k]) != max_heap.end()){
                    max_heap.erase(max_heap.find(nums[i-k]));
                }
                else{
                    min_heap.erase(min_heap.find(nums[i-k]));
                }
            }
            if(max_heap.size() == 0 || *max_heap.begin() > nums[i]){
                max_heap.insert(nums[i]);
            }
            else{
                min_heap.insert(nums[i]);
            }
            if(max_heap.size() > min_heap.size() + 1){
                min_heap.insert(*max_heap.begin());
                max_heap.erase(max_heap.begin());
            }
            else if(max_heap.size() < min_heap.size()){
                max_heap.insert(*min_heap.begin());
                min_heap.erase(min_heap.begin());
            }
            if(i >= k-1){
                if(max_heap.size() == min_heap.size()){
                    ans.push_back((double)(*max_heap.begin() + *min_heap.begin())/2);
                }
                else{
                    ans.push_back(*max_heap.begin());
                }
            }
        }
        return ans;
    }
};