#include<iostream>
#include<algorithm>
#include<math.h>
#include<bits/stdc++.h>
#define lli long long int
using namespace std;

map<lli,vector<lli> >::iterator itr,itr1,itr2;
map<lli,vector<lli> > mp;
vector<lli> vect;
vector<pair<lli,lli> >vp;
vector<lli>::iterator vit;
lli c,sum,ans,a[100005];

void reset()
{
    mp.clear();
    vect.clear();
    vp.clear();
    c=sum=ans=0;
    memset(a,0,sizeof(a));
}

void traversemap(map<lli,vector<lli> >::iterator itr)
{
    if(itr==mp.end())return;
    //cout<<vect[itr->first-1]<<endl;
    sum+=vect[itr->first -1];
    /*for(vit=itr->second.begin();vit!=itr->second.end();vit++)
    {
        itr1=mp.find(*vit);
        traversemap(itr1);
    }*/
    itr1=mp.find(itr->second[0]);
    if(itr->second.size()==2)
    {
        traversemap(itr1);
        itr2=mp.find(itr->second[1]);
        traversemap(itr2);
    }
    else
        traversemap(itr1);
}
void clearmap(map<lli,vector<lli> >::iterator itr)
{
    if(itr==mp.end())return ;
    //cout<<vect[itr->first-1]<<endl;
    if(vect[itr->first-1 ]<0)
    {
        mp.erase(itr->first);
        c++;
    }
    //sum+=vect[itr->first-1 ];
    itr1=mp.find(itr->second[0]);
    if(itr->second.size()==2)
    {
        clearmap(itr1);
        itr2=mp.find(itr->second[1]);
        clearmap(itr2);
    }
    else
        clearmap(itr1);
}

 int main()
 {
 	long long int t,n,u,v,i,x;
 	cin>>t;
 	{
 	    c=0,sum=0;
 	    reset();
 	    cin>>n>>x;
 	    for(i=0;i<n;i++)
 	    {
 	        cin>>a[i];
 	        vect.push_back(a[i]);
 	    }
 	    for(i=0;i<n-1;i++)
 	    {
 	        cin>>u>>v;
 	        mp[u].push_back(v);
 	        vp.push_back(make_pair(u,v));
 	    }
 	    for(i=vp.size()-1;i>=0;i--)
 	    {
 	        vect[vp[i].first-1]+=vect[vp[i].second-1];
 	    }
 	    itr=mp.begin();
 	    clearmap(itr);
 	    vect.clear();
 	    for(i=0;i<n;i++)
 	    {
 	        vect.push_back(a[i]);
 	    }
 	    sum=0;
 	    traversemap(itr);
 	    ans=sum-(c*x);
 	    //cout<<c<<" "<<ans<<"\n";
 	    cout<<ans<<"\n";
 	}
	return 0;
 }
