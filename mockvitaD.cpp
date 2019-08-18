#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>
#include<bits/stdc++.h>
#define lli long long int
//#define fn(n) n*a[n-1] + (n-1)*a[n-2]
using namespace std;

vector<string> a;
string multiply(string num1, string num2)
{
    int n1 = num1.size();
    int n2 = num2.size();
    if (n1 == 0 || n2 == 0)
    return "0";
    vector<int> result(n1 + n2, 0);
    int i_n1 = 0;
    int i_n2 = 0;
    for (int i=n1-1; i>=0; i--)
    {
        int carry = 0;
        int n1 = num1[i] - '0';
        i_n2 = 0;
        for (int j=n2-1; j>=0; j--)
        {
            int n2 = num2[j] - '0';
            int sum = n1*n2 + result[i_n1 + i_n2] + carry;
            carry = sum/10;
            result[i_n1 + i_n2] = sum % 10;
            i_n2++;
        }
        if (carry > 0)
            result[i_n1 + i_n2] += carry;
        i_n1++;
    }
    int i = result.size() - 1;
    while (i>=0 && result[i] == 0)
    i--;
    if (i == -1)
    return "0";
    string s = "";
    while (i >= 0)
        s += to_string(result[i--]);
    return s;
}
string findSum(string str1, string str2)
{
    if (str1.length() > str2.length())
        swap(str1, str2);
    string str = "";
    int n1 = str1.length(), n2 = str2.length();
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
    int carry = 0;
    for (int i=0; i<n1; i++)
    {
        int sum = ((str1[i]-'0')+(str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }
    for (int i=n1; i<n2; i++)
    {
        int sum = ((str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }
    if (carry)
        str.push_back(carry+'0');
    reverse(str.begin(), str.end());
    return str;
}
string findDiff(string str1, string str2)
{
    /*if (isSmaller(str1, str2))
        swap(str1, str2);*/
    string str = "";
    int n1 = str1.length(), n2 = str2.length();
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
    int carry = 0;
    for (int i=0; i<n2; i++)
    {
        int sub = ((str1[i]-'0')-(str2[i]-'0')-carry);
        if (sub < 0)
        {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;
        str.push_back(sub + '0');
    }
    for (int i=n2; i<n1; i++)
    {
        int sub = ((str1[i]-'0') - carry);
        if (sub < 0)
        {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;
        str.push_back(sub + '0');
    }
    reverse(str.begin(), str.end());
    return str;
}

void fn(lli n)
{
    lli n1=n-1;
    string strn=to_string(n);string strn1=to_string(n1);
    a.push_back(findSum(multiply(strn,a[n-1]), multiply(strn1,a[n-2])));
}
lli numFact(lli n)
{
    int fact=0;
    for(lli i=1;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            fact++;
            if(n%(n/i)==0 && (n/i)!=i)
                fact++;
        }
    }
    return fact;
}
int main()
{
    lli t,n,i,p;
    cin>>t;
    a.push_back("1");
    a.push_back("1");
    for(i=2;i<25;i++)
        fn(i);
    while(t--)
    {
        cin>>n;
        p=numFact(n);
        cout<<p<<" "<<a[p-1]<<"\n";
    }
    return 0;
}
