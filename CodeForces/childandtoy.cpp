#include<bits/stdc++.h>

using namespace std;

typedef int ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define rf(x,a,b) for(ll x=a;x>b;x--)
#define pii pair<ll,ll>
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN
#define INF 2e9
#define N 1002
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll n,m;

bool visited[N];

struct Nodes{
  ll id;
  vector<ll> adj;
  ll cost;
};

struct Nodes node[N];

bool cmp(struct Nodes n1,struct Nodes n2){
  if(n1.cost==n2.cost) return SZ(n1.adj)<SZ(n2.adj);
  else return n1.cost>n2.cost;
}

void init(){
  fr(i,1,n+1){
    node[i].id=i;
    visited[i]=false;
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n>>m;

  init();

  fr(i,1,n+1) cin>>node[i].cost;

  ll u,v;
  fr(i,0,m){
    cin>>u>>v;
    node[v].adj.PB(u);
    node[u].adj.PB(v);
  }

  sort(node+1,node+n+1,cmp);

  ll mp[n+1];
  fr(i,1,n+1) mp[node[i].id]=i;

  ll ans=0;
  fr(i,1,n+1){
    fr(j,0,SZ(node[i].adj)){
      ans+=node[mp[node[i].adj[j]]].cost;
    }
    node[i].cost=0;
  }
  cout<<ans;

  return 0;
}
