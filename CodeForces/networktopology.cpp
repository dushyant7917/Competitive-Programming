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
#define N 100005
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll n,m;
vector<ll> adj[N];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n,m;
  cin>>n>>m;

  ll u,v;
  fr(i,0,m){
    cin>>u>>v;
    adj[u].PB(v);
    adj[v].PB(u);
  }

  ll centre=0,endpoints=0,internal=0;
  fr(i,1,n+1){
    if(SZ(adj[i])==n-1) centre++;
    if(SZ(adj[i])==2) internal++;
    if(SZ(adj[i])==1) endpoints++;
  }
  if(centre==1 && endpoints==n-1){
    cout<<"star topology";
  }
  else if(internal==n-2 && endpoints==2){
    cout<<"bus topology";
  }
  else if(internal==n){
    cout<<"ring topology";
  }
  else{
    cout<<"unknown topology";
  }

  return 0;
}
