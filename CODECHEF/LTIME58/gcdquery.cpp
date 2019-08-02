#include<bits/stdc++.h>

using namespace std;

typedef int ll;
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
#define N 10005
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll a[N],pos[N*N],dp[N][N];
vector<ll> divisors[N];

void cal(ll n){
  for(ll i=1;i*i<=a[n];i++){
    if(a[n]%i==0){
      divisors[n].PB(i);
      if(a[n]/i!=i) divisors[n].PB(a[n]/i);
    }
  }
  sort(divisors[n].begin(),divisors[n].end());
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n,q;
  cin>>n>>q;

  fr(i,1,n+1){
    cin>>a[i];
    cal(i);
  }

  rf(i,n,1){
    fr(j,0,SZ(divisors[i])){
      if(i<n) dp[i][pos[divisors[i][j]]]=divisors[i][j];
      pos[divisors[i][j]]=i;
    }
  }

  rf(i,n,1){
    fr(j,i+1,n+1){
      dp[i][j]=MAX(dp[i][j],dp[i+1][j],dp[i][j-1]);
    }
  }

  ll l,r;
  fr(i,0,q){
    cin>>l>>r;
    cout<<dp[l][r]<<"\n";
  }

  return 0;
}
