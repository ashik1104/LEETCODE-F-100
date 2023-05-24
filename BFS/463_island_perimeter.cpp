class Solution {
public:
    int perimeter = 0;
    int visited[105][105];
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    bool is_outside(pair<int, int> coordinate, vector<vector<int>> &grid)
    {
        int x = coordinate.first;
        int y = coordinate.second;
        if(x < 0 or y < 0 or x >= grid.size() or y >= grid[0].size())
        {
            return true;
        }
        return false;
    }

    bool is_invalid(pair<int, int> coordinate, vector<vector<int>> &grid)
    {
        int x = coordinate.first;
        int y = coordinate.second;
        if(grid[x][y] == 0)
        {
            return true;
        }
        return false;
    }

    void BFS(pair<int, int> source, vector<vector<int>> grid)
    {
        queue<pair<int, int>> q;
        q.push(source);
        visited[source.first][source.second] = 1;

        while(!q.empty())
        {
            pair<int, int> head = q.front();
            q.pop();
            int x = head.first;
            int y = head.second;

            for(int i = 0; i < 4; i++)
            {
                int newx = x + dx[i];
                int newy = y + dy[i];
                if(is_outside({newx, newy}, grid) or is_invalid({newx, newy}, grid))
                {
                    perimeter += 1;
                }
                if(!is_outside({newx, newy}, grid) and !is_invalid({newx, newy}, grid) and visited[newx][newy] == 0)
                {
                    visited[newx][newy] = 1;
                    q.push({newx, newy});
                }
            }
        }
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        memset(visited, 0, sizeof(visited));
        pair<int, int> source;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[i].size(); j++)
            {
                if(grid[i][j] == 1)
                {
                    source = {i, j};
                    break;
                }
            }
        }
        BFS(source, grid);
        return perimeter;
    }
};