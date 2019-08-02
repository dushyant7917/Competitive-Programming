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
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n;
  cin>>n;
  string a,b;
  cin>>a>>b;

  ll ans=0;

  fr(i,0,n/2){
    if(a[i]==a[n-i-1] && b[i]==b[n-i-1]) continue;
    else if(a[i]==b[i] && a[n-i-1]==b[n-i-1]) continue;
    else if(a[i]==b[n-i-1] && a[n-i-1]==b[i]) continue;
    else if(a[i]==b[i] || a[i]==b[n-i-1] || b[i]==a[n-i-1] || b[i]==b[n-i-1] || a[n-i-1]==b[n-i-1]) ans+=1;
    else ans+=2;
  }

  if(n&1 && a[n/2]!=b[n/2]) ans++;

  cout<<ans;

  return 0;
}
