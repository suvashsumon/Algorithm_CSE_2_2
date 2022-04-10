#include<bits/stdc++.h>
using namespace std;
#define MX 5000
#define INF 100000000
struct node {
    int val;
    int cost;
};

bool vis[MX];
int dist[MX];
vector<node>G[MX];

void reset()
{
    for(int i=0; i<MX; i++)
    {
        G[i].clear();
        vis[i] = false;
        dist[i] = INF;
    }
}

class cmp {
public:
    bool operator()(node &A, node &B) {
        if(A.cost > B.cost) return true;
        return false;
    }
};

void dijkstra(int src)
{
    priority_queue<node, vector<node>, cmp>PQ;
    PQ.push({src, 0});

    while(!PQ.empty()) {
        node current = PQ.top();
        PQ.pop();

        int val = current.val;
        int cost = current.cost;

        if (vis[val]==true) continue;

        dist[val] = cost;
        vis[val] = true;

        for(int i=0; i<G[val].size(); i++)
        {
            int next = G[val][i].val;
            int nextCost = G[val][i].cost;

            if(vis[next]==false) {
                PQ.push({next, cost+nextCost});
            }
        }
    }
}

int main()
{
    reset();
    int nodes, edges;
    cin >> nodes >> edges;
    for(int i=1; i<=edges; i++)
    {
        int s, e, w;
        cin >> s >> e >> w;
        G[s].push_back({e, w});
    }

    dijkstra(4);
    for (int i = 1; i <= nodes; i++){
        cout << "Node: " << i << " Distance: ";
        if (dist[i] == INF) cout << "inf" << "\n";
        else cout << dist[i] << "\n";
    }
    return 0;
}