#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int MA = 1e5;
vector<int> adj[MA];
int n,m, p[MA];
bool vis[MA], act[MA];

void dfs(int u)
{
    vis[u]=1;
    act[u]=1;
    for(int v : adj[u])
    {
        if(act[v])
        {
            vector<int> ans={u};
            //ans.push_back(ans[0]);
            while(u^v)
            {
                u = p[u];
                ans.push_back(u);
            }
            ans.push_back(ans[0]);
            reverse(ans.begin(),ans.end());
            cout<<ans.size()<<"\n";
            for(int a : ans)
                cout<<a+1<<" ";
            exit(0);
        }else
        {
            if(!vis[v])
            {
                p[v]=u;
                dfs(v);
            }

        }
        
    }
    act[u]=0;
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        ll a,b;
        cin>>a>>b , --a, --b;
        adj[a].push_back(b);
    }
    for(int i=0;i<n;i++)
        if(!vis[i])
            dfs(i);
    cout<<"IMPOSSIBLE";

    return 0;
}