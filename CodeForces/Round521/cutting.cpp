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
#define N 200005
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) ((ll)s.size())
#define MS(x,v) memset(x,v,sizeof(x))

ll n,k;
ll a[N];
vector<pii> p;
vector<ll> v;

bool cmp(pii p1,pii p2){
  return p1.se>p2.se;
}

bool F(ll x){
  if(!x) return false;
  v.clear();
  //cout<<"x:"<<x<<"\n";

  ll f;

  fr(i,0,SZ(p)){
    if(p[i].se>=x){
      f=(ll)p[i].se/(ll)x;
      //cout<<"f:"<<(f)<<"\n";
      ll j=0;
      while(j<f && SZ(v)<k){
        v.PB(p[i].fi);
        j++;
      }
      //v.PB(p[i].fi);
    }
    else return false;
    if(SZ(v)==k) return true;
  }

  return false;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n>>k;
  fr(i,0,n) cin>>a[i];

  map<ll,ll> mp;
  fr(i,0,n) mp[a[i]]++;

  for(auto x:mp) p.PB(MP(x.fi,x.se));

  sort(p.begin(),p.end(),cmp);

  //fr(i,0,SZ(p)) cout<<p[i].fi<<" "<<p[i].se<<"\n"; cout<<"\n";

  ll l=1,r=n/k,m;

  ll ans=0;

  while(l<=r){
    m=(l+r)/2;
    if(F(m)){
      ans=max(ans,m);
      l=m+1;
    }
    else r=m-1;
  }

  bool f=F(ans);
  fr(i,0,SZ(v)) cout<<v[i]<<" ";

  return 0;
}
