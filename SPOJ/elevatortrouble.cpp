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
#define N 1000001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll n,src,dst,up,down,ans;
bool visited[N];

void bfs(){
  queue<pii> q;
  q.push(pii(src,0));

  ll node,d;
  while(SZ(q)){
    node=q.front().fi;
    d=q.front().se;
    q.pop();

    if(visited[node]) continue;

    visited[node]=true;

    if(node==dst){
      ans=d;
      break;
    }

    if(node+up<=n && !visited[node+up]) q.push(pii(node+up,d+1));
    if(node-down>=1 && !visited[node-down]) q.push(pii(node-down,d+1));
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n>>src>>dst>>up>>down;

  fr(i,1,n+1) visited[i]=false;
  bfs();
  if(visited[dst]) cout<<ans;
  else cout<<"use the stairs";

  return 0;
}
