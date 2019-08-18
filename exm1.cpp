#include<iostream>
#include<algorithm>
#include<math.h>
#include<bits/stdc++.h>

using namespace std;

 int main()
 {
 	int t,n;
 	cin>>t;
 	while(t--)
 	{
 	    string s1,s2;
 	    int c=0;
 	    cin>>n;
 	    cin>>s1;
 	    cin>>s2;
 	    for(int i=0;i<n-1;i++)
 	    {
 	        if(s1[i]==s2[i])
 	        {
 	            c++;
 	        }
 	        else
 	        {
 	            if(s2[i]!='N')
 	            i++;
 	        }
 	    }
 	    if(s1[n-1]==s2[n-1])
 	    {
 	        c++;
 	    }
 	    cout<<c<<endl;
 	}
	return 0;
 }
