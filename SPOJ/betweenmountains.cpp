#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN
#define INF 2e9
#define N 100001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  ll n1,n2;
  while(t--){
    cin>>n1;
    ll a[n1];
    fr(i,0,n1) cin>>a[i];
    cin>>n2;
    ll b[n2];
    fr(i,0,n2) cin>>b[i];

    sort(a,a+n1);
    sort(b,b+n2);

    ll x;
    ll ans=INF;
    fr(i,0,n1){
      if(binary_search(b,b+n2,a[i])){
        ans=0;
        break;
      }
      else{
        x=lower_bound(b,b+n2,a[i])-b;
        if(x==n2) ans=min(ans,abs(a[i]-b[n2-1]));
        else ans=min(ans,abs(a[i]-b[x]));
      }
    }

    cout<<ans<<"\n";
  }

  return 0;
}
