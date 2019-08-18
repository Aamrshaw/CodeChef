#include <bits/stdc++.h>
#define ll long long
using namespace std;

void check()
{
    for(ll i=0;i<1000000;i++);
}
int main(){

	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//python
	ll T;
	cin >> T;
	while(T--)
	{
		ll n,m;double r;
		cin >> n >> m;
		check();
		r=(n>m)?(double) n/m:(double) m/n;
		if(r>1.618033988749895||n%m==0||m%n==0)
		cout<<"Ari\n";
		else
		cout<<"Rich\n";
	}
	return 0;
}
