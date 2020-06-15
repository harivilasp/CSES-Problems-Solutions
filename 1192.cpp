#include<bits/stdc++.h>
using namespace std;

char a[1001][1001];
void dfs(int i,int j,int n, int m)
{
    if(i>=n || i<0 || j<0 || j>=m || a[i][j]=='#')
    return ;
    if(a[i][j]=='.')
    {
        a[i][j]='#';
        int b[] = {0,-1,1};
        //dfs(i,j+1,n,m);
        for(int s=0;s<3;s++)
        {
            for(int d=0;d<3;d++)
            {
                if(s==0 || d==0)
                dfs(i+b[s],j+b[d],n,m);
            }
        }
    }
    return ;
}
int main()
{
    int n,m,c=0;
    cin>>n>>m;
    //char a[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i][j]=='.')
            {
                c++;
                dfs(i,j,n,m);
            }
        }
    }
    cout<<c;
    return 0;
}