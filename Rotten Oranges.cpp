class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<int> dx = {1,-1,0,0};
        vector<int> dy = {0,0,1,-1};

        int n = grid.size();
        int noOfMinutes = -1;

        queue<pair<int,int>> q;
        vector<vector<int>> visited = grid;
        int cntOfOranges = 0;

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(visited[i][j]==1){
                    cntOfOranges++;
                }
                if(visited[i][j]==2){
                    q.push({i,j});
                }
            }
        }


        if(cntOfOranges==0){
            return 0;
        }

        if(q.size()==0){
            return -1;
        }

        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto curr = q.front();
                int i = curr.first;
                int j = curr.second;

                q.pop();
              
                for(int l =0;l<4;l++){               
                      if( dx[l]+i>=0 && dy[l]+j>=0 && dx[l]+i<grid.size() && dy[l]+j<grid[0].size() && visited[dx[l]+i][dy[l]+j]==1){
                        q.push({dx[l]+i,dy[l]+j});
                        visited[dx[l]+i][dy[l]+j]=2;
                        cntOfOranges--;
                      }                
                }
            }
            noOfMinutes++;
        }

        if(cntOfOranges==0){
            return noOfMinutes;
        }

        return -1;
    }
};
