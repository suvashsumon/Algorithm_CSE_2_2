#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

const int MAXN = 1e5 + 3;
const int INF = INT_MAX;

vector<vector<ii>> adjList;
int n, dist[MAXN], par[MAXN];
bool isDone[MAXN];

bool dijkstra(int s, int t)
{
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    fill(dist, dist + n + 1, INF); // initializing all the distance to Infinite

    pq.push(ii(0, s)); // distance, node --- distance of source from source is 0
    dist[s] = 0; // distance 0
    par[s] = -1; // s has no parent

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        if (u == t)
            return true; // we find the destination node and return true means has a shortest path

        isDone[u] = true; // set u as visited

        for (auto pr : adjList[u])
        {
            int v = pr.first, w = pr.second;

            if (!isDone[v] && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w; // update dist of v
                pq.push(ii(dist[v], v)); // then push to piority queue
                par[v] = u; // update parent
            }
        }
    }

    return false; // that means there are no shortest path
}

int main()
{
    int m;
    cin >> n >> m;

    adjList.resize(n + 3);

    int u, v, w;

    while (m--)
    {
        cin >> u >> v >> w;
        adjList[u].push_back(ii(v, w));
        adjList[v].push_back(ii(u, w));
    }

    if (dijkstra(1, n))
    {
        vector<int> path;

        v = n;
        while(v!=-1)
            path.push_back(v), v=par[v];

        for (int i = path.size() - 1; i > 0; --i)
            printf("%d ", path[i]);

        printf("%d\n", path[0]);
    }
    else
        puts("-1");

    return 0;
}