#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define rf(x,a,b) for(ll x=a;x>b;x--)
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

ll n,m,c;
ll color[N];
set<ll> s[N];
vector<ll> v;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n>>m;
  fr(i,1,n+1){
    cin>>c;
    color[i]=c;
    v.PB(c);
  }

  ll x,y;
  fr(i,0,m){
    cin>>x>>y;
    if(color[x]!=color[y]){
      s[color[x]].insert(color[y]);
      s[color[y]].insert(color[x]);
    }
  }

  sort(v.begin(),v.end());

  ll ms=s[v[0]].size(),ans=v[0];
  fr(i,1,v.size()){
    if(s[v[i]].size()>ms){
      ans=v[i];
      ms=s[v[i]].size();
    }
  }

  cout<<ans;

  return 0;
}
