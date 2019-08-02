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
#define N 200001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll color[N];
ll component[N];
vector<ll> cmp[N];

void init(ll n){
  fr(i,1,n+1) component[i]=i;
}

ll find_component(ll x){
  if(component[x]!=x) component[x]=find_component(component[x]);
  return component[x];
}

void union_components(ll x,ll y){
  x=find_component(x);
  y=find_component(y);
  if(x!=y) component[x]=y;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n,m,k;
  cin>>n>>m>>k;
  fr(i,1,n+1) cin>>color[i];

  init(n);

  ll u,v;
  fr(i,0,m){
    cin>>u>>v;
    union_components(u,v);
  }

  fr(i,1,n+1) cmp[find_component(i)].PB(color[i]);

  ll cnt,ans=0;

  fr(i,1,n+1){
    cnt=0;
    map<ll,ll> mp;
    fr(j,0,SZ(cmp[i])){
      mp[cmp[i][j]]++;
      cnt=max(cnt,mp[cmp[i][j]]);
    }
    ans+=SZ(cmp[i])-cnt;
  }

  cout<<ans;

  return 0;
}
