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
#define N 1000001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)

ll n,k;

struct Tree{
  ll min_val;
  ll max_val;
  ll or_val;
  ll and_val;
  ll cost;
  ll m;
};

struct Tree tree[2*N];

void build(ll a[]){
  fr(i,n,2*n){
    tree[i].min_val=a[i-n];
    tree[i].max_val=a[i-n];
    tree[i].or_val=a[i-n];
    tree[i].and_val=a[i-n];
    tree[i].cost=0;
    tree[i].m=-1;
  }

  for(ll i=n-1;i>=1;i--){
    tree[i].min_val=min(tree[i*2].min_val,tree[(i*2)+1].min_val);
    tree[i].max_val=max(tree[i*2].max_val,tree[(i*2)+1].max_val);
    tree[i].or_val=(tree[i*2].or_val|tree[(i*2)+1].or_val);
    tree[i].and_val=(tree[i*2].and_val&tree[(i*2)+1].and_val);
    tree[i].cost=(tree[i].or_val-tree[i].and_val)-(tree[i].max_val-tree[i].min_val);
    tree[i].m=max(tree[i*2].m,tree[(i*2)+1].m);
  }
}

ll query(ll left,ll right){
  ll min_val=INF;
  ll max_val=-INF;
  ll or_val=0;
  ll and_val;

  left+=n;
  right+=n;

  ll ft=1;

  while(left<right){
    if(left%2==1){
      min_val=min(min_val,tree[left].min_val);
      max_val=max(max_val,tree[left].max_val);
      or_val=(or_val|tree[left].or_val);
      if(ft){
        and_val=tree[left].and_val;
        ft=0;
      }
      else and_val=(and_val&tree[left].and_val);
      left++;
    }
    if(right%2==1){
      right--;
      min_val=min(min_val,tree[right].min_val);
      max_val=max(max_val,tree[right].max_val);
      or_val=(or_val|tree[right].or_val);
      if(ft){
        and_val=tree[right].and_val;
        ft=0;
      }
      else and_val=(and_val&tree[right].and_val);
    }

    left=left/2;
    right=right/2;
  }

  return (or_val-and_val)-(max_val-min_val);
}

void fn(ll i,ll v){
  if(i>=n){
    tree[i].m=max(v,tree[i].m);
    return;
  }
  else{
    tree[i].m=max(v,tree[i].m);
    fn(i*2,v);
    fn(i*2+1,v);
  }
}

void update(ll l,ll r,ll val){
  for (l += n, r += n; l < r; l >>= 1, r >>= 1){
    if (l&1){
      tree[l].m = max(val,tree[l].m);
      if(l<n){
        fn(l,val);
      }
      l++;
    }
    if (r&1){
      --r;
      tree[r].m = max(val,tree[r].m);
      if(r<n){
        fn(r,val);
      }
    }
  }
}



int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n>>k;

  ll a[n],ans[n];
  fr(i,0,n) cin>>a[i];

  build(a);

  fr(i,0,n) ans[i]=-1;

  ll val;
  fr(i,0,n){
    fr(j,i,n){
      val=query(i,j+1);
      if(val>=k){
        update(i,j+1,j-i+1);
      }
    }
  }

  fr(i,n,2*n) cout<<tree[i].m<<"\n";

  return 0;
}
