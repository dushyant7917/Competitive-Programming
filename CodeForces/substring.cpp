#include<bits/stdc++.h>

using namespace std;

typedef int ll;
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
#define N 300002
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll n,m;
ll in_deg[N];
vector<ll> adj[N];
bool visited[N];
ll dp[N][26];
char s[N];

ll topological_sort(){
  queue<ll> q;


  fr(i,1,n+1) if(!in_deg[i]) q.push(i);

  ll v,u,cnt=0;
  while(SZ(q)){
    v=q.front();
    q.pop();
    visited[v]=true;
    cnt++;
    fr(i,0,SZ(adj[v])){
      u=adj[v][i];
      if(!visited[u]){
        fr(j,0,26){
          dp[u][j]=max(dp[u][j],dp[v][j]+((s[u]-'a'==j)?1:0));
        }
        in_deg[u]--;
        if(!in_deg[u]) q.push(u);
      }
    }
  }

  if(cnt==n){
    ll ans=0;
    fr(i,1,n+1){
      fr(j,0,26){
        ans=max(ans,dp[i][j]);
      }
    }
    return ans;
  }
  else return -1;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n>>m;

  MS(visited,false);
  MS(dp,0);

  fr(i,1,n+1){
    cin>>s[i];
    dp[i][s[i]-'a']=1;
  }

  ll u,v;
  fr(i,0,m){
    cin>>u>>v;
    adj[u].PB(v);
    in_deg[v]++;
  }

  cout<<topological_sort();

  return 0;
}
