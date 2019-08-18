#include<bits/stdc++.h>
#include<iostream>
using namespace std;
double t1=1/365;
int main()
{
    int n,i,t,j;
    double r,t1,I;
    string op;
    cin>>r>>n;
    int a[n]={0},task[n]={0},bal[n]={-1},bal1,bal2;
    int sum=0;
    for(i=0;i<n-2;i++)
    {
        cin>>j;
        cin>>a[j-1]>>op>>bal[j-1];
        if (op=="credit")
            task[j-1]=1;
        else
            task[j-1]=-1;
        sum+=bal[j-1];
        if(task[j-2]==0)
        {
            bal2=(-1*task[j-1]*a[j-1]+bal[j-1]);
        }
    }
    cin>>I;
    r=(r/100);
    double I1=(sum*r)/365;
    I1=I-I1;
    int req=round((I1*365)/r);
    bal1=req-bal2;
    for(i=0;i<n;i++)
    {
        if(task[i]==0)
        {
            if(bal[i-1]>bal1)
                cout<<(i+1)<<" "<<(bal[i-1]-bal1)<<" debit "<<bal1<<endl;
            else
                cout<<(i+1)<<" "<<(bal1-bal[i-1])<<" credit "<<bal1<<endl;
            if(bal1>bal2)
                cout<<(i+2)<<" "<<(bal1-bal2)<<" debit "<<bal2;
            else
                cout<<(i+2)<<" "<<(bal2-bal1)<<" credit "<<bal2;
            break;
        }
    }
    return 0;
}
