#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,x;
    cin>>n;
    int a[n+1];
    memset(a,0,n);
    for(int i=0;i<n-1;i++)
    {
        cin>>x;
        a[x-1]=1;
    }
    int i=0;
    while(i<n && a[i]==1)
    {
        i++;
    }
    cout<<i+1;
    return 0;
}