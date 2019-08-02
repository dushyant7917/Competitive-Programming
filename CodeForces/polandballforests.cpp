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
#define N 10001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll n;

ll component[N];

void init(){
  fr(i,1,n+1) component[i]=i;
}

ll find_component(ll node){
  while(component[node]!=node){
    component[node]=component[component[node]];
    node=component[node];
  }
  return node;
}

void union_components(ll node1,ll node2){
  ll x=find_component(node1);
  ll y=find_component(node2);
  component[x]=component[y];
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n;
  ll a[n];
  fr(i,1,n+1) cin>>a[i];

  init();

  ll cmp;
  fr(i,1,n+1){
    if(find_component(i)!=find_component(a[i])){
      union_components(i,a[i]);
    }
  }

  set<ll> ans;
  fr(i,1,n+1){
    ans.insert(find_component(i));
  }
  cout<<SZ(ans);

  return 0;
}
