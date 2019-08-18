#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,c;
    cin>>t;
    while(t--)
    {
        cin>>n;
        c=floor(log(n)/log(2)+1);
        cout<<c<<endl;
    }
}
