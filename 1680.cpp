#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array
// DP on Graphs

const int MA = 1e5;
int n,m;
vector<ll> adj[MA],ans;
int dp[MA], p[MA];
bool vis[MA],act[MA]; // act means active inside stack most probably

void dfs(int u)
{
    dp[u]=u==n-1?1:-1e9;
    vis[u]=1;
    act[u]=1;
    for(int v : adj[u])
    {
        if(act[v]){
            cout<<"IMPOSSIBLE";
            exit(0);
        }else{
            if(!vis[v]){
                p[v]=u;
                dfs(v);
            }
        }

        if(dp[v]+1>dp[u])
            p[u]=v, dp[u]=dp[v]+1;
    }
    act[u]=0;
    //ans.push_back(u);
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        ll a,b;
        cin>>a>>b, --a,--b;
        adj[a].push_back(b);
    }
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
            dfs(i);
    }
    if(dp[0]<0)
    cout<<"IMPOSSIBLE";
    else
    {
        ans.push_back(0);
        int u=0;
        while(u^n-1)
        {
            u=p[u];
            ans.push_back(u);
        }
        cout<<ans.size()<<"\n";
        for(int a : ans)
            cout<<a+1<<" ";
    }
    return 0;
}
