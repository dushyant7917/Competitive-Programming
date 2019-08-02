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
#define N 100001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll n,m,src,t;
ll dist[N];
vector<pii> adj[N];

void dijkstras(){
  fr(i,1,n+1) dist[i]=INF;
  priority_queue<pii,vector<pii>,greater<pii> > pq;
  pq.push(MP(0,src));
  dist[src]=0;

  ll u,v,w;
  while(SZ(pq)){
    u=pq.top().se;
    pq.pop();

    fr(i,0,SZ(adj[u])){
      v=adj[u][i].se;
      w=adj[u][i].fi;
      if(dist[u]+w<dist[v]){
        dist[v]=dist[u]+w;
        pq.push(MP(dist[v],v));
      }
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n>>src>>t>>m;

  ll u,v,w;
  fr(i,0,m){
    cin>>u>>v>>w;
    adj[v].PB(MP(w,u));
  }

  dijkstras();

  ll ans=0;
  fr(i,1,n+1) if(dist[i]<=t) ans++;
  cout<<ans;

  return 0;
}
