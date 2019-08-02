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
#define SZ(s) ((ll)s.size())

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll t;
  cin>>t;

  ll n,k,x,ans;
  while(t--){
    cin>>n>>k;

    if(k*(k+1)>n*2) cout<<-1<<"\n";

    else{
      ll a[k+1];

      x=(n-((k*(k+1))/2))/k;
      fr(i,1,k+1) a[i]=i+x;

      n-=(k*(k+1))/2;
      fr(i,1,k+1) if(a[i]+(n%k)==a[k]+1) a[i]+=(n%k);

      ans=1;
      fr(i,1,k+1) ans=((ans%mod)*(((a[i]%mod)*(a[i]%mod)-(a[i]%mod))%mod))%mod;
      cout<<ans<<"\n";
    }
  }

  return 0;
}
