#include<bits/stdc++.h>

using namespace std;

typedef int ll;
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

ll cd[N][N];

ll ncd(ll n1,ll n2){
  ll n=__gcd(n1,n2);
  ll ans=0;
  ll sr=sqrt(n);

  for(ll i=1;i<=sr;i++){
    if(n%i==0){
      if(n/i==i) ans+=1;
      else ans+=2;
    }
  }

  return ans;
}

void compute_ncd(){
  fr(i,1,N){
    fr(j,1,N){
      if(i!=j) cd[i][j]=ncd(i,j);
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  MS(cd,0);
  compute_ncd();

  fr(i,0,N) fr(j,0,N) fr(k,0,N) {}

  ll n;
  while(t--){
    cin>>n;
    ll a[n+1][n+1];
    fr(i,1,n+1) fr(j,1,n+1) cin>>a[i][j];
  }

  return 0;
}
