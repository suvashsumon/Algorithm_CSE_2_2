#include<bits/stdc++.h>
using namespace std;

int r;
int c;
char arr[1001][1001];
bool visited[1001][1001];
int sum[1001];

bool check(int x, int y)
{
    if(x<0 || x>r-1 || y<0 || y>c-1) return false;
    else if(arr[x][y]=='B') return false;
    else if(visited[x][y]) return false;
    else return true;
}

void dfs(int x, int y, int k)
{
    visited[x][y] = true;
    sum[k]++;
    if(check(x-1, y)) dfs(x-1, y, k);
    if(check(x, y-1)) dfs(x, y-1, k);
    if(check(x+1, y)) dfs(x+1, y, k);
    if(check(x,y+1)) dfs(x,y+1, k);
}

int main()
{
    cin >> r >> c;
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            cin >> arr[i][j];
        }
    }
    int ans = 0;
    int k = 0;
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            if(visited[i][j]==false && arr[i][j]=='W')
            {
                dfs(i, j, k);
                k++;
                ans++;
            }
        }
    }
    cout << "Total white grid : " << ans << endl;
    cout << "Number of pixels : ";
    for(int i=0; i<ans; i++) cout << sum[i] << " ";
    cout << endl;

}