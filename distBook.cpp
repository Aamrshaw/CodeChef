#include<iostream>
#include<algorithm>
#include<math.h>
#include<bits/stdc++.h>
#define lli long long int

using namespace std;
lli p=1000000007;

lli countDer(lli n)
{

    lli der[n + 1];
    der[0] = 1;
    der[1] = 0;
    der[2] = 1;
    for (lli i = 3; i <= n; ++i)
        der[i] = ((i - 1) * (der[i - 1] +  der[i - 2]))%p;
    return der[n]%p;
}
int main()
{
    lli n,i,j;
    cin>>n;
    for(j=1;j<=100;j++)
    {
        i=(countDer(j));
        cout<<j<<" "<<i<<endl;
    }

    return 0;
}
