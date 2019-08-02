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

  ll n,m,k,p,cnt;
  while(t--){
    cin>>n>>m>>k;
    ll a[n];
    fr(i,0,n) cin>>a[i];

    cnt=0;
    fr(i,0,n){
      p=1;
      fr(j,i,n){
        p*=a[j];
        if(p%m==k) cnt++;
      }
    }
    cout<<cnt<<"\n";
  }

  return 0;
}
