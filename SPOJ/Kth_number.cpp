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
#define N 100005
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll n,q;
ll a[N];

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

  if(left<=start && end<=right) return upper_bound(tree[node].begin(),tree[node].end(),val)-tree[node].begin();

  ll mid=(start+end)/2;
  ll t1=query(node*2,start,mid,left,right,val);
  ll t2=query(node*2+1,mid+1,end,left,right,val);
  return (t1+t2);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n>>q;

  vector<ll> v;

  fr(i,0,n){
    cin>>a[i];
    v.PB(a[i]);
  }

  sort(v.begin(),v.end());

  fr(i,0,n) a[i]=lower_bound(v.begin(),v.end(),a[i])-v.begin();

  build(1,0,n-1);

  ll l,r,m,k,x,start,end,mid,ans;
  fr(i,0,q){
    cin>>l>>r>>k;
    l--;
    r--;
    start=0;
    end=n-1;
    while(start<=end){
      mid=(start+end)/2;
      x=query(1,0,n-1,l,r,mid);
      if(x>=k){
        ans=mid;
        end=mid-1;
      }
      else start=mid+1;
    }
    cout<<v[ans]<<"\n";
  }

  return 0;
}
