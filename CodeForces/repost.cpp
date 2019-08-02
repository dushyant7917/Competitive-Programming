#include<bits/stdc++.h>

using namespace std;

typedef int ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN
#define INF 2e9
#define N 201
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

vector<ll> graph[N];
ll visited[2*N];

ll dfs(ll node){
  ll ans=0;
  visited[node]=1;

  fr(i,0,SZ(graph[node])){
    if(!visited[graph[node][i]]){
      ans=max(ans,dfs(graph[node][i]));
    }
  }

  return ans+1;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n;
  cin>>n;

  string a,b,e;
  ll u,v,c=1;
  map<string,ll> mp;

  fr(i,0,n){
    cin>>a>>e>>b;
    transform(a.begin(),a.end(),a.begin(),::tolower);
    transform(b.begin(),b.end(),b.begin(),::tolower);
    if(!mp[b]) mp[b]=c++;
    if(!mp[a]) mp[a]=c++;
    u=mp[a];
    v=mp[b];
    graph[v].PB(u);
  }

  cout<<dfs(1);

  return 0;
}
