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
#define N 1001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n;
  cin>>n;
  ll a[2*n];
  fr(i,0,2*n) cin>>a[i];

  ll ans=0,cnt,ind;

  for(ll i=0;i+1<=2*n-1;i+=2){
    if(a[i]==a[i+1]) continue;

    fr(j,i+1,2*n){
      if(a[j]==a[i]){
        ind=j;
        break;
      }
    }

    cnt=0;

    rf(j,ind,i+2){
      swap(a[j],a[j-1]);
      cnt++;
    }

    ans+=cnt;
  }

  cout<<ans;

  return 0;
}
