class Solution {
public:
    int directPrice(vector<int>& price, vector<vector<int>>& special, vector<int>& needs){
        int ans = 0;
        int n = needs.size();
        for(int i = 0 ; i < n ; i++){
            ans += price[i] * needs[i];
        }
        return ans;
    }
    int minimumPrice(vector<int>& price, vector<vector<int>>& special, vector<int>& needs, int pos){
        int n = needs.size();
        int ans = directPrice(price, special, needs);
        
        for(int i = pos ; i < special.size() ; i++){
            vector<int> temp;
            for(int j = 0 ; j < n ; j++){
                if(special[i][j] > needs[j]){
                    temp.clear();
                    break;
                }
                temp.push_back(needs[j] - special[i][j]);
            }
            if(temp.size() > 0) 
                ans = min(ans, special[i][n] + minimumPrice(price, special, temp, i));
        }
        return ans;
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return minimumPrice(price, special, needs, 0);
    }
};