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

  ll n,m;
  cin>>n>>m;

  vector<map<ll,ll> > mp;
  map<ll,ll>::iterator itr;
  mp.resize(n+1);

  mp[2][4]=1;
  mp[2][5]=0;
  itr=mp[2].lower_bound(3);
  cout<<itr->first<<" "<<itr->second;

  ll val,ans=0;

  ll u,v,w;
  fr(i,0,m){
    cin>>u>>v>>w;

    if(i){
      itr=mp[u].lower_bound(w);
      if(itr->first==w){
        itr--;
        val=itr->second;
      }
      else if(itr->first<w) val=itr->second;
      else val=0;
      ans=max(ans,val);
    }

    itr=mp[v].lower_bound(w+1);
    if(itr->first==w+1){
      itr--;
      val=itr->second;
    }
    else if(itr->first<w+1) val=itr->second;
    else val=0;

    ans=max(ans,val);
  }

  //cout<<ans;

  return 0;
}
