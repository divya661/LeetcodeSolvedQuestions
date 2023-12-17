class Solution {
public:
   typedef long long LL;

    LL calculateDistance(vector<int> &bomb1, vector<int> &bomb2){
        LL distance = 
            ((bomb1[0]-bomb2[0])*1LL)*((bomb1[0]-bomb2[0])*1LL)
            +((bomb1[1]-bomb2[1])*1LL)*((bomb1[1]-bomb2[1])*1LL)
            ;
        return distance;
    }

     void dfs(int v, unordered_set<int>& visited, 
     unordered_map<int,vector<int>>& adj){
            visited.insert(v);
         for(auto &u:adj[v]){
             if(visited.find(u)==visited.end()){
                dfs(u, visited, adj);
             }
         }
     }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        unordered_map<int, vector<int>> adj;


        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){

                if(i==j) continue;
                LL distance = calculateDistance(bombs[i],bombs[j]);
                
                if(distance<=(LL)bombs[i][2]*bombs[i][2]){
                    adj[i].push_back(j);
                }
            }
        }

        int globalCount =0;
        
        for(int i=0;i<n;i++){
           unordered_set<int> visited;
            dfs(i,visited, adj);
           int result = visited.size();
           globalCount = max(result, globalCount);
        }

        return globalCount;
    }
};