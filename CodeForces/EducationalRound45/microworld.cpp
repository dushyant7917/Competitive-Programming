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

bool bs(ll a[],ll n,ll i,ll k){
  ll l=i+1,h=n-1,m;

  while(l<=h){
    m=(l+h)/2;
    if(a[m]>a[i] && a[m]<=a[i]+k) return true;
    else if(a[m]>a[i]+k && a[m]>a[i]+k) h=m-1;
    else l=m+1;
  }

  return false;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n,k;
  cin>>n>>k;
  ll a[n];
  fr(i,0,n) cin>>a[i];

  sort(a,a+n);

  ll cnt=0;
  fr(i,0,n){
    cnt+=(ll)bs(a,n,i,k);
  }

  cout<<n-cnt;

  return 0;
}
