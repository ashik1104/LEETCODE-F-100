class Solution {
public:
    vector<pair<int, int>> adj_list[101];
    vector<int> d;
    vector<int> visited;

    void Dijkstra(int source)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
        pq.push({0, source});
        d[source] = 0;

        while(!pq.empty())
        {
            pair<int, int> head = pq.top();
            pq.pop();
            int s_node = head.second;
            if(visited[s_node] == 1)
            {
                continue;
            }
            visited[s_node] = 1;
            for(auto paired : adj_list[s_node])
            {
                int adj_node = paired.first;
                int w = paired.second;
                if((d[s_node] + w) < d[adj_node])
                {
                    d[adj_node] = d[s_node] + w;
                    pq.push({d[adj_node], adj_node});
                }
            }
        }
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        for(int i = 0; i <= 101; i++)
        {
            d.push_back(1e9);
        }
        for(int i = 0; i <= 101; i++)
        {
            visited.push_back(0);
        }
        for(int i = 0; i < times.size(); i++)
        {
            adj_list[times[i][0]].push_back({times[i][1], times[i][2]});
        }

        Dijkstra(k);

        for(int i = 1; i <= n; i++)
        {
            if(d[i] == 1e9)
            {
                return -1;
            }
        }

        int ans = 0;
        for(int i = 1; i <= n; i++)
        {
            if(d[i] > ans)
            {
                ans = d[i];
            }
        }
        
        return ans;
    }
};