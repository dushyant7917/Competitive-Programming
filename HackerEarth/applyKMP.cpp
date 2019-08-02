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

  string p,t;
  cin>>p>>t;

  ll ans=0;
  bool flag=true;
  if(p[0]!=t[0]) flag=false;
  if(p[SZ(p)-1]!=t[SZ(p)-1]) flag=false;
  fr(i,1,SZ(p)-1){
    if(s[i]!=t[i]) flag=false;
  }

  return 0;
}
