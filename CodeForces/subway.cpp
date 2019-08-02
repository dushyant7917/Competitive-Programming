#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define rf(x,a,b) for(ll x=a;x>=b;x--)
#define pii pair<ll,ll>
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN
#define INF 2e9
#define N 3002
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll n;
vector<ll> adj[N];
ll dist[N];
ll parent[N];
bool visited[N];
stack<ll> st;

void process_cycle(ll x){
  dist[x]=0;

  while(SZ(st) && st.top()!=x){
    dist[st.top()]=0;
    st.pop();
  }
}

ll dfs(ll v,ll par){
  visited[v]=true;
  st.push(v);

  ll u,x;
  fr(i,0,SZ(adj[v])){
    u=adj[v][i];
    if(u==par) continue;

    if(!visited[u]){
      parent[u]=v;
      x=dfs(u,parent[u]);
      if(x) return x;
    }
    else if(visited[u] && parent[u]!=v) return u;
    else {}
  }

  st.pop();
  return 0;
}

void find_dist(ll v,ll d){
  visited[v]=true;
  dist[v]=d;

  ll u;
  fr(i,0,SZ(adj[v])){
    u=adj[v][i];
    if(visited[u]) continue;
    if(dist[u]==0) continue;
    find_dist(u,d+1);
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n;
  ll u,v;
  fr(i,0,n){
    cin>>u>>v;
    adj[u].PB(v);
    adj[v].PB(u);
  }

  MS(visited,false);
  MS(parent,-1);
  fr(i,1,n+1) dist[i]=INF;

  ll x=dfs(1,-1);
  if(x) process_cycle(x);

  MS(visited,false);

  fr(i,1,n+1){
    if(!dist[i]) find_dist(i,0);
  }

  fr(i,1,n+1) cout<<dist[i]<<" ";

  return 0;
}
