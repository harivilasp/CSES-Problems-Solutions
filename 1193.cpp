#include<bits/stdc++.h>
using namespace std;
#define ar array

char a[1001][1001];
string p[1001];
//char p[1001][1001];
int n,m;

bool e(int i, int j)
{
    return i>=0 && i<m && j<n && j>=0 && a[i][j]=='.';
}

int main()
{
    int c=0,si,sj,ti,tj,d[1001][1001];
    int di[]={1,0,-1,0};
    int dj[]={0,1,0,-1};
    char dc[]={'D','R','U','L'};
    cin>>m>>n;
    
    //char a[n][m];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
            if(a[i][j]=='B')
            {
                ti=i;
                tj=j;
                a[i][j]='.';
            }
            if(a[i][j]=='A')
            {
                si=i;
                sj=j;
                //a[i][j]='.';
            }
        }
        p[i]=string(n,0);
    }
    queue<ar<int,2>> qu;
    qu.push({si,sj});
    while(qu.size())
    {
        ar<int,2> u = qu.front();
        qu.pop();
        for(int k=0;k<4;k++)
        {
            int ni=u[0]+di[k],nj=u[1]+dj[k];
            if(!e(ni,nj))
            {
                continue;
            }
            qu.push({ni,nj});
            a[ni][nj]='#';
            d[ni][nj]=k;
            p[ni][nj]=dc[k];
        }
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<p[i][j]<<" ";
        }
        cout<<endl;
    }
    if(p[ti][tj])
    {
        cout<<"YES\n";
        string t;
        while(ti^si || tj^sj)
        {
            t+=p[ti][tj];
            int dd=d[ti][tj]^2; // extremly clever idea changes down to up etc.
            ti+=di[dd];
            tj+=dj[dd];
        }
        reverse(t.begin(),t.end());
        cout<<t.size()<<"\n";
        cout<<t;
    }else
    {
        cout<<"NO";
    }
    
    return 0;
}