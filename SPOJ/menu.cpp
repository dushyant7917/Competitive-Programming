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



ll F(ll day,ll dish,ll rep,ll amt,dbl benifit){
  if(amt>m) return INF;
  if(amt<=m && day==k) return benifit;

  return max();
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  while(1){
    cin>>k>>n>>m;

    if(!k && !n && !m) break;

    dbl ans=0.0;
    fr(i,0,n) ans=max(ans,F(0,));
    cout<<ans<<"\n";
  }

  return 0;
}
