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

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll t;
  cin>>t;

  ll n;
  while(t--){
    cin>>n;
    ll a[n+1],b[n+1];
    fr(i,1,n+1) cin>>a[i];
    fr(i,1,n+1) cin>>b[i];

    bool flag=true;
    ll cnt;

    for(ll i=1;i<=n-2;i++){
      if(a[i]==b[i]) continue;
      else if(a[i]>b[i]){
        flag=false;
        break;
      }
      else{
        cnt=(b[i]-a[i])/1;
        a[i]+=cnt*1;
        a[i+1]+=cnt*2;
        a[i+2]+=cnt*3;
      }
    }

    fr(i,1,n+1) if(a[i]!=b[i]) flag=false;

    if(flag) cout<<"TAK\n";
    else cout<<"NIE\n";
  }

  return 0;
}
