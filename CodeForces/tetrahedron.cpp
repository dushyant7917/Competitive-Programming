#include<bits/stdc++.h>

using namespace std;

typedef int ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN
#define INF 2e9
#define N 10000001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define sz(s) s.size()

ll a[N],b[N],c[N],d[N];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n;
  cin>>n;

  a[0]=b[0]=c[0];
  d[0]=1;
  fr(i,1,n+1){
    d[i]=((a[i-1]+b[i-1])%mod+c[i-1])%mod;
    a[i]=((d[i-1]+b[i-1])%mod+c[i-1])%mod;
    b[i]=((a[i-1]+d[i-1])%mod+c[i-1])%mod;
    c[i]=((a[i-1]+b[i-1])%mod+d[i-1])%mod;
  }

  cout<<d[n];

  return 0;
}
