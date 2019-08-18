#include<iostream>
#include<algorithm>
#include<math.h>
#include<bits/stdc++.h>

using namespace std;

void dfs(vector< pair <long long int, long long int> > cp)
{


}
 int main()
 {
 	long long int t,n,m,k,i,j,r,c;
 	cin>>t;
 	while(t--)
 	{
 	    cin>>n>>m>>k;
 	    long long int f=4*k;
 	    vector< pair <long long int, long long int> > rv,cv,cp;
 	    for(i=0;i<k;i++)
 	    {
 	        cin>>r>>c;
 	        rv.push_back(make_pair(r,c));
 	        cv.push_back(make_pair(c,r));
 	    }
 	    sort(rv.begin(),rv.end());
 	    sort(cv.begin(),cv.end());
 	    for(i=0;i<rv.size();i++)
        {
            cout<<rv[i].first<<"-"<<rv[i].second<<"\n";
        }
 	    cout<<"\n";
 	    for(i=0;i<cv.size();i++)
        {
            cout<<cv[i].first<<"-"<<cv[i].second<<"\n";
        }
 	    cout<<"\n";
 	    cp.make_pair(rv[0].first,rv[0].second);
 	    cout<<cp.first<<"-"<<cp.second<<"\n";
 	    dfs(cp);
 	}
	return 0;
 }
