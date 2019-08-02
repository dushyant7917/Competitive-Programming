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
#define N 1001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll n=0;

struct Node{
  ll l,r;
  bool visited;
};

struct Node node[N];

void dfs(ll v){
  node[v].visited=true;

  fr(i,1,n+1){
    if(!node[i].visited){
      if(node[i].l<node[v].l && node[v].l<node[i].r) dfs(i);
      else if(node[i].l<node[v].r && node[v].r<node[i].r) dfs(i);
      else {}
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll q,t,a,b;
  cin>>q;
  fr(i,0,q){
    cin>>t>>a>>b;
    if(t==1){
      n++;
      node[n].l=a;
      node[n].r=b;
    }
    else{
      fr(i,1,n+1) node[i].visited=false;
      dfs(a);
      if(node[b].visited) cout<<"YES\n";
      else cout<<"NO\n";
    }
  }

  return 0;
}
