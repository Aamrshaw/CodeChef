#include<bits/stdc++.h>
using namespace std;
int main()
{int a[1000],i,l,sum,max=0,k=0;
sum=0;
string s;
for(i=0;i<152;i++)
    a[i]=0;
    cin>>s;
    l=s.length();
    for(i=0;i<l;i++)
    {
        a[int(s[i])]++;
        if(max<a[int(s[i])])
            max=a[int(s[i])];
    }

for(i=0;i<150;i++)
{

if(a[i]!=0)
{
    k++;
    sum=sum+a[i];
}

}
cout<<k<<" "<<sum<<" "<<max<<endl;
    if(max*k==sum || (max-1)*k+1==sum || (max*k)-1==sum)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;

return 0;
}
