class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        for(auto it: nums1){
            m[it]++;
        }
        unordered_map<int, int> t;
        for(auto it: nums2){
            if(m.find(it) != m.end()){
                t[it]++;
            }
        }
        vector<int> ans;
        for(auto it: t){
            ans.push_back(it.first);
        }
        return ans;
    }
};