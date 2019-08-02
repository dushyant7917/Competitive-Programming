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

  map<ll,pii> mp;
  ll ans[n+1]={0};
  ll l,r;

  fr(i,0,n){
    cin>>l>>r;
    mp[l].fi++;
    mp[r].se++;
  }

  ll cur,prv,cnt=0,opened,closed;

  for(auto x:mp){
    opened=x.se.fi;
    closed=x.se.se;
    cur=x.fi;

    if(prv==-1){
      cnt+=opened;
      ans[cnt]++;
      cnt+=closed;
      prv=cur;
    }
    else{
      ans[cnt]+=cur-prv-1;
      cnt+=opened;
      ans[cnt]++;
      cnt-=closed;
      prv=cur;
    }
  }

  fr(i,1,n+1) cout<<ans[i]<<" ";

  return 0;
}
