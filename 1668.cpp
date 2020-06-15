#include<bits/stdc++.h>
using namespace std;
// bipartie graph code
const int MA=1e5+1;
int vis[MA];
vector<int> adj[MA],ans;
int n,m, c[MA];
// int p[MA];
void dfs(int u, int cu=0)
{
    if(~c[u])
    {
        if(c[u]^cu)
        {
            cout<<"IMPOSSIBLE";
            exit(0);
        }
        return ;
    }
    c[u]=cu;
    for(int v: adj[u])
    {
        dfs(v,cu^1);
    }
}
int main()
{
    int m,n,u,v;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>u>>v;
        --u;--v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    memset(c,-1,4*n);
    for(int i=0;i<n;i++)
    {
        if(c[i]<0)
        {
            dfs(i);
        }
    }
    
    for(int i=0;i<n;i++)
    cout<<c[i]+1<<" ";

    return 0;
}