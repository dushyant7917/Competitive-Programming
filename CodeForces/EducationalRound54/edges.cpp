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
#define INF 2e15
#define N 300005
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) ((ll)s.size())
#define MS(x,v) memset(x,v,sizeof(x))

struct Edge{
  ll w,to,ind;
};

ll n,m,k;
vector<Edge> adj[N];
vector<ll> ans;
ll dist[N],last[N];

void dijkstras(){
  set<pii> s;
  s.insert(MP(0,1));
  ll cnt=0;
  fr(i,2,n+1) dist[i]=INF;
  fr(i,1,n+1) last[i]=0;
  dist[1]=0;

  ll u,v,w,ind;
  while(SZ(s) && cnt<min(n,k+1)){
    u=(*s.begin()).se;
    s.erase(s.begin());

    cnt++;
    if(last[u]) ans.PB(last[u]);

    fr(i,0,SZ(adj[u])){
      v=adj[u][i].to;
      w=adj[u][i].w;
      ind=adj[u][i].ind;
      if(dist[u]+w<dist[v]){
        s.erase(MP(dist[v],v));
        last[v]=ind;
        dist[v]=dist[u]+w;
        s.insert(MP(dist[v],v));
      }
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n>>m>>k;

  ll x,y,w;

  fr(i,0,m){
    cin>>x>>y>>w;
    adj[x].PB({w,y,i+1});
    adj[y].PB({w,x,i+1});
  }

  dijkstras();

  cout<<SZ(ans)<<"\n";
  fr(i,0,SZ(ans)) cout<<ans[i]<<" ";

  return 0;
}
