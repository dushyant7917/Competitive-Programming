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

ll n,m,k,cnt,ans;
bool mark[N],visited[N];
ll dist[N];
vector<pii> adj[N];

void dijkstras(){
  priority_queue<pii,vector<pii>,greater<pii> > pq;
  ll u,v,w;

  fr(i,1,n+1){
    if(!mark[i]) continue;

    while(SZ(pq)) pq.pop();

    fr(j,1,n+1){
      visited[j]=false;
      dist[j]=INF;
    }

    cnt=0;
    pq.push(MP(0,i));
    dist[i]=0;

    while(SZ(pq)){
      u=pq.top().se;
      pq.pop();

      if(visited[u]) continue;

      visited[u]=true;
      if(mark[u]) cnt++;

      if(dist[u]>ans) break;

      if(cnt==2 && mark[u]){
        ans=min(ans,dist[u]);
        break;
      }

      fr(j,0,SZ(adj[u])){
        v=adj[u][j].se;
        w=adj[u][j].fi;
        if(dist[u]+w<dist[v]){
          dist[v]=dist[u]+w;
          pq.push(MP(dist[v],v));
        }
      }
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n>>m>>k;

  fr(i,1,n+1) mark[i]=false;

  ll x;
  fr(i,0,k){
    cin>>x;
    mark[x]=true;
  }

  ll u,v,w;
  fr(i,0,m){
    cin>>u>>v>>w;
    adj[u].PB(MP(w,v));
    adj[v].PB(MP(w,u));
  }

  ans=INF;
  dijkstras();
  cout<<ans;

  return 0;
}
