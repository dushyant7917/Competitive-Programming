#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define rf(x,a,b) for(ll x=a;x>=b;x--)
#define pii pair<ll,ll>
#define fi first
#define se second
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN
#define INF 2e9
#define N 200001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) ((ll)s.size())
#define MS(x,v) memset(x,v,sizeof(x))

ll n;
ll val[N],sum[N];
vector<ll> adj[N];
ll ans,res;

void dfs(ll v,ll p,ll d) {
    res+=(val[v]*d);
    sum[v]=val[v];

    ll u;
    fr(i,0,SZ(adj[v])) {
        u=adj[v][i];
        if(u==p) continue;
        dfs(u,v,d+1);
        sum[v]+=sum[u];
    }
}

void compute(ll v,ll p) {
    ans=max(ans,res);

    ll u;
    fr(i,0,SZ(adj[v])) {
        u=adj[v][i];
        if(u==p) continue;

        // calculating values after making u as the root
        res-=sum[u];
        sum[v]-=sum[u];
        res+=sum[v];
        sum[u]+=sum[v];

        // calling the function for u as root
        compute(u,v);

        // rolling back the changes
        sum[u]-=sum[v];
        res-=sum[v];
        sum[v]+=sum[u];
        res+=sum[u];
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    fr(i,1,n+1) cin>>val[i];

    ll x,y;
    fr(i,0,n-1) {
        cin>>x>>y;
        adj[x].PB(y);
        adj[y].PB(x);
    }

    res=ans=0;
    dfs(1,-1,0);
    compute(1,-1);

    cout<<ans;

  return 0;
}
