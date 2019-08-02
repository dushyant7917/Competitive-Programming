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

ll bs(ll a[],ll x,ll l,ll r){
  ll m,res=-1;

  while(l<=r){
    m=(l+r)/2;
    if(a[m]>x){
      res=m;
      r=m-1;
    }
    else l=m+1;
  }

  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n;
  cin>>n;
  ll a[n];
  fr(i,0,n) cin>>a[i];
  sort(a,a+n);

  ll ans=0;
  ll ind=-1,prv=1;

  fr(i,0,n){
    ind=bs(a,a[i],prv,n-1);
    if(ind!=-1){
      ans++;
      prv=ind+1;
    }
    else break;
  }

  cout<<ans;

  return 0;
}
