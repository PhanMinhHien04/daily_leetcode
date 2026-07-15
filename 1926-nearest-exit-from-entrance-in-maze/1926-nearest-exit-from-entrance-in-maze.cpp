class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();

        queue<pair<int,int>> q;
        q.push({entrance[0], entrance[1]});

        maze[entrance[0]][entrance[1]] = '+';

        int steps = 0;

        vector<pair<int,int>> directions = {
            {1,0}, {-1,0}, {0,1}, {0,-1}
        };

        while(!q.empty()) {

            int size = q.size();
            steps++;

            for(int i = 0; i < size; i++) {
                auto [row, col] = q.front();
                q.pop();

                for(auto &dir : directions) {
                    int newRow = row + dir.first;
                    int newCol = col + dir.second;

                    if(newRow >= 0 && newRow < n &&
                       newCol >= 0 && newCol < m &&
                       maze[newRow][newCol] == '.') {

                        if(newRow == 0 || newRow == n-1 ||
                           newCol == 0 || newCol == m-1) {
                            return steps;
                        }

                        maze[newRow][newCol] = '+';
                        q.push({newRow, newCol});
                    }
                }
            }
        }

        return -1;
    }
};