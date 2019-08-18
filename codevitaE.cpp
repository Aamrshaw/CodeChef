#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main()
{
    int n,a[30],i,j,sum,mx=0;
    cin>>n;
    for(i=0;i<n;i++)
        scanf("%d,",&a[i]);
    sum=0;
    for(j=-1;j<n-1;)
    {
        if(a[j+1]<a[j+2] && j<n-2)
        {
            j+=2;
            sum+=2*a[j];
        }
        else
        {
            j++;
            sum+=a[j];
        }
    }
    mx=(mx<sum)?sum:mx;
    for(i=2;i<n;i++)
    {
        sum=0;
        for(j=-1;j<n-1;)
        {
            if(j+3==i)
            {
               j+=3;
               sum+=3*a[j];
            }
            else
            {
                if(a[j+1]<a[j+2] && j<n-2)
                {
                   j+=2;
                   sum+=2*a[j];
                }
                else
                {
                    j++;
                    sum+=a[j];
                }
            }
        }
        mx=(mx<sum)?sum:mx;
    }
    cout<<mx;
    return 0;
}
