#include<iostream>
using namespace std;
int fact(int n);

int nCr(int n, int r)
{
    return fact(n) / (fact(r) * fact(n - r));
}
int fact(int n)
{
    int res = 1;
    for (int i = 2; i <= n; i++)
        res = res * i;
    return res;
}
int main()
{
    int x,y,z,s,m,c;
    char p1,p2;
    char p3;
    cin>>x>>s>>y>>m>>z>>c>>p1>>p2>>p3;
    int total=nCr(x,s)*nCr(y,m)*nCr(z,c);
    int ip1=(int)p1-64;
    int ip2=(int)p2-64;
    int ip3=(int)p3-64;
     int pa1=nCr(x,s);
     int pa2=nCr(y,m);
     int pa3=nCr(z,c);
     int affx=0,affy=0,affz=0;
     int total1;
     //find not possible for 2nd output
     if(ip1<=x)
     {
         //affected
         affx++;
     }
     else
        if(ip1<=x+y)
        affy++;
     else
        affz++;
     if(ip2<=x)
        affx++;
     else
        if(ip2<=x+y)
        affy++;
     else
        affz++;
     total1=total-nCr(x-affx,s-affx)*nCr(y-affy,m-affy)*nCr(z-affz,c-affz);
     //third condition
     if(ip3<=x)
     {
         affx++;
         total1=total1-nCr(x-1,s-1)*nCr(y,m)*nCr(z,c);
     }
     else
        if(ip3<=x+y)
     {
         affy++;
         total1-=nCr(x,s)*nCr(y-1,m-1)*nCr(z,c);
     }
     else
     {
         affz++;
         total1-=nCr(x,s)*nCr(y,m)*nCr(z-1,c-1);
     }
     //adding part subtracted twice+1
     total1=total1+1+nCr(x-affx,s-affx)*nCr(y-affy,m-affy)*nCr(z-affz,c-affz);
     cout<<total<<endl;
     cout<<total1;
     return 0;
}
