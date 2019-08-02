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

  ll l,r,a;
  cin>>l>>r>>a;

  ll la=0,ra=0,d;
  if(l==r) cout<<2*(l+a/2);
  else{
    if(l<=r){
      l+=a;
      la+=a;
      if(l<=r){
        cout<<2*l;
        return 0;
      }
      else{
        d=l-r;
        if(la>=d/2){
          r+=d/2;
          l-=d/2;
        }
        cout<<2*min(l,r);
      }
    }
    else{
      r+=a;
      ra+=a;
      if(r<=l){
        cout<<2*r;
        return 0;
      }
      else{
        d=r-l;
        if(ra>=d/2){
          l+=d/2;
          r-=d/2;
        }
        cout<<2*min(l,r);
      }
    }

  }

  return 0;
}
