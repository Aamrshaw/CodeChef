#include<iostream>
#include<algorithm>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;

string removeDuplicatesFromString(string str)
{
    int counter=0, length=0, i=0, x, size=str.size();
    while (i < size) {
        x = str[i] - 97;
        if ((counter & (1 << x)) == 0) {
            str[length] = 'a' + x;
            counter = counter | (1 << x);
            length++;
        }
        i++;
    }
    return str.substr(0, length);
}

 int main()
 {
 	string str,cmbstr;
 	long long int t,n,i,j,x,c,c5,i1,i2,i3,i4;
 	map<string, long long int> smap;
 	map<string, long long int>::iterator itr;
 	map<string, long long int>::iterator itr1;
 	map<string, long long int>::iterator itr2;
 	cin>>t;
 	while(t--)
 	{
 	    cin>>n;
 	    c5=i1=i2=i3=i4=c=0;
 	    string str4[n],str3[n],str2[n],str1[n];
 	    for(i=0;i<n;i++)
 	    {
 	        cin>>str;
 	        str= removeDuplicatesFromString(str);
 	        x=str.length();
 	        sort(str.begin(), str.end());
 	        smap[str]++;
 	        //cout<<str<<"\n";
 	    }
 	    //cout<<"i1="<<i1<<", i2="<<i2<<", i3="<<i3<<", i4="<<i4<<", i5="<<c5<<"\n";
 	    for (itr = smap.begin(); itr != smap.end(); ++itr)
 	    {
 	        for (itr2 =next(itr,1) ; itr2 != smap.end(); ++itr2)
 	        {
 	            cmbstr=itr->first+itr2->first;
 	            cmbstr= removeDuplicatesFromString(cmbstr);
 	            if(cmbstr.length()==5)
 	            c++;
		    }
 	    }
 	    cout<<c<<"\n";
 	}
	return 0;
 }
