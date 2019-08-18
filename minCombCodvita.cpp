#include<algorithm>
#include<math.h>
#include<bits/stdc++.h>
#define lli long long int

using namespace std;

lli gcd(lli a, lli b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int main()
{
    lli t,n1,n2,i,j;
    cin>>t;
    while(t--)
    {
        cin>>n1>>n2;
        lli m=99999999;
        if (n1>n2)
        {
           j=gcd(n1,n2);
        }
        else
        {
           j=gcd(n2,n1);
        }

        cout<<t<<" "<<j;
    }
    return 0;
}
