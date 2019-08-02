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
#define INF 2e9
#define N 1001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) ((ll)s.size())
#define MS(x,v) memset(x,v,sizeof(x))

ll n,k;

ll dp[N][N][3];

void init(){
  fr(i,0,n+1){
    fr(j,0,k+1){
      fr(k,0,3){
        dp[i][j][k]=-1;
      }
    }
  }
}

ll F(ll i,ll b,ll prv){
  if(i==0 && b>0) return 0;
  if(b==0) return 1;

  if(dp[i][b][prv]!=-1) return dp[i][b][prv];

  ll res;

  if(prv==1) res=F(i-1,b-1,2)+F(i-1,b,0);
  else if(prv==2) res=F(i-1,b-1,1)+F(i-1,b,0);
  else res=F(i-1,b-1,1)+F(i-1,b-1,2)+F(i-1,b,0);

  dp[i][b][prv]=res;

  return dp[i][b][prv];
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll t;
  cin>>t;

  while(t--){
    cin>>n>>k;
    init();
    cout<<F(n,k,0)<<"\n";
  }

  return 0;
}
