class Solution {
public:
    void bfs(vector<vector<char>>& grid,vector<vector<int>>& visited,int i,int j){
        queue<pair<int,int>> q;
        int n = grid.size();
        int m = grid[0].size();

       vector<int> dx = {1,-1,0,0};
       vector<int> dy = {0,0,1,-1};


    //    (1,0),(0,1),(-1,0),(0,-1)

        q.push({i,j});
        visited[i][j] = 1;
       
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            int i = front.first;
            int j = front.second;
                for(int k=0;k<4;k++){
                    int new_i= i+dx[k];
                    int new_j = j+dy[k];
                    if(new_i<n && new_i>=0 && new_j<m && new_j>=0 && 
                       grid[new_i][new_j]=='1' && !visited[new_i][new_j]
                    ){
                        visited[new_i][new_j] = 1;
                        q.push({new_i,new_j});
                    }
                }
        }
    }


    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(n==0 || m==0){
            return 0;
        }

        int cntIslands = 0;
        vector<vector<int>> visited(n,vector<int>(m,0));
       
       for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    cntIslands++;
                    bfs(grid,visited,i,j);
                }
           }
       }
 
        return cntIslands;
    }
};
