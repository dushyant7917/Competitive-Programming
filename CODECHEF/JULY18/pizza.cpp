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
#define INF 2e15
#define N 1001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll n,m,x;
bool blocked[N][N];
pii p[N];
pii c[N];
ll ans[N];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  fr(i,1,N) fr(j,1,N) blocked[i][j]=false;

  cin>>n>>m;

  fr(i,1,n+1) cin>>p[i].fi>>p[i].se;

  fr(i,1,m+1){
    cin>>c[i].fi>>c[i].se;
    fr(j,0,c[i].se){
      cin>>x;
      blocked[i][x]=true;
    }
  }

  ll mn;

  fr(i,1,m+1){
    mn=-1;
    fr(j,1,n+1){
      if(blocked[i][j]) continue;
      if(mn==-1) mn=(p[j].fi-c[i].fi)*(p[j].fi-c[i].fi)+p[j].se;
      else mn=min(mn,(p[j].fi-c[i].fi)*(p[j].fi-c[i].fi)+p[j].se);
    }
    ans[i]=mn;
  }

  fr(i,1,m+1) cout<<ans[i]<<"\n";

  return 0;
}
