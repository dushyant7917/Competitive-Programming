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
#define N 200002
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll n,a[N];
vector<ll> tree[4*N];

void build(ll node,ll start,ll end){
  if(start==end) tree[node].PB(a[start]);
  else{
    ll mid=(start+end)/2;
    build(node*2,start,mid);
    build(node*2+1,mid+1,end);
    merge(tree[node*2].begin(),tree[node*2].end(),tree[node*2+1].begin(),tree[node*2+1].end(),back_inserter(tree[node]));
  }
}

ll query(ll node,ll start,ll end,ll left,ll right,ll val){
  if(right<start || end<left) return 0;

  if(left<=start && end<=right){
    ll ind=lower_bound(tree[node].begin(),tree[node].end(),val)-tree[node].begin();
    return SZ(tree[node])-ind;
  }

  ll mid=(start+end)/2;
  return query(node*2,start,mid,left,right,val)+query(node*2+1,mid+1,end,left,right,val);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n;
  fr(i,0,n){
    cin>>a[i];
    a[i]=min(n,a[i]);
  }

  build(1,0,n-1);

  ll ans=0;
  fr(i,0,n-1) if(i+1<=a[i]) ans+=query(1,0,n-1,i+1,a[i]-1,i+1);

  cout<<ans;

  return 0;
}
