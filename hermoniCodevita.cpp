#include<bits/stdc++.h>
using namespace std;
long long int a[100000],aa[100000];
long long int power(long long int x, long long int y, long long int p)
{
    long long int res = 1;      // Initialize result

    x = x % p;  // Update x if it is more than or
                // equal to p

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}
long long int mulmod(long long int a, long long int b)
{ long long int mod=1000000007;
    long long int res = 0;
    a = a % mod;
    while (b > 0)
    {
        if (b % 2 == 1)
            res = (res + a) % mod;

        a = (a * 2) % mod;
        b /= 2;
		  }

    return res % mod;
}
int main()
{
  long long int n,t,q,i,l,r,largest=-1,k;
  cin>>n;

  aa[1]=1;

  for(i=1;i<=n;i++)
  {
    cin>>a[i];
    if(largest<a[i])largest=a[i];
  }
  cout<<aa[1]<<endl;
    for(k=2;k<=largest;k++)
    {
      aa[k]=mulmod(aa[k-1],k);

  }

  cin>>q;
  for(i=1;i<=q;i++)
  {
    cin>>l>>r;
    long long int pro=1;
    for(k=l;k<=r;k++)
    {
      pro=mulmod(aa[k],pro);
    }

    pro=(power(pro,(r-l),1000000007));
    cout<<pro<<endl;
  }
  return 0;
}
