#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int n;
    cin>>n;
    ll pre,cur,sum=0;
    cin>>pre;
    for(int i=1;i<n;i++)
    {
        cin>>cur;
        if(pre>cur)
        {
            sum+=(pre-cur);
        }else
        {
            pre=cur;
        }
        
    }
    cout<<sum;
    return 0;
}