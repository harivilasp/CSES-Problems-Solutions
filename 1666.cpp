#include<bits/stdc++.h>
using namespace std;

const int MA=1e5+1;
vector<int> adj[MA];
bool visit[MA];
void dfs(int u)
{
    visit[u]=1;
    for(int a:adj[u])
    {
        if(!visit[a])
        dfs(a);
    }
}
int main()
{
    int m,n,u,v;
    cin>>m>>n;
    for(int i=0;i<n;i++)
    {
        cin>>u>>v;
        --u;--v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> ans;
    for(int i=0;i<m;i++)
    {
        if(!visit[i])
        {
            ans.push_back(i);
            dfs(i);
        }
    }
    cout<<ans.size()-1<<"\n";
    for(int i=1;i<ans.size();i++)
    {
        cout<<ans[0]+1<<" "<<ans[i]+1<<"\n";
    }
    return 0;
}