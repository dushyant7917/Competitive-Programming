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
#define N 1000001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

bool visited[N];
ll mark[N];
vector<pii> adj[N];

void init(ll n){
  fr(i,1,n+1){
    visited[i]=false;
    mark[i]=-1;
    adj[i].clear();
  }
}

bool bfs(ll v){
  visited[v]=true;
  mark[v]=1;
  queue<ll> q;
  q.push(v);

  ll x,y,w;
  while(SZ(q)){
    x=q.front();
    q.pop();

    fr(i,0,SZ(adj[x])){
      y=adj[x][i].fi;
      w=adj[x][i].se;
      if((w==0 && mark[y]==1-mark[x]) || (w==1 && mark[y]==mark[x])) return false;
      if(visited[y]) continue;
      visited[y]=true;
      q.push(y);
      if(w==1) mark[y]=1-mark[x];
      else mark[y]=mark[x];
    }
  }

  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  bool flag,ans;
  ll n,q,u,v,w;
  while(t--){
    cin>>n>>q;

    init(n);
    ans=true;

    fr(i,0,q){
      cin>>u>>v>>w;
      adj[u].PB(pii(v,w));
      adj[v].PB(pii(u,w));
    }

    fr(i,1,n+1){
      if(visited[i]) continue;
      flag=bfs(i);
      if(!flag) break;
    }

    if(flag && ans) cout<<"yes\n";
    else cout<<"no\n";
  }

  return 0;
}
