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

bool check(ll x,ll y,ll z){
  if(x+y>z && x+z>y && y+z>x) return true;
  else return false;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n,q;
  cin>>n>>q;
  ll a[n+1];
  fr(i,1,n+1) cin>>a[i];

  ll t,l,r;
  fr(i,0,q){
    cin>>t>>l>>r;
    if(t==1) a[l]=r;
    else{
      ll b[r-l+1];
      fr(i,l,r+1) b[i-l]=a[i];
      sort(b,b+(r-l+1),greater<ll>());
      ll f=0;
      fr(i,0,(r-l+1)-3+1){
        if(check(b[i],b[i+1],b[i+2])){
          cout<<b[i]+b[i+1]+b[i+2];
          f=1;
          break;
        }
      }
      if(!f) cout<<0;
      cout<<"\n";
    }
  }

  return 0;
}
