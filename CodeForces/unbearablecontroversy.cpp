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
#define N 3001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll n,m;
vector<ll> adj[N];
bool a[N][N];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n>>m;
  ll u,v;
  fr(i,0,m){
    cin>>u>>v;
    a[u][v]=true;
    adj[u].PB(v);
  }

  ll ans=0,cnt;
  fr(i,1,n+1){
    fr(j,1,n+1){
      if(i!=j){
        cnt=0;
        fr(k,0,SZ(adj[i])){
          v=adj[i][k];
          if(v!=i && v!=j && a[i][v] && a[v][j]) cnt++;
        }
        ans+=(cnt*(cnt-1))/2;
      }
    }
  }

  cout<<ans;

  return 0;
}
