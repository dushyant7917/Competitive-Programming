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
  ll t;
  cin>>t;

  bool x,y;
  ll n;
  while(t--){
    cin>>n;
    ll a[n],b[n];
    fr(i,0,n) cin>>a[i];
    fr(i,0,n) cin>>b[i];

    x=y=true;
    fr(i,0,n){
      if(a[i]>b[i]) x=false;
      if(a[n-i-1]>b[i]) y=false;
    }

    if(x && y) cout<<"both\n";
    else if(x && !y) cout<<"front\n";
    else if(!x && y) cout<<"back\n";
    else cout<<"none\n";
  }

  return 0;
}
