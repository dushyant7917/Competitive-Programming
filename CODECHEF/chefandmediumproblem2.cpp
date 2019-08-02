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

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n,m;
  cin>>n;

  ll a[n+1];
  ll t,l,r,p,d;
  set<ll> s[6];
  set<ll>::iterator itr;

  fr(i,1,n+1){
    cin>>a[i];
    if(a[i]%2==0) s[2].insert(i);
    if(a[i]%3==0) s[3].insert(i);
    if(a[i]%5==0) s[5].insert(i);
  }

  cin>>m;
  vector<ll> e;

  fr(i,0,m){
    cin>>t;
    if(t==1){
      cin>>l>>r>>p;
      itr=s[p].lower_bound(l);
      while(itr!=s[p].end() && (*itr>=l) && (*itr)<=r){
        a[(*itr)]/=p;
        if(a[(*itr)]%p) e.PB(*itr);
        itr++;
      }
      fr(i,0,SZ(e)) s[p].erase(e[i]);
      e.clear();
    }
    else{
      cin>>l>>d;
      if(a[l]%2==0) s[2].erase(l);
      if(a[l]%3==0) s[3].erase(l);
      if(a[l]%5==0) s[5].erase(l);

      if(d%2==0) s[2].insert(l);
      if(d%3==0) s[3].insert(l);
      if(d%5==0) s[5].insert(l);

      a[l]=d;
    }
  }

  fr(i,1,n+1) cout<<a[i]<<" ";

  return 0;
}
