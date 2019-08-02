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
#define MS(x,v) memset(x,v,sizeof(x))

ll n,m;
pii intervals[N];
ll arrival[N];

ll BS(ll x){
  ll ans=INF,l=0,r=n-1,m;
  bool flag=false;

  while(l<=r){
    m=(l+r)/2;
    if(intervals[m].fi<=x && x<intervals[m].se) return 0;
    else if(x<intervals[m].fi){
      flag=true;
      ans=min(ans,intervals[m].fi-x);
      r=m-1;
    }
    else l=m+1;
  }

  if(flag) return ans;

  return -1;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll t;
  cin>>t;

  while(t--){
    cin>>n>>m;

    fr(i,0,n) cin>>intervals[i].fi>>intervals[i].se;

    fr(i,0,m) cin>>arrival[i];

    sort(intervals,intervals+n);

    fr(i,0,m) cout<<BS(arrival[i])<<"\n";
  }

  return 0;
}
