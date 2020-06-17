#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

int n,m;
const int MA=1e5;
vector<int> adj[MA],ans;
int out[MA],vis[MA];

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        out[i]=0;
        vis[i]=0;
    }
    
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b, --a,--b;
        adj[b].push_back(a);
        out[a]++;
    }
    //priority_queue<ar<int,2>, vector<ar<int,2>>, greater<ar<int,2>>> pq;
    bool st=true;
    while(st)
    {
        st=false;
        for(int i=0;i<n;i++)
        {
            if(!vis[i]&&!out[i])
            {
                vis[i]=1;
                ans.push_back(i+1);
                out[i]--;
                for(int a: adj[i])
                out[a]--;
                st=true;
            }
        }
    }
    if(ans.size()==n)
    {
        reverse(ans.begin(),ans.end());
        for(int a:ans)
            cout<<a<<" ";
    }else
    {
        cout<<"IMPOSSIBLE";
    }
    
    return 0;
}