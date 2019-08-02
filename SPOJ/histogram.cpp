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
#define N 100001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll f[9];
  f[0]=f[1]=1;
  fr(i,2,9) f[i]=f[i-1]*i;

  ll n,k,ans,sum2,sum1,freq;
  while(cin>>n && n){
    k=n/2;

    ll a[n];
    fr(i,0,n) cin>>a[i];
    sort(a,a+n);

    sum1=sum2=0;

    if(n&1){
      fr(i,0,k) sum1+=a[i];
      fr(i,k,n) sum2+=a[i];
      ans=(sum2-sum1+n)*2;
      freq=f[k+1]*f[k];
    }
    else{
      fr(i,0,k) sum1+=a[i];
      fr(i,k-1,n) sum2+=a[i];
      ans=(sum2-sum1+n)*2;
      freq=2*(f[k])*(f[k]);
    }

    cout<<ans<<" "<<freq<<"\n";
  }

  return 0;
}
