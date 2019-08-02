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

pii a[12],b[12];

bool bothSame(ll i,ll j){
  if(a[i].fi==b[j].fi && a[i].se==b[j].se) return true;
  else return false;
}

bool bothDifferent(ll i,ll j){
  if(a[i].fi!=b[j].fi && a[i].fi!=b[j].se && a[i].se!=b[j].fi && a[i].se!=b[j].se) return true;
  else return false;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n,m;
  cin>>n>>m;

  ll x,y;
  ll f[10]={0};

  fr(i,0,n){
    cin>>x>>y;
    if(x>y) swap(x,y);
    a[i].fi=x;
    a[i].se=y;
  }
  fr(i,0,m){
    cin>>x>>y;
    if(x>y) swap(x,y);
    b[i].fi=x;
    b[i].se=y;
  }

  set<ll> s1[n],s2[m];
  ll c;

  fr(i,0,n){
    fr(j,0,m){
      if(bothSame(i,j) || bothDifferent(i,j)) continue;
      if(a[i].fi==b[j].fi || a[i].fi==b[j].se || a[i].se==b[j].fi || a[i].se==b[j].se){
        if(a[i].fi==b[j].fi || a[i].fi==b[j].se) c=a[i].fi;
        if(a[i].se==b[j].fi || a[i].se==b[j].se) c=a[i].se;
        s1[i].insert(c);
        s2[j].insert(c);
        f[c]++;
      }
    }
  }

  ll cnt=0;
  fr(i,0,10) if(f[i]>0) cnt++;

  if(cnt==1){
    cout<<c;
    return 0;
  }

  ll a1=0,b1=0;
  fr(i,0,n) if(SZ(s1[i])>1) a1++;
  fr(i,0,m) if(SZ(s2[i])>1) b1++;

  if(!a1 && !b1) cout<<0;
  else cout<<-1;

  return 0;
}
