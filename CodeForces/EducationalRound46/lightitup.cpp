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

  ll n,m;
  cin>>n>>m;


  ll a[n+2];
  a[0]=0;
  a[n+1]=m;

  fr(i,1,n+1) cin>>a[i];

  ll ans,ontime=0,offtime=0;

  fr(i,1,n+2){
    if(i&1) ontime+=a[i]-a[i-1];
    else offtime+=a[i]-a[i-1];
  }

  ans=ontime;

  ll prefixSum=0,cur;

  fr(i,1,n+2){
    cur=a[i]-a[i-1];

    if(i&1){
      prefixSum+=cur;
      if(cur>1) ans=max(ans,(prefixSum-1)+offtime);
    }
    else{
      if(cur>1) ans=max(ans,prefixSum+(offtime-1));
      offtime-=cur;
    }
  }

  cout<<ans;

  return 0;
}
