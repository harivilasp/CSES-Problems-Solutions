#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array
// without dp time limit exceeded
const int MA = 1e5;
int n,m,ans=0;
vector<ll> adj[MA];
int dp[MA], p[MA];
//bool vis[MA],act[MA]; // act means active inside stack most probably

void dfs(int u)
{
    //vis[u]=1;
    if(u==n-1)
        ans++;
    for(int v : adj[u])
    {
        //if(!vis[v]){
            //p[v]=u;
            dfs(v);
        //}
    }
    //act[u]=0;
    //ans.push_back(u);
}

int main()
{
    cin>>n>>m;
    //for(int i=0;i<n;i++)
    //    vis[i]=0;
    for(int i=0;i<m;i++)
    {
        ll a,b;
        cin>>a>>b, --a,--b;
        adj[a].push_back(b);
    }
    dfs(0);
    cout<<ans;
    return 0;
}
