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
#define INF 2e16
#define N 100001
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
  ll a[n],b[n];

  fr(i,0,n){
    cin>>a[i];
    b[i]=i+((a[i]/n)*n);
    if(b[i]<a[i]) b[i]+=n;
  }

  ll mn=INF;
  ll ans;
  fr(i,0,n){
    if(b[i]<mn){
      mn=b[i];
      ans=i+1;
    }
  }
  cout<<ans;

  return 0;
}
