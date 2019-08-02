#include<bits/stdc++.h>

using namespace std;

typedef int ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN
#define INF 2e9
#define N 100010
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)

ll n;

struct ST{
  ll sum; // sum
  ll ms;  // max_sum
  ll mps; // max_prefix_sum
  ll mss; // max_suffix_sum
};

struct ST tree[N];

void build(ll a[]){
  fr(i,n,2*n){
    tree[i].sum=a[i-n];
    tree[i].ms=a[i-n];
    tree[i].mps=a[i-n];
    tree[i].mss=a[i-n];
  }

  for(ll i=n-1;i>=1;i--){
    tree[i].sum=(tree[i*2].sum+tree[(i*2)+1].sum);
    tree[i].mps=max(tree[i*2].mps,tree[i*2].sum+tree[(i*2)+1].mps);
    tree[i].mss=max(tree[(i*2)+1].mss,tree[(i*2)+1].sum+tree[i*2].mss);
    tree[i].ms=max(tree[i].mps,max(tree[i].mss,max(tree[i*2].ms,max(tree[(i*2)+1].ms,tree[i*2].mss+tree[(i*2)+1].mps))));
  }
}

ll combine(struct ST left,struct ST right){
  struct ST ans;
  ans.ms=max(max(left.ms,right.ms),left.mss+right.mps);
  //ans.mps=max(left.mps,left.sum+right.mps);
  //ans.mss=max(left.mss+right.sum,right.mss);
  //ans.sum=left.sum+right.sum;

  return ans.ms;
}

void update(ll pos,ll val){
  pos+=n;
  tree[pos].sum=val;
  tree[pos].ms=val;
  tree[pos].mps=val;
  tree[pos].mss=val;

  while(pos>1){
    pos=pos/2;
    tree[pos].sum=(tree[pos*2].sum+tree[(pos*2)+1].sum);
    tree[pos].mps=max(tree[pos*2].mps,tree[pos*2].sum+tree[(pos*2)+1].mps);
    tree[pos].mss=max(tree[(pos*2)+1].mss,tree[(pos*2)+1].sum+tree[pos*2].mss);
    tree[pos].ms=max(tree[pos].mps,max(tree[pos].mss,max(tree[pos*2].ms,max(tree[(pos*2)+1].ms,tree[pos*2].mss+tree[(pos*2)+1].mps))));
  }
}

ll query(ll left,ll right){
  struct ST lt,rt;
  lt.sum=rt.sum=0;
  lt.ms=lt.mps=lt.mss=-INF;
  rt.ms=rt.mps=rt.mss=-INF;

  left+=n;
  right+=n;

  while(left<right){
    if(left&1){ // (left%2==1)
      lt.ms=max(lt.ms,max(tree[left].ms,lt.mss+tree[left].mps));
      lt.mps=max(lt.mps,lt.sum+tree[left].mps);
      lt.mss=max(lt.mss+tree[left].sum,tree[left].mss);
      lt.sum+=tree[left].sum;

      left++;
    }
    if(right&1){ // (right%2==1)
      right--;

      rt.ms=max(rt.ms,max(tree[right].ms,rt.mps+tree[right].mss));
      rt.mps=max(rt.mps+tree[right].sum,tree[right].mps);
      rt.mss=max(rt.sum+tree[right].mss,tree[right].mss);
      rt.sum+=tree[right].sum;
    }
    left=left/2;
    right=right/2;
  }

  return combine(lt,rt);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n;

  ll a[n];
  fr(i,0,n) cin>>a[i];

  build(a);

  ll m;
  cin>>m;

  ll ty,x,y;
  fr(i,0,m){
    cin>>ty>>x>>y;
    if(ty==1) cout<<query(x-1,y)<<"\n";
    else update(x-1,y);
  }

  return 0;
}
