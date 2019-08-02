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
#define INF 2e15
#define N 1000002
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) ((ll)s.size())
#define MS(x,v) memset(x,v,sizeof(x))

ll n,k;
ll arr[N];

ll ltr(ll i,ll stop){
  if(i>=stop) return 0;

  ll a,b;
  a=b=-INF;

  if(i+1<=stop) a=arr[i+1]+ltr(i+1,stop);
  if(i+2<=stop) b=arr[i+2]+ltr(i+2,stop);

  return max(a,b);
}

ll rtl(ll i,ll stop){
  if(i<=stop) return 0;

  ll a,b;
  a=b=-INF;

  if(i-1>=stop) a=arr[i-1]+rtl(i-1,stop);
  if(i-2>=stop) b=arr[i-2]+rtl(i-2,stop);

  return max(a,b);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n>>k;
  fr(i,1,n+1) cin>>arr[i];

  ll ans=-INF;
  fr(i,k,n+1) ans=max(ans,ltr(k,i)+rtl(i,1));
  cout<<ans;

  return 0;
}
