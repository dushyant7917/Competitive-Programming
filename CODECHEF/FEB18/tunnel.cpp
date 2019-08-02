#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define rf(x,a,b) for(ll x=a;x>b;x--)
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

  ll n,c,d,s;
  ll ft,st,lt,diff;
  while(t--){
    cin>>n;
    ll p[n];
    fr(i,0,n) cin>>p[i];
    cin>>c>>d>>s;

    //diff=st-ft;
    diff=0;
    fr(i,0,n) diff=max(diff,p[i]);
    lt=ft+((c-1)*diff);
    cout<<fixed<<setprecision(9)<<(dbl)(lt-ft)<<"\n";
  }

  return 0;
}
