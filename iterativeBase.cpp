#include<algorithm>
#include<math.h>
#include<bits/stdc++.h>
#define lli long long int

using namespace std;
string base="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int main()
{
    int i,j,m,b=99,sum1=0;
    string s;
    cin>>s;
    int l=s.size();
    while(1)
    {
        vector<int> bval;
        m=0;
        for(i=0;i<l;i++)
        {
            j = base.find(s[i]);
            m=max(m,j);
            bval.push_back(j);
        }
        b=m+1;
        ////cout<<m<<" "<<b<<endl;
        int sum=0;
        for(i=0;i<l;i++)
        {
            sum+=bval[i]*(pow(b,(l-i-1)));
        }
        if(sum1==sum)
        break;
        sum1=sum;
        s=to_string(sum);
        l=s.size();
        //cout<<s<<" "<<l<<endl;
    }
    cout<<sum1<<endl;
    return 0;
}