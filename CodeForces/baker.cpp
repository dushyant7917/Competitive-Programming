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
#define N 100001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll n,m,k;
vector<pii> graph[N];
bool storage[N];

ll ans=INF;

void cal(){
  fr(i,1,n+1){
    if(!storage[i]){
      fr(j,0,SZ(graph[i])){
        if(storage[graph[i][j].first]) ans=min(ans,graph[i][j].second);
      }
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n>>m>>k;
  ll u,v,l;
  fr(i,0,m){
    cin>>u>>v>>l;
    graph[u].PB(MP(v,l));
    graph[v].PB(MP(u,l));
  }

  MS(storage,false);
  ll s;
  fr(i,0,k){
    cin>>s;
    storage[s]=true;
  }

  cal();
  if(ans==INF) cout<<-1;
  else cout<<ans;

  return 0;
}
