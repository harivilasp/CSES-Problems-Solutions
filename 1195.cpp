#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

// clever approach of 2 dijikstra

const int MA = 1e5;
int n,m;
vector<ar<ll,2>> adj1[MA],adj2[MA];
ll d1[MA],d2[MA];

void solve(int u, vector<ar<ll,2>> adj[MA], ll d[MA])
{
    memset(d, 0x3f, sizeof(d1));
    d[u]=0;
    priority_queue<ar<ll,2>, vector<ar<ll,2>>, greater<ar<ll,2>>> pq;
    pq.push({0,u});
    while(pq.size())
    {
        ar<ll,2> u =pq.top();
        pq.pop();
        if(u[0]>d[u[1]])
            continue;

        for(ar<ll,2> v : adj[u[1]])
        {
            if(d[v[1]]> u[0]+v[0])
            { 
                d[v[1]]=u[0]+v[0];
                pq.push({d[v[1]],v[1]});
            }
        }
    }
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c, --a,--b;
        adj1[a].push_back({c,b});
        adj2[b].push_back({c,a});
    }
    solve(0,adj1,d1);
    solve(n-1,adj2,d2);
    ll ans = 1e18;
    for(int i=0;i<n;i++)
    {
        for(ar<ll,2> j : adj1[i])
        ans=min(ans, d1[i]+d2[j[1]]+j[0]/2);
    }
    cout<<ans;
    return 0;
}
