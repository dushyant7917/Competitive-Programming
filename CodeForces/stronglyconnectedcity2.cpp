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
#define N 1001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll n,m;
string h,v;
vector<ll> adj1[N],adj2[N];
bool visited[N];

void dfs(ll v,ll t){
  visited[v]=true;

  ll u;
  if(t==1){
    fr(i,0,SZ(adj1[v])){
      u=adj1[v][i];
      if(!visited[u]) dfs(u,t);
    }
  }
  if(t==2){
    fr(i,0,SZ(adj2[v])){
      u=adj2[v][i];
      if(!visited[u]) dfs(u,t);
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n>>m;
  cin>>h>>v;

  fr(i,0,n){
    fr(j,0,m){
      if(h[i]=='>' && j+1<=m){
        adj1[i*m+j].PB(i*m+(j+1));
        adj2[i*m+(j+1)].PB(i*m+j);
      }
      if(h[i]=='<' && j-1>=0){
        adj1[i*m+j].PB(i*m+(j-1));
        adj2[i*m+(j-1)].PB(i*m+j);
      }
      if(v[j]=='^' && i-1>=0){
        adj1[i*m+j].PB((i-1)*m+j);
        adj2[(i-1)*m+j].PB(i*m+j);
      }
      if(v[j]=='v' && i+1<=n){
        adj1[i*m+j].PB((i+1)*m+j);
        adj2[(i+1)*m+j].PB(i*m+j);
      }
    }
  }

  bool flag=true;

  MS(visited,false);
  dfs(0,1);
  fr(i,0,n){
    fr(j,0,m){
      if(!visited[i*m+j]) flag=false;
    }
  }

  if(flag){
    MS(visited,false);
    dfs(0,2);
    fr(i,0,n){
      fr(j,0,m){
        if(!visited[i*m+j]) flag=false;
      }
    }
  }

  if(flag) cout<<"YES";
  else cout<<"NO";

  return 0;
}
