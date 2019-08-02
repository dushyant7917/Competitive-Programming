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

  string s;
  cin>>s;

  bool visited[SZ(s)];
  MS(visited,false);

  vector<ll> f[10];
  fr(i,0,SZ(s)) f[s[i]-'0'].PB(i);

  queue<pii> q;
  q.push(pii(0,0));
  ll ind,d,ans;

  while(SZ(q)){
    ind=q.front().fi;
    d=q.front().se;
    q.pop();
    visited[ind]=true;

    if(ind==SZ(s)-1){
      ans=d;
      break;
    }

    fr(i,0,SZ(f[s[ind]-'0'])){
      if(visited[f[s[ind]-'0'][i]]) continue;
      q.push(pii(f[s[ind]-'0'][i],d+1));
    }
    f[s[ind]-'0'].clear();

    if(ind-1>=0 && !visited[ind-1]) q.push(pii(ind-1,d+1));

    if(ind+1<SZ(s) && !visited[ind+1]) q.push(pii(ind+1,d+1));
  }

  cout<<ans;

  return 0;
}
