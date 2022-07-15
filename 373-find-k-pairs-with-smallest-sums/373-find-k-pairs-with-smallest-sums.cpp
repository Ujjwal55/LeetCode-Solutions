class Solution {
public:
    class cmp{
        public:
        bool operator()(pair<int, pair<int, int>> &p1, pair<int, pair<int, int>> &p2){
            return p1.first > p2.first;
        }
    };
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, cmp> pq;
        vector<vector<int>> ans;
        if(nums1.size() == 0 || nums2.size() == 0 || k <= 0) return ans;
        for(int i = 0 ; i < nums1.size() ; i++){
            pq.push({nums1[i]+nums2[0], {i, 0}});
        }
        
        while(k-- && !pq.empty()){
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();
            ans.push_back({nums1[i], nums2[j]});
            if(j != nums2.size()-1){
                pq.push({nums1[i]+nums2[j+1], {i, j+1}});
            }
        }
        return ans;
    }
};