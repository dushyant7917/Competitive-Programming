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

  ll n,m;
  cin>>n>>m;

  if(m<n-1){
    cout<<"Impossible";
    return 0;
  }

  vector<pii> v;
  ll i=n,j,cnt=0;

  fr(i,1,n+1){
    if(cnt==m) break;
    fr(j,i+1,n+1){
      if(cnt==m) break;
      if(__gcd(i,j)==1){
        v.PB(pii(i,j));
        cnt++;
      }
    }
  }

  if(cnt==m){
    cout<<"Possible\n";
    fr(i,0,SZ(v)) cout<<v[i].fi<<" "<<v[i].se<<"\n";
  }
  else cout<<"Impossible";

  return 0;
}
