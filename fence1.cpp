#include<iostream>
#include<algorithm>
#include<math.h>
#include<bits/stdc++.h>

using namespace std;

 int main()
 {
 	long long int t,n,m,k,i,j,r,c;
 	cin>>t;
 	while(t--)
 	{
 	    cin>>n>>m>>k;
 	    long long int f=4*k,fence=0;
 	    map<long long int, list <long long int> > rm,cm;
 	    for(i=0;i<k;i++)
 	    {
 	        cin>>r>>c;
 	        rm[r].push_back(c);
 	        cm[c].push_back(r);
 	    }
 	    map<long long int, list <long long int> >::iterator itr;
 	    list <long long int>::iterator lit;
 	    for(itr=rm.begin();itr!=rm.end();itr++)
 	    {
     	    cout<<itr->first<<"-";
     	    fence+=2;
     	    long long int prev=*itr->second.begin();
     	    for(lit=itr->second.begin();lit!=itr->second.end();lit++)
     	    {
     	        cout<<*lit<<", ";
     	        if(*lit==prev)
     	        {
     	            prev++;
     	        }
     	        else
     	        {
     	            fence+=2;
     	            prev=*lit;
     	        }
     	    }
 	    }
 	    cout<<"\n";
 	    for(itr=cm.begin();itr!=cm.end();itr++)
 	    {
     	    cout<<itr->first<<"-";
     	    fence+=2;
     	    long long int prev=*itr->second.begin();
     	    for(lit=itr->second.begin();lit!=itr->second.end();lit++)
     	    {
     	        cout<<*lit<<", ";
     	        if(*lit==prev)
     	        {
     	            prev++;
     	        }
     	        else
     	        {
     	            fence+=2;
     	            prev=*lit;
     	        }
     	    }
 	    }cout<<"\n";
 	    cout<<fence<<"\n";
 	}
	return 0;
 }
