class Solution {
public:
    
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        vector<int> dx = {1,-1,0,0};
        vector<int> dy = {0,0,1,-1};

        int ex = entrance[0];
        int ey = entrance[1];

        int n = maze.size();
        int m = maze[0].size();

        queue<pair<int,int>> q;

        q.push({ex,ey});

        int level=0;

        maze[ex][ey] = '+';

        while(!q.empty()){
            int size = q.size();
            
            while(size--){
                auto curr = q.front();
                int i = curr.first;
                int j = curr.second;
                q.pop();

                if(!(i==ex && j==ey) && (i==0 || j==0 || i==n-1 || j==m-1)){
                    return level;
                } 

                for(int k=0;k<4;k++){
                    int new_i = i+dx[k];
                    int new_j = j+dy[k];
                    if(new_i>=0 && new_j>=0 && new_i<n && new_j<m && maze[new_i][new_j]!='+'){
                        maze[new_i][new_j]='+';
                        q.push({new_i,new_j});
                    }
                }
            }

            level++;
        }

        return -1;

    }
};
