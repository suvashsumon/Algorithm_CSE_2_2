#include<bits/stdc++.h>
using namespace std;

#define MX 105

struct node {
    int val;
    int cost;

    bool operator<(const node& n) const
	{
		return (this->cost < n.cost);
	}
};

vector <node> G[MX];
bool vis[MX];
int dist[MX];

class cmp {
    public:
    bool operator() (node &A, node&B){
        if(A.cost > B.cost) return true;
        else return false;
    }
};

void dijkstra(int source)
{
    //priority_queue <node, vector<node>, cmp> PQ;
    //PQ.push({source, 0});

    set<struct node>PQ;



    while(!PQ.empty())
    {
        node current = PQ.top();
        PQ.pop();

        int val = current.val;
        int cost = current.cost;

        if(vis[val]==1) continue;

        dist[val] = cost; // final cost of this node
        vis[val] = 1;

        for(int i=0; i<G[val].size(); i++)
        {
            int nxt = G[val][i].val;
            int nxtCost = G[val][i].cost;

            if(vis[nxt] == 0)
            {
                PQ.push({nxt, cost + nxtCost});
            }
        }
    }
}


int main()
{
    int nodes, edges;
    cin >> nodes >> edges;

    for(int i=1; i<=edges; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({v, w});
    }

    //cout << "Enter source : ";
    int src;
    cin >> src;
    dijkstra(src);
    for(int i=1; i<=nodes; i++)
    {
        cout << i << " => " << dist[i] << endl;
    }
    return 0;
}