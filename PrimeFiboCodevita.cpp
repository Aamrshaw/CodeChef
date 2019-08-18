#include<algorithm>
#include<math.h>
#include<bits/stdc++.h>
#define lli long long int
using namespace std;

lli Max(set<lli> s) 
{ 
    lli max_element; 
    if (!s.empty()) 
        max_element = *(s.rbegin()); 
  
   
    return max_element; 
} 
lli Min(set<lli> s) 
{ 
  
     
    lli min_element; 
    if (!s.empty()) 
        min_element = *s.begin(); 
  
    
    return min_element; 
} 
lli  isPrime(lli n)
{
    lli  i,flag=0;
	for(i=2;i<=n/2;i++)
	{
		if(n%i==0)
		flag=1;
	}
	if (flag==0)
	return 1;
	else
	return 0;
}

int main()
{
    set <lli> pset;
    string ps[1000];
    lli  i,k=0,j,n,m,y=0,u[1000],a,b,c;
	cin>>n>>m;
	for(i=n;i<=m;i++)
	{
		if(isPrime(i)==1)
		ps[k++]=to_string(i);
		}
	for(i=0;i<k;i++)
	{
		for(j=0;j<k;j++)
		{  
		    if(j!=i)
		    {
    		    if(isPrime(stoi(ps[i]+ps[j]))==1)
    			    pset.insert(stoi(ps[i]+ps[j]));
		    }
		}
	}
    lli l=pset.size();
    a=Min(pset);
    b=Max(pset);
    for(i=0;i<l-2;i++)
    {
    	c=a+b;
    	a=b;
    	b=c;
    }
    cout<<c;
    return 0;
}