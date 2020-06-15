#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int co=1,i=1,ma=1;;
    while(s[i])
    {
        if(s[i]==s[i-1])
        {
            co++;
            if(ma<co)
            ma=co;
        }else
        {
            co=1;
        }
        i++;
    }
    if(s.length())
    cout<<ma;
    else cout<<"0";
    return 0;
}