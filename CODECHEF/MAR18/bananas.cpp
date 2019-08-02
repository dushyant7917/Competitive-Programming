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
#define N 100001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll check(ll a[],ll n,ll h,ll k){
  ll cnt=0;

  fr(i,0,n){
    if(a[i]<=k) cnt+=1;
    else{
      if(a[i]%k==0) cnt+=a[i]/k;
      else cnt+=(a[i]/k)+1;
    }
  }

  return cnt;
}

ll bs(ll a[],ll n,ll h){
  ll m,l=1,r=0,ans,v;

  fr(i,0,n) r=max(r,a[i]);
  ans=r;

  while(l<=r){
    m=(l+r)/2;
    v=check(a,n,h,m);
    if(v<=h) ans=min(ans,m),r=m-1;
    else l=m+1;
  }

  return ans;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  ll n,h;
  while(t--){
    cin>>n>>h;
    ll a[n];
    fr(i,0,n) cin>>a[i];

    cout<<bs(a,n,h)<<"\n";
  }

  return 0;
}
