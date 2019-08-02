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
#define N 101
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll n;
pii p[N];
pii c[N];
ll ans[N],a[N];

ll bs(ll l,ll r,ll p1,ll p2,ll c1,ll c2){
  ll ind=-1,m;

  while(l<=r){
    m=(l+r)/2;
    if((p1-m)*(p1-m)+c1<(p2-m)*(p2-m)+c2){
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

  cin>>n;

  fr(i,1,n+1) cin>>p[i].fi>>p[i].se;

  ll mn;

  fr(i,1,N){
    mn=-1;
    fr(j,1,n+1){
      if(mn==-1){
        mn=(p[j].fi-i)*(p[j].fi-i)+p[j].se;
        ans[i]=j;
      }
      else{
        if((p[j].fi-i)*(p[j].fi-i)+p[j].se<mn){
          mn=(p[j].fi-i)*(p[j].fi-i)+p[j].se;
          ans[i]=j;
        }
      }
    }
  }

  fr(i,1,N) cout<<ans[i];

  cout<<"\n";

  ll ind;
  fr(i,1,n){
    ind=bs(1,N-1,p[i].fi,p[i+1].fi,p[i].se,p[i+1].se);
    cout<<ind<<"\n";
  }

  return 0;
}
