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

     int bfs(int u,unordered_map<int,vector<int>>& adj){
         unordered_set<int> visited;
         queue<int> q;
          q.push(u);

            visited.insert(u);
         while(!q.empty()){
             int top = q.front();
             q.pop();
             for(auto &v: adj[top]){
                 if(visited.find(v)==visited.end()){
                     visited.insert(v);
                     q.push(v);
                 }
             }
         }

         return visited.size();
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
            int result = bfs(i, adj);
           globalCount = max(result, globalCount);
        }

        return globalCount;
    }
};