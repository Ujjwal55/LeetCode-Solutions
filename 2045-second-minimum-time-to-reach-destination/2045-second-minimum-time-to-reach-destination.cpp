class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>>graph(n+1);
        for(auto & edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        pq.push({0,1});
        vector<int>minTime(n+1, INT_MAX);
        vector<int>secondMinTime(n+1, INT_MAX);
        minTime[1]=0;

        while(!pq.empty()){
            auto[curTime, u]=pq.top();
            pq.pop();

            for(int v: graph[u]){
                int newTime=curTime;
                int cycle=(curTime/change)%2;
                if(cycle==1){
                    newTime +=change-(curTime%change);
                }
                newTime +=time;

                if(newTime < minTime[v]){
                    secondMinTime[v]=minTime[v];
                    minTime[v]=newTime;
                    pq.push({newTime,v});
                }else if(newTime > minTime[v] && newTime < secondMinTime[v]){
                    secondMinTime[v]=newTime;
                    pq.push({newTime,v});
                }
            }
        }
        return secondMinTime[n];
        
    }
};