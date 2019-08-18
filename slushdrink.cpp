#include<iostream>
#include<algorithm>
#include<math.h>
#include<bits/stdc++.h>
#define lli long long int

using namespace std;

int main()
{
    lli t, n,m,i,j;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        lli c[m],d[n],f[n],b[n],a[n]={0};
        for(i=0;i<m;i++)
            cin>>c[i];
        lli sum=0;
        for(i=0;i<n;i++)
        {
            cin>>d[i]>>f[i]>>b[i];
            if(c[d[i]-1]!=0)
            {
                sum+=f[i];
                c[d[i]-1]--;
                a[i]=d[i];
            }
            else
            {
                sum+=b[i];
            }
        }
        cout<<sum<<endl;
        sort(c,c+m);
        for(i=0;i<m;i++)
            cout<<c[i]<<" ";
        cout<<endl;
        j=m-1;
        for(i=0;i<n;i++)
        {
            if(a[i]==0)
            {
                if(c[j]!=0)
                {
                    a[i]=c[j];
                    c[j]--;
                }
                else
                {
                    j--;
                    a[i]=c[j];
                    c[j]--;
                }
            }
        }
        for(i=0;i<n;i++)
            cout<<a[i]<<" ";
        cout<<endl;
    }
}
