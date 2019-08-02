#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
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
#define N 1001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll n,m,k;
ll component[N];
ll sz[N];
bool gov[N];

ll find_component(ll node){
  while(component[node]!=node){
    component[node]=component[component[node]];
    node=component[node];
  }
  return node;
}

void union_components(ll node1,ll node2){
  ll x=find_component(node1);
  ll y=find_component(node2);
  component[x]=component[y];
  sz[y]+=sz[x];
  sz[x]=0;
}

ll max_edges(ll n){
  return (n*(n-1))/2;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n>>m>>k;

  fr(i,1,n+1){
    component[i]=i;
    sz[i]=1;
  }

  ll c[k];
  fr(i,0,k) cin>>c[i];

  ll x,y;
  fr(i,0,m){
    cin>>x>>y;
    if(find_component(x)!=find_component(y)) union_components(x,y);
  }

  MS(gov,false);
  ll ms=0;
  fr(i,0,k){
    c[i]=find_component(c[i]);
    gov[c[i]]=true;
    ms=max(ms,sz[c[i]]);
  }

  ll non_gov_size=0;
  fr(i,1,n+1){
    if(!gov[i]) non_gov_size+=sz[i];
  }

  ll total_edges=0;
  bool flag=false;
  fr(i,0,k){
    if(sz[c[i]]==ms && !flag){
      total_edges+=max_edges(sz[c[i]]+non_gov_size);
      flag=true;
    }
    else total_edges+=max_edges(sz[c[i]]);
  }

  cout<<total_edges-m;

  return 0;
}
