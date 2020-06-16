#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

int n,m;
const int MA=2.5e3;
vector<ar<ll,2>> adj[MA];

int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c, --a,--b;
        adj[a].push_back({c,b});
    }
    return 0;
}