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
#define MAX(a,b,c,d,e,f) max(a,max(b,max(c,max(d,max(e,f)))))
#define MIN(a,b,c) min(min(a,b),c)

ll n;
ll a[N];

struct Tree{
  ll m1;
  ll m2;
};

struct Tree tree[2*N];

void build(ll a[]){
  fr(i,n,2*n){
    tree[i].m1=a[i-n];
    tree[i].m2=0;
  }

  for(ll i=n-1;i>=1;i--){
    tree[i].m1=max(tree[i*2].m1,tree[(i*2)+1].m1);
    tree[i].m2=min(max(tree[i*2].m1,tree[(i*2)+1].m2),max(tree[i*2].m2,tree[(i*2)+1].m1));
  }
}

void update(ll pos,ll val){
  a[pos]=val;
  pos+=n;
  tree[pos].m1=val;

  while(pos>1){
    pos=pos/2;
    tree[pos].m1=max(tree[pos*2].m1,tree[(pos*2)+1].m1);
    tree[pos].m2=min(max(tree[pos*2].m1,tree[(pos*2)+1].m2),max(tree[pos*2].m2,tree[(pos*2)+1].m1));
  }
}

ll query(ll left,ll right){
  struct Tree t;
  t.m1=0;
  t.m2=0;
  left+=n;
  right+=n;

  while(left<right){
    if(left%2==1){
      t.m2=min(max(tree[left].m1,t.m2),max(tree[left].m2,t.m1));
      t.m1=max(tree[left].m1,t.m1);
      left++;
    }
    if(right%2==1){
      right--;
      t.m2=min(max(tree[right].m1,t.m2),max(tree[right].m2,t.m1));
      t.m1=max(tree[right].m1,t.m1);
    }
    left=left/2;
    right=right/2;
  }

  return (t.m1+t.m2);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n;
  fr(i,0,n) cin>>a[i];

  a[N-1]=0;
  build(a);

  ll q;
  cin>>q;

  char ty;
  ll x,y;
  fr(i,0,q){
    cin>>ty;
    if(ty=='U'){
      cin>>x>>y;
      update(x-1,y);
    }
    else{
      cin>>x>>y;
      cout<<query(x-1,y)<<"\n";
    }
  }

  return 0;
}
