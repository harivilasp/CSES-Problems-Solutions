#include<bits/stdc++.h>
using namespace std;

const int MA=1e5+1;
vector<int> adj[MA];
int p[MA];
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
    memset(p,-1,4*m);
    queue<int> qu;
    qu.push(0);
    p[0]=-2;
    while(qu.size())
    {
        int u=qu.front();
        //visit[a]=1;
        qu.pop();
        for(int v:adj[u])
        {
            if(p[v]<0)
            {
                p[v]=u; // p array stores array
                qu.push(v);
            }
        }
        
    }
    vector<int> ans;
    if(p[m-1]<0)
    {
        cout<<"IMPOSSIBLE";
    }else
    {
        int u = m-1;
        while(u)
        {
            ans.push_back(u);
            u=p[u]; // p array stores parrent
            //cout<<"te";
        }
        ans.push_back(0);
        reverse(ans.begin(),ans.end());
        cout<<ans.size()<<"\n";
        for(int a : ans)
        {
            cout<<a+1<<" ";
        }
        
    }
    
    return 0;
}