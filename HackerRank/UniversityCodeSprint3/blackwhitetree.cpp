#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN
#define INF 2e9

ll n,m;
bool visited[100001];
ll color[100001];
ll nw=0,nb=0;
vector<ll> adj[100001];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin>>n;
  fr(i,1,n+1) cin>>color[i];

  fr(i,0,n-1){
    cin>>x>>y;
    adj[x].PB(y);
    adj[y].PB(x);
  }

  return 0;
}
