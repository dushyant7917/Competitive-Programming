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

bool BITSET(ll n,ll i){
  if(n&(1<<i)) return true;
  else return false;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll x,d;
  cin>>x>>d;

  ll num=1,cnt=0;
  vector<ll> ans;

  rf(i,31,1){
    if(BITSET(x,i)){
      fr(j,0,i) ans.PB(num);
      num+=d;
      cnt++;
    }
  }

  while(cnt>0){
    ans.PB(num);
    num+=d;
    cnt--;
  }

  if(x&1) ans.PB(num);

  cout<<SZ(ans)<<"\n";
  fr(i,0,SZ(ans)) cout<<ans[i]<<" ";

  return 0;
}
