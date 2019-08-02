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

ll n,m;
ll a[N];
ll dp[N][N];

ll F(ll val,ll ind){
  //cout<<val<<"\n";
  if(val==m) return 1;
  if(val>m) return 0;
  if(ind==n && val<m) return 0;

  if(dp[val][ind]==-1) dp[val][ind]=F(val+a[ind],ind)+F(val,ind+1);
  return dp[val][ind];
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>m>>n;
  fr(i,0,n) cin>>a[i];
  fr(i,0,N) fr(j,0,N) dp[i][j]=-1;
  cout<<F(0,0);

  return 0;
}
