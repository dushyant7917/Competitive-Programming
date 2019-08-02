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
#define N 1000002
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll ps[N],ss[N],s[N];

ll bsl(ll l,ll r,ll i){
  ll ind=i-1,m;

  while(l<=r){
    m=(l+r)/2;
    if(ss[m]-ss[i]-s[m]<=s[i]){
      ind=m;
      r=m-1;
    }
    else l=m+1;
  }

  return ind;
}

ll bsr(ll l,ll r,ll i){
  ll ind=i+1,m;

  while(l<=r){
    m=(l+r)/2;
    if(ps[m]-ps[i]-s[m]<=s[i]){
      ind=m;
      l=m+1;
    }
    else r=m-1;
  }

  return ind;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  ll n;
  while(t--){
    cin>>n;
    fr(i,0,n) cin>>s[i];

    ps[0]=s[0];
    fr(i,1,n) ps[i]=ps[i-1]+s[i];
    ss[n-1]=s[n-1];
    rf(i,n-2,0) ss[i]=ss[i+1]+s[i];

    ll l,r;
    ll ans[n]={0};

    fr(i,0,n){
      if(i==0){
        l=i+1;
        r=bsr(i+1,n-1,i);
      }
      else if(i==n-1){
        r=i-1;
        l=bsl(0,i-1,i);
      }
      else{
        l=bsl(0,i-1,i);
        r=bsr(i+1,n-1,i);
      }
      fr(j,l,r+1) if(j!=i) ans[j]++;
    }
    fr(i,0,n) cout<<ans[i]<<" ";
    cout<<"\n";
  }

  return 0;
}
