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
#define N 100001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

struct Edge{
  ll u,v,ind;
  bool removed;

  Edge(ll x,ll y,ll i){
    u=x;
    v=y;
    ind=i;
    removed=false;
  }
};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n,m;
  cin>>n>>m;

  vector<Edge> edge;
  vector<Edge> rem;
  ll deg[n+1]={0};
  ll u,v,ind;

  fr(i,0,m){
    cin>>u>>v;
    edge.PB(Edge(u,v,i));
    deg[u]++;
    deg[v]++;
  }

  bool flag;
  ll ans=0;

  while(1){
    flag=false;

    fr(i,0,SZ(edge)){
      u=edge[i].u;
      v=edge[i].v;
      ind=i;

      if(edge[i].removed==false && (deg[u]==1 || deg[v]==1)){
        flag=true;
        rem.PB(Edge(u,v,ind));
      }
    }

    if(flag) ans++;
    else break;

    fr(i,0,SZ(rem)){
      u=rem[i].u;
      v=rem[i].v;
      ind=rem[i].ind;
      deg[u]--;
      deg[v]--;
      edge[ind].removed=true;
    }

    rem.clear();
  }

  cout<<ans;

  return 0;
}
