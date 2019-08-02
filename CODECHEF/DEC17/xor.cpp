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
#define N 100001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)

ll n,q;

struct Tree{
  ll v;
  set<ll> s;
};

struct Tree tree[N];

void build(ll a[]){
  fr(i,n,2*n){
    tree[i].v=a[i-n];
    tree[i].s.insert(a[i-n]);
  }

  for(ll i=n-1;i>=1;i--){
    tree[i].v=tree[i*2].v^tree[(i*2)+1].v;

    tree[i].s.insert(tree[i*2].v);
    tree[i].s.insert(tree[i*2].v^tree[(i*2)+1].v);
  }
}

void update(ll pos,ll val){
  pos+=n;
  ll v=tree[pos].v;
  tree[pos].s.erase(v);
  tree[pos].v=val;
  tree[pos].s.insert(val);

  while(pos>1){
    pos=pos/2;
    tree[pos].s.erase(v^tree[pos*2].v);
    tree[pos].s.erase(v^tree[pos*2+1].v);
    tree[pos].s.insert(tree[pos*2].v);
    tree[pos].s.insert(tree[pos*2].v^tree[(pos*2)+1].v);
    tree[pos].v=tree[pos*2].v^tree[(pos*2)+1].v;
  }
}

ll query(ll left,ll right,ll k){
  ll ans=0;
  left+=n;
  right+=n;

  while(left<right){
    if(left%2==1){
      //cout<<left<<" ";
      if(tree[left].s.find(k)!=tree[left].s.end()) ans++;
      left++;
    }
    if(right%2==1){
      right--;
      //cout<<right<<" ";
      if(tree[right].s.find(k)!=tree[right].s.end()) ans++;
    }
    left=left/2;
    right=right/2;
  }

  return ans;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n>>q;

  ll a[n];
  fr(i,0,n) cin>>a[i];

  build(a);

  ll ty,i,x,k;
  fr(j,0,q){
    cin>>ty;
    if(ty==1){
      cin>>i>>x;
      a[i-1]=x;
      update(i-1,x);
    }
    else{
      cin>>i>>k;
      cout<<query(0,i,k)<<"\n";
    }
  }

  /*
  ll z=0;
  fr(i,0,n){
    z=z^a[i];
    cout<<z<<" ";
  }
  */

  return 0;
}
