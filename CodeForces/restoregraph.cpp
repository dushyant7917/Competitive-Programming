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

struct Node{
  ll val;
  ll dist;
};

bool cmp(Node n1,Node n2){
  return n1.dist<n2.dist;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n,k;
  cin>>n>>k;

  Node node[n+1];
  fr(i,1,n+1){
    node[i].val=i;
    cin>>node[i].dist;
  }

  sort(node+1,node+1+n,cmp);
  ll cnt=0;
  fr(i,1,n+1) if(!node[i].dist) cnt++;
  if(cnt!=1){
    cout<<-1;
    return 0;
  }

  vector<ll> adj[n+1];
  ll i=1;
  fr(j,2,n+1){
    if(node[j].dist-node[i].dist==1){
      adj[node[i].val].PB(node[j].val);
    }
    else{
      i++;

    }
  }

  return 0;
}
