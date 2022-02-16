#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef double dl;

#define endl '\n'
#define PB push_back
#define F first
#define S second
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define sz(x) (int)x.size()

const long long infLL = 9000000000000000000;

const int mx = 512;
long long int dist[mx];
vector <pii> adj[mx];


void dijkstra(int s, int n)
{
    for(int i=0; i<n; i++)
    {
        dist[i] = infLL; // set all the dist is infinite
    }
    dist[s] = 0; // source distance 0
    priority_queue <pll, vll, greater<pll>> pq;
    pq.push({0, s});  // push the source and dist of source

    while (!pq.empty())
    {
        int u = pq.top().second;
        long long curDis = pq.top().first;
        pq.pop();

        if(dist[u]<curDis) continue; // dist jodi choto hoi tobe niche jabo na
        for(auto a : adj[u])
        {
            int v = a.first;
            long long w = a.second;
            long long Max = max(curDis, w);

            if(Max < dist[v])
            {
                dist[v] = Max;
                pq.push({dist[v], v});
            }
        }
    }
    
}


int main()
{
    int T;
    cin >> T;
    for(int c = 1; c<=T; c++)
    {
        int n, m;
        cin >> n >> m;
        for(int i=0; i<n; i++) adj[i].clear(); // clearing the graph to take input
        for(int i=1; i<=m; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({v, w}); // pusing the edge of u to v
            adj[v].push_back({u, w}); // pushing the edge of v to u
        }
        int nn;
        cin >> nn;

        dijkstra(nn, n);

        cout << "Case " << c << ":" << endl;
        for(int i=0; i<n; i++)
        {
            if(dist[i]== infLL) cout << "Impossible" << endl;
            else cout << dist[i] << endl;
        }
    }
    return 0;
}