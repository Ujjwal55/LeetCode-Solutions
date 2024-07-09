class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int customerSize = customers.size();
        double ans = 0;
        int currTime = 0;
        
        for(auto it : customers) {
            int arrivalTime = it[0];
            int cookTime = it[1];
            
            if(currTime < arrivalTime) {
                currTime = arrivalTime;
            }
            
            int waitTime = currTime + cookTime - arrivalTime;
            
            ans += waitTime;
            currTime = currTime + cookTime;
        }
        
        return ans/customerSize;
    }
};