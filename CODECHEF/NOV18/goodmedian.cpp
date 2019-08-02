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
#define MIN(a,b,c,d) min(min(a,b),min(c,d))
#define SZ(s) ((ll)s.size())
#define MS(x,v) memset(x,v,sizeof(x))

ll ncr[2*N][2*N];

void preProcess(){
  fr(i,0,2*N) fr(j,0,2*N) ncr[i][j]=0;

  fr(i,1,2*N){
    fr(j,0,i+1){
      if(j==0 || j==i) ncr[i][j]=1;
      else ncr[i][j]=((ncr[i-1][j-1]%mod)+(ncr[i-1][j]%mod))%mod;
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  preProcess();

  ll t;
  cin>>t;

  ll n,ans;
  while(t--){
    cin>>n;

    ll a[n];
    fr(i,0,n) cin>>a[i];

    sort(a,a+n);

    ans=n;

    fr(i,1,n-1){
      fr(j,1,min(i,n-i-1)+1){
        ans=((ans%mod)+((ncr[i][j]%mod)*(ncr[n-i-1][j]%mod)))%mod;
      }
    }

    fr(i,0,n-1){
      fr(j,i+1,n){
        if((a[i]+a[j])&1) continue;
        if(a[i]!=a[j]) continue;
        ans=((ans%mod)+1)%mod;
        if(i==0 || j==n-1) continue;
        else ans=((ans%mod)+(ncr[i+n-j-1][i]%mod)-1)%mod;
      }
    }

    cout<<ans<<"\n";
  }

  return 0;
}
