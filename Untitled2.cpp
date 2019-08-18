#include<iostream>
#include<algorithm>
#include<math.h>
#include<bits/stdc++.h>
#define lli long long int

using namespace std;
lli p=1000000007;
lli modpower(lli x, lli y)
{
    int res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}

int main()
{
    lli n,i,j;
    cin>>n;
    cout<<modpower((n-1),(n-2));
    return 0;
}
