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
#define INF 2e14
#define N 512
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) ((ll)s.size())
#define MS(x,v) memset(x,v,sizeof(x))

ll n;
ll a[N];
vector<ll> adj[N];
bool visited[N];
ll ans,mx;

void init() {
    fr(i,1,n+1) visited[i]=false;
}

void edge_clear() {
    fr(i,1,n+1) adj[i].clear();
}

void dfs(ll v,ll sum) {
    sum+=a[v];
    visited[v]=true;
    //cout<<"v:"<<v<<" sum:"<<sum<<"\n";

    if(v*2>n) {
        mx=max(mx,sum);
        //cout<<"leaf\n";
    }

    ll u;
    fr(i,0,SZ(adj[v])) {
        u=adj[v][i];
        if(visited[u]) continue;
        dfs(u,sum);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    cin>>t;

    while(t--){
        edge_clear();
        init();
        ans=-INF;

        cin>>n;
        fr(i,1,n+1) cin>>a[i];

        fr(i,1,n+1) {
            if(i*2<=n) {
                adj[i].PB(i*2);
                adj[i*2].PB(i);
            }
            if(i*2+1<=n) {
                adj[i].PB(i*2+1);
                adj[i*2+1].PB(i);
            }
        }

        //mx=-INF;
        //dfs(6,0);
        //cout<<"mx:"<<mx<<"\n";
        fr(i,1,n+1) {
            if(i*2<=n) continue;
            init();
            mx=-INF;
            dfs(i,0);
            //cout<<"i:"<<i<<" mx:"<<mx<<"\n\n";
            ans=max(ans,mx);
        }

        cout<<ans<<"\n";
    }

  return 0;
}
