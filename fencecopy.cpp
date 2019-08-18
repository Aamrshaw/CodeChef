#include <bits/stdc++.h>
#define ll long long
#define inf 10000000000
#define N 2000000
#define mp make_pair
#define pii pair<lli,lli>
#define lli long long int
#define x first
#define y second
#define rf freopen("inp.in","r",stdin)
using namespace std;

pii a[N];
bool visited[N];
vector<lli> adj[N];
lli size, edgecount,t;
lli ans;
void reset()
{
    for(lli i=1;i<N;i++)
    adj[i].clear();
    memset(::visited,false,sizeof(::visited));
}
void dfs(lli v)
{
    if(visited[v])return;
    //cout<<v<<": "<<size<<" "<<edgecount<<endl;
    size++;
    edgecount+=adj[v].size();
    visited[v] = true;
    for(lli i=0;i<adj[v].size();i++)
    {
        lli u = adj[v][i];
            dfs(u);
    }
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>t;
	while(t--)
    {
        ans=0;
        reset();
        //memset(visited,false,sizeof visited);
        lli r,c,n; cin>>r>>c>>n;
        for(lli i=1;i<=n;i++)
        {
            lli aa,bb; cin>>aa>>bb;
            a[i] = mp(aa,bb);

        }
        sort(a,a+n+1);
        int j=a[1].x;
        lli lastrow = a[n].x;
        for(lli i=1;i<n;i++)
        {
            if(a[i].x==a[i+1].x and a[i].y +1==a[i+1].y)
            {
                adj[i].push_back(i+1);
                adj[i+1].push_back(i);
                //cout<<a[i].x<<" "<<a[i].y<<" "<<a[i+1].x<<" "<<a[i+1].y<<endl;
            }
            for(lli j=i+1;j<=n;j++)
            {
                if(a[i].x+1<a[j].x)break;
                if(a[i].x+1==a[j].x and a[i].y==a[j].y)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                    break;
                    //cout<<i<<" "<<j<<endl;
                    //cout<<a[i].x<<" "<<a[i].y<<" "<<a[j].x<<" "<<a[j].y<<endl;
                }
            }
        }

        for(lli i=1;i<=n;i++)
            {
                if(!visited[i])
                {
                    size=0; edgecount=0;
                    dfs(i);
                    //cout<<i<<": "<<size<<" "<<edgecount<<endl;
                    ans += (size*4 - edgecount );
                }
                //cout<<i<<" "<<adj[i].size()<<endl;
            }
            cout<<ans<<endl;
    }
    return 0;
}
