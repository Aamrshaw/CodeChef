#include<iostream>
#include<algorithm>
#include<math.h>
#include<bits/stdc++.h>
#define lli long long int

using namespace std;

 int main()
 {
    lli t,n,m,i,j,d,v;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        vector<pair<lli,lli> > a;
        for(i=0;i<n;i++)
        {
            cin>>d>>v;
            a.push_back(make_pair(v,d));
        }
        sort(a.begin(),a.end());
        lli sum=a[n-1].first;
        for(i=n-1;i>0;i--)
        {
            if(a[i].second!=a[i-1].second)
            {
                sum+=a[i-1].first;
                break;
            }
        }
        cout<<sum<<endl;
    }
	return 0;
 }
