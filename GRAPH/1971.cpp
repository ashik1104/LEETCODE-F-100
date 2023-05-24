// Using DFS : my approach

class Solution {
public:
    vector<int> adj_list[200005];
    vector<int> visited = vector<int> (200005, 0);

    void DFS(int source)
    {
        visited[source] = 1;
        for(auto adj_node : adj_list[source])
        {
            if(visited[adj_node] == 0)
            {
                DFS(adj_node);
            }
        }
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(n == 1 and source == destination)
        {
            return true;
        }
        for(auto v : edges)
        {
            adj_list[v[0]].push_back(v[1]);
            adj_list[v[1]].push_back(v[0]);
        }
        DFS(source);
        return visited[destination] == 1 ? true : false;
    }
};