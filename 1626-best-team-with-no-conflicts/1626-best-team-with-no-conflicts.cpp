class Solution {
public:
    int bestScore(vector<vector<int>> &temp, int i, int maxAge, vector<vector<int>> &dp){
        if(i >= temp.size()){
            return 0;
        }
        if(dp[i][maxAge] != -1) return dp[i][maxAge];
        if(temp[i][1] >= maxAge){
            return dp[i][maxAge] = max(temp[i][0] + bestScore(temp, i+1, temp[i][1], dp), bestScore(temp, i+1, maxAge, dp));
        }
        else{
            return dp[i][maxAge] = bestScore(temp, i+1, maxAge, dp);
        }
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<vector<int>> temp;
        for(int i = 0 ; i < scores.size() ; i++){
            temp.push_back({scores[i], ages[i]});
        }
        vector<vector<int>> dp(1001, vector<int> (1001, -1));
        sort(temp.begin(), temp.end());
        return bestScore(temp, 0, 0, dp);
    }
};