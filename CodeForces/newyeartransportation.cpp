#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define rf(x,a,b) for(ll x=a;x>b;x--)
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

ll n,t;
vector<ll> graph[N];
bool visited[N];
bool flag=false;

void dfs(ll node){
  if(node==t){
    flag=true;
    return;
  }

  visited[node]=true;

  fr(i,0,SZ(graph[node])){
    if(!visited[graph[node][i]]){
      dfs(graph[node][i]);
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n>>t;
  ll x;
  fr(i,1,n){
    cin>>x;
    graph[i].PB(i+x);
  }

  dfs(1);
  if(flag) cout<<"YES";
  else cout<<"NO";

  return 0;
}
