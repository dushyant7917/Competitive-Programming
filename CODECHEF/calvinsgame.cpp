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
ll arr[N],dpLTR[N],dpRTL[N];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n>>k;
  fr(i,1,n+1) cin>>arr[i];

  fr(i,0,n+1) dpLTR[i]=dpRTL[i]=-INF;

  dpLTR[k]=0;
  if(k+1<=n) dpLTR[k+1]=arr[k+1];
  if(k+2<=n) dpLTR[k+2]=max(arr[k+2],arr[k+1]+arr[k+2]);
  fr(i,k+3,n+1) dpLTR[i]=arr[i]+max(dpLTR[i-1],dpLTR[i-2]);

  dpRTL[1]=0;
  if(n>=2) dpRTL[2]=arr[1];
  fr(i,3,n+1) dpRTL[i]=max(arr[i-1]+dpRTL[i-1],arr[i-2]+dpRTL[i-2]);

  ll ans=-INF;
  fr(i,k,n+1) ans=max(ans,dpLTR[i]+dpRTL[i]);
  cout<<ans;

  return 0;
}
