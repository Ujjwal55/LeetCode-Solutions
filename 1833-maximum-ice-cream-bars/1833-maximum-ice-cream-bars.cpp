class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int spent = 0;
        int bought = 0;
        for(int i = 0; i < costs.size(); i++){
            if(spent + costs[i] <= coins){
                spent += costs[i];
                bought++;
            }
            else{
                break;
            }
        }
        return bought;
    }
};