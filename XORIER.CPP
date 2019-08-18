#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int t,i,j,n,c,ec,oc,tec,toc,x,a[100002],result;
    map <long long int, long long int> emp;
    map <long long int, long long int> :: iterator itr1;
    map <long long int, long long int> :: iterator itr2;
    cin>>t;
    while(t--)
    {
        cin>>n;
        j=0;
        ec=0;
        oc=0;
        memset(a, -1, sizeof(a));
        for(i=0;i<n;i++)
        {
            cin>>c;
            if(c%2==0)
            ec++;
            else
            oc++;
            itr1=emp.find(c);
            if(itr1!=emp.end())
            {
                emp[c]=(itr1->second)+1;
            }
            else
            {
                a[j++]=c;   //creation of array without duplicacy
                emp[c]=1;
            }
        }
        tec=(ec*(ec-1))/2;  //total combination of even numbcers
        toc=(oc*(oc-1))/2;  //total combination of even numbcers
        cout<<"tec="<<tec<<" toc="<<toc<<" "<<j<<"\n";
        //for element of array without duplicacy
        for(i=0;i<j;i++)
        {
            x=a[i]^2;
            itr1=emp.find(a[i]);
            itr2=emp.find(x);
            if(a[i]%2==0)
            {
                if(itr1!=emp.end())
                {
                    cout<<"even-a "<<(itr1->second*(itr1->second-1))/2<<"tec:"<<tec<<"\n";
                    tec-=(itr1->second*(itr1->second-1))/2;

                }
                x=a[i]^2;
                itr1=emp.find(a[i]);
                itr2=emp.find(x);
                if(itr2!=emp.end())
                {
                    cout<<x<<" "<<(itr1->second*(itr2->second))<<"tec:"<<tec<<"\n";
                    tec-=(itr1->second*(itr2->second));
                    emp[a[i]]=0;
                }
            }
            else
            {
                if(itr1!=emp.end())
                {
                    cout<<"odd-a "<<(itr1->second*(itr1->second-1))/2<<"toc:"<<toc<<"\n";
                    toc-=(itr1->second*(itr1->second-1))/2;

                }
                x=a[i]^2;
                itr1=emp.find(a[i]);
                itr2=emp.find(x);
                if(itr2!=emp.end())
                {
                    cout<<x<<" "<<(itr1->second*(itr2->second))<<"toc:"<<toc<<"\n";
                    toc-=(itr1->second*itr2->second);
                    emp[a[i]]=0;
                }
            }
        }
        cout<<"tec="<<tec<<" toc="<<toc<<"\n";
        result=(tec+toc);
        cout<<result<<"\n";
    }
    return 0;
}
/*
4
5
8 2 4 1 3
2
6 8
2
5 7
4
6 8 7 5
*/
